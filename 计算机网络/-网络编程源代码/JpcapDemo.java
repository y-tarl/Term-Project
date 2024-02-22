import jpcap.JpcapCaptor;
import jpcap.NetworkInterface;
import jpcap.packet.IPPacket;
import jpcap.packet.Packet;
import java.io.IOException;
import java.util.Scanner;

public class JpcapDemo {
    public static void main(String[] args) {
        /*-------显示网络设备列表-------- */
        // 获取网络接口列表，返回你所有的网络设备数组,一般就是网卡;
        NetworkInterface[] devices = JpcapCaptor.getDeviceList();
        int k = -1;
        // 显示所有网络设备的名称和描述信息;
        // 要注意的是,显示出来的网络设备在不同网络环境下是不同的,可以在控制台使用 ipconfig /all命令查看;
        for (NetworkInterface n : devices) {
            k++;
            System.out.println("序号 " + k + "   " + n.name + "     |     " + n.description);
            System.out.println("----------------------------------------------------------");
        }
        //--------选择网卡并打开网卡连接--------
        // 选择网卡序号;
        System.out.println("请输入你想要监听的网卡序号: ");
        Scanner sc = new Scanner(System.in);
        int index = sc.nextInt();

        JpcapCaptor jpcap = null;// 声明一个JpcapCaptor全局实例变量 jpcap;
        // 打开网卡连接,此时还未开始捕获数据包;
        try {
            // 参数一:选择一个网卡，调用 JpcapCaptor.openDevice()连接，返回一个 JpcapCaptor类的对象 jpcap;
            // 参数二:限制每一次收到一个数据包，只提取该数据包中前1512个字节;
            // 参数三:设置为非混杂模式,才可以使用下面的捕获过滤器方法;
            // 参数四:指定超时的时间;
            jpcap = JpcapCaptor.openDevice(devices[index], 1512, true, 5000);// 捕获时间为5s
        } catch (IOException e) {
            e.printStackTrace();
            System.out.println("抓取数据包时出现异常!!");
        }
        //--------捕获数据包--------
         //捕获四个数据包;
        int i = 0;
        while (i < 3) {
            // Packet getPacket() 捕捉并返回一个数据包。这是 JpcapCaptor实例中四种捕捉包的方法之一;
            // 受到 to_ms参数影响,但一次只抓一个包并返回,或者超时返回 null;
            // 将抓到的包传给 Packet类的一个对象 packet;
            Packet packet = jpcap.getPacket();
            i++;
        IPPacket ipPacket = (IPPacket) packet;// 将 packet类转成 IPPacket类;
        System.out.println("IP报文首部 : " + ipPacket.toString());
        System.out.println("版本 ：" + ipPacket.version);
        System.out.println("总长度：" + ipPacket.length);
        //  System.out.println("时间戳usec(毫秒) : " + ipPacket.usec);
        System.out.println("源IP : " + ipPacket.src_ip.getHostAddress());
        System.out.println("目的IP : " + ipPacket.dst_ip.getHostAddress());
        String protocol;
        switch ((int) ipPacket.protocol) {
            case 1:
                protocol = "ICMP";
                break;
            case 2:
                protocol = "IGMP";
                break;
            case 6:
                protocol = "TCP";
                break;
            case 8:
                protocol = "EGP";
                break;
            case 9:
                protocol = "IGP";
                break;
            case 17:
                protocol = "UDP";
                break;
            case 41:
                protocol = "IPv6";
                break;
            case 89:
                protocol = "OSPF";
                break;
            default:
                protocol = "Other";
                break;
        }
        System.out.println("协议: " + protocol);
        System.out.println("生存时间hop：" + ipPacket.hop_limit);
        System.out.println("标志位RF:保留位必须为false: " + ipPacket.rsv_frag);
        System.out.println("标志位DF（是否允许分片）: " + ipPacket.dont_frag);
        System.out.println("标志位MF（后面是否还有分片）: " + ipPacket.more_frag);
        System.out.println("片偏移offset：" + ipPacket.offset);
        System.out.println("标识ident：" + ipPacket.ident);
        }
    }
}

