`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// Design Name: 
// Module Name:    button_led_buzzer 
// Project Name: 
// Target Devices: 
// Tool versions: 
// Description: 
//
// Dependencies: 
//
// Revision: 
// Revision 0.01 - File Created
// Additional Comments: 
//
//////////////////////////////////////////////////////////////////////////////////
module button_led_buzzer(
    
input            clk,//系统时钟信号
input      [3:0] row,//4个行
output     [7:0] led,//对应按键的LED灯会亮
output reg [3:0] col,
output reg       buzzer
);

//================4x4按键=========================//
//定义4个按键的地址 是列地址
   localparam				CHECK_R1=3'b000;//检测COL1
	localparam				CHECK_R2=3'b001;//检测COL2
	localparam				CHECK_R3=3'b011;//检测COL3
	localparam				CHECK_R4=3'b010;//检测COL4


//1s计时
reg [31:0] time_cnt =0 ;             
always@(posedge clk) 
    if(time_cnt == 32'd100000000)//1的周期
	time_cnt <= 32'd0;
else
	time_cnt <= time_cnt + 1'b1;

//================分频计数器逻辑=====================//
reg [16:0] div_cnt = 0 ;	//用于计时1ms
reg        cnt_full = 0 ;  //状态转移标志

always@(posedge clk )      //此处设计每次拉高一列时间为1ms
if(div_cnt==17'd1000_00)//用于计时1ms
	begin
		div_cnt <= 16'd0;
		cnt_full <= 1'b1;//已经完成一个周期
	end
else 
	begin
		div_cnt <= div_cnt + 1'b1;
		cnt_full <= 1'b0;//还未完成一个周期
	end
	
//状态组合判断--不断地转换到下一组按键
reg [2:0] state = 3'b000;
always@(posedge clk)
	begin
			case(state)
				CHECK_R1:
					if(cnt_full)//完成一个周期
						state <= CHECK_R2;//跳转到下一列
					else
						state <= CHECK_R1;
				CHECK_R2:
					if(cnt_full)
						state <= CHECK_R3;
					else
						state <= CHECK_R2;
				CHECK_R3:
					if(cnt_full)
						state <= CHECK_R4;
					else
						state <= CHECK_R3;
				CHECK_R4:
					if(cnt_full)
						state <= CHECK_R1;
					else
						state <= CHECK_R4;
				default:
					state <= state;
			endcase
	end

//状态机输出逻辑
reg [4:0] key_out = 6'd0;//记录每个按键按下之后的输出 十进制 
always@(posedge clk)
	begin
			case(state)//先判按键状态正常 对于按键位置 先判断列 再判断行
				CHECK_R1:begin
					col <= 4'b1110;//14
					case(row)
						4'b1110:key_out <= 5'd1;  //J1
						4'b1101:key_out <= 5'd5;  //J5
						4'b1011:key_out <= 5'd9;  //J9
						4'b0111:key_out <= 5'd13; //J13
						4'b1111:key_out <= 5'd17; //无按键按下
					endcase
				end
				CHECK_R2:begin
					col <= 4'b1101;//12
					case(row)
					   4'b1110:key_out <= 5'd2;  //J2
						4'b1101:key_out <= 5'd6;  //J6
						4'b1011:key_out <= 5'd10; //J10
						4'b0111:key_out <= 5'd14; //J14
						4'b1111:key_out <= 5'd17; //无按键按下
					endcase
				end
				CHECK_R3:begin
					col <= 4'b1011;//11
					case(row)
						4'b1110:key_out <= 5'd3;  //J3
						4'b1101:key_out <= 5'd7;  //J7
						4'b1011:key_out <= 5'd11; //J11
						4'b0111:key_out <= 5'd15; //J15
						4'b1111:key_out <= 5'd17; //无按键按下
					endcase
				end
				CHECK_R4:begin
					col <= 4'b0111;//7
					case(row)
						4'b1110:key_out <= 5'd4;  //J4
						4'b1101:key_out <= 5'd8;  //J8
						4'b1011:key_out <= 5'd12; //J12
						4'b0111:key_out <= 5'd16; //J16
						4'b1111:key_out <= 5'd17; //无按键按下
					endcase
				end	
				default:begin
					col <= 4'b1111;//15
					key_out <= 5'd17;//
				end
			endcase
	end

//======================keyfilter==========================//排除信号的毛刺	
reg [4:0] key_out_buf = 5'd0; 
always@(posedge clk)
	key_out_buf <= key_out;//上升沿的时候 将输出放入到key_out_buf buffer缓冲
	
(*KEEP="TRUE"*)reg [19:0] cnt_900us;	
always@(posedge clk)
	if(cnt_900us == 20'd600_00)//按照6000作为一个周期
		cnt_900us <= 20'd0;
	else if(key_out_buf != key_out)
		cnt_900us <= 20'd0;
	else if(key_out_buf == key_out)
		cnt_900us <= cnt_900us + 1'b1;//

reg [4:0] key_out_fliter;
always@(posedge clk)//J16的发射按键在后面信号输出单元实现
	if(cnt_900us >= 20'd200_00 && key_out_buf!=5'd17)//条件 输出按键有定义 并且时间达到了20000
		key_out_fliter <= key_out_buf;//过滤器 当满足条件的时候 才能将缓存器中的按键指令输出
	else 
		key_out_fliter <= key_out_fliter;//否则保持之前的按键信息
		
	
		
(*KEEP="TRUE"*)wire error_flag;//报错
assign error_flag = (key_out_buf != key_out)?1:0;//当缓存内容和接受的按键内容不相同的时候 报错

//======================BUZZER=============================//
reg [7:0]firseq=8'b00000000;				//按键输入的序列
reg [15:0]testseq=16'b0000000000000000;//测试序列，用于输出的缓冲和存储firseq
reg [3:0]times=4'd0;//计数器
integer i;
always@(posedge clk)
	if(key_out_fliter>=5'd1&&key_out_fliter<=5'd8)//按键J1~J8 对应位置是序列7~0位
	begin
		for(i=0;i<8;i=i+1)//读取八位按键
		begin
			if(i==key_out_fliter-1)//接受输入的按键信号
				firseq[i]=1'b1;
		end
	end
	else if(key_out_fliter==5'd14)//J14为确认按键 将firseq更新到testseq并且以led的形式输出
	begin
		testseq={firseq[7:0],firseq[7:0]};
	end
	else if(key_out_fliter==5'd15)//J15作为清零按键
	begin
	   buzzer=1'b0;
      firseq=8'b00000000;
      testseq={firseq[7:0],firseq[7:0]};
		times=4'd0;
	end
	else if(key_out_fliter == 5'd16)//J16作为发射按键   
	begin
	   if(times==4'd0)
		begin
		   testseq={8'b00000000,firseq[7:0]};//在开始时对其赋值，构成输出序列
		end
		buzzer=1'b0;//蜂鸣器不响
		if(times==4'd8)//第八秒后，运行结束，蜂鸣器报警
		begin
			buzzer = 1'b1;
		end
		else
		begin
			if(time_cnt == 32'd100000000)//每隔1s
			begin
			testseq={testseq[14:0],testseq[15]};//每1s移动一位
			times=times+1'b1;//计数器+1
			end
		end
	end
	else if(key_out_fliter==5'd13)//点按按键J13 关闭蜂鸣器
	begin
		buzzer = 1'b0;
	end
//============================LED=============================//

assign led={testseq[7:0]};//led灯，输出testseq的前八位来作显示

endmodule