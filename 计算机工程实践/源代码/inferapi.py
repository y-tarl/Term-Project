import cv2
import numpy as np
import torch
from models.experimental import attempt_load
from utils.datasets import LoadImages, LoadStreams
from utils.general import apply_classifier, check_img_size, check_imshow, check_requirements, check_suffix, colorstr, \
    increment_path, non_max_suppression, print_args, save_one_box, scale_coords, set_logging, \
    strip_optimizer, xyxy2xywh
from utils.plots import Annotator, colors
from utils.torch_utils import load_classifier, select_device, time_sync


class ExternalInference:
    def __init__(self, weights='best.pt', img_size=640, device=''):
        self.device = select_device(device)  # 选择设备（CPU或GPU）
        self.model = attempt_load(weights, map_location=self.device)  # 加载模型权重
        self.img_size = check_img_size(img_size, s=self.model.stride.max())  # 检查图像大小

        if self.device.type != 'cpu':  # 如果使用GPU，则将模型转换为半精度FP16
            self.model.half()

        # 模型预热（在GPU上运行一次空的输入）
        if self.device.type != 'cpu':
            self.model(
                torch.zeros(1, 3, self.img_size, self.img_size).to(self.device).type_as(next(self.model.parameters())))

    def infer(self, img0):
        # 调整图像大小并添加边框
        img = letterbox(img0, self.img_size)[0]
        img = img[:, :, ::-1].transpose(2, 0, 1)  # BGR转RGB，并调整维度顺序为3x416x416
        img = np.ascontiguousarray(img)  # 转换为连续数组

        img = torch.from_numpy(img).to(self.device)  # 将图像转换为张量并移动到设备上
        img = img.half() if self.device.type != 'cpu' else img.float()  # 根据设备类型转换数据类型
        img /= 255.0  # 将像素值归一化到0-1之间
        if img.ndimension() == 3:  # 如果是3维张量，则增加一个批次维度
            img = img.unsqueeze(0)

        pred = self.model(img, augment=False)[0]  # 进行前向传播并获取预测结果

        # 执行非最大抑制，去除多余的检测框
        pred = non_max_suppression(pred, 0.25, 0.45, classes=None, agnostic=False)

        detected_info = []
        for i, det in enumerate(pred):  # 遍历每个检测结果
            if len(det):
                # 调整检测框的坐标，使其适应原始图像的大小
                det[:, :4] = scale_coords(img.shape[2:], det[:, :4], img0.shape).round()
                for *xyxy, conf, cls in reversed(det):
                    detected_info.append({
                        'bbox': [int(coord) for coord in xyxy],  # 检测框坐标
                        'confidence': float(conf),  # 置信度
                        'class': self.model.names[int(cls)]  # 检测的类别
                    })

        return detected_info


def letterbox(img, new_shape=640, color=(114, 114, 114), auto=True, scaleFill=False, scaleup=True):
    shape = img.shape[:2]  # 当前图像的高和宽
    if isinstance(new_shape, int):
        new_shape = (new_shape, new_shape)

    r = min(new_shape[0] / shape[0], new_shape[1] / shape[1])  # 计算缩放比例
    if not scaleup:  # 只缩小，不放大（为了更好的验证mAP）
        r = min(r, 1.0)

    ratio = r, r  # 宽高比例
    new_unpad = int(round(shape[1] * r)), int(round(shape[0] * r))  # 缩放后的新尺寸
    dw, dh = new_shape[1] - new_unpad[0], new_shape[0] - new_unpad[1]  # 计算需要填充的宽高
    if auto:  # 自动调整为最小矩形
        dw, dh = np.mod(dw, 32), np.mod(dh, 32)  # 填充宽高
    elif scaleFill:  # 拉伸填充
        dw, dh = 0.0, 0.0
        new_unpad = (new_shape[1], new_shape[0])
        ratio = new_shape[1] / shape[1], new_shape[0] / shape[0]  # 宽高比例

    dw /= 2  # 将填充的宽度和高度分成两边
    dh /= 2

    if shape[::-1] != new_unpad:  # 调整图像大小
        img = cv2.resize(img, new_unpad, interpolation=cv2.INTER_LINEAR)
    top, bottom = int(round(dh - 0.1)), int(round(dh + 0.1))
    left, right = int(round(dw - 0.1)), int(round(dw + 0.1))
    img = cv2.copyMakeBorder(img, top, bottom, left, right, cv2.BORDER_CONSTANT, value=color)  # 添加边框
    return img, ratio, (dw, dh)
