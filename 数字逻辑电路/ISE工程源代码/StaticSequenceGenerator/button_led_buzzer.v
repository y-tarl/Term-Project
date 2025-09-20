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
    if(time_cnt == 32'd100000000)//4.5的周期
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
						4'b1110:key_out <= 5'd0;  //J1
						4'b1101:key_out <= 5'd4;  //J5
						4'b1011:key_out <= 5'd8;  //J9
						4'b0111:key_out <= 5'd12; //J13
						4'b1111:key_out <= 5'd16; //无按键按下
					endcase
				end
				CHECK_R2:begin
					col <= 4'b1101;//12
					case(row)
						4'b1110:key_out <= 5'd1;  //J2
						4'b1101:key_out <= 5'd5;  //J6
						4'b1011:key_out <= 5'd9;  //J10
						4'b0111:key_out <= 5'd13; //J14
						4'b1111:key_out <= 5'd16; //无按键按下
					endcase
				end
				CHECK_R3:begin
					col <= 4'b1011;//11
					case(row)
						4'b1110:key_out <= 5'd2;  //J3
						4'b1101:key_out <= 5'd6;  //J7
						4'b1011:key_out <= 5'd10; //J11
						4'b0111:key_out <= 5'd14; //J15
						4'b1111:key_out <= 5'd16; //无按键按下
					endcase
				end
				CHECK_R4:begin
					col <= 4'b0111;//7
					case(row)
						4'b1110:key_out <= 5'd3;  //J4
						4'b1101:key_out <= 5'd7;  //J8
						4'b1011:key_out <= 5'd11; //J12
						4'b0111:key_out <= 5'd15; //J16
						4'b1111:key_out <= 5'd16; //无按键按下
					endcase
				end	
				default:begin
					col <= 4'b1111;//15
					key_out <= 5'd16;//
				end
			endcase
	end

//======================keyfilter==========================//排除信号的毛刺	

reg [4:0] key_out_buf = 5'd0; 
always@(posedge clk)
	key_out_buf <= key_out;//上升沿的时候 将输出放入到key_out_buf buffer缓冲
//判断当前状态和前一个时间单位的状态相同，并且维持了一定时间	
(*KEEP="TRUE"*)reg [19:0] cnt_900us;	
always@(posedge clk)
	if(cnt_900us == 20'd600_00)//按照6000作为一个周期
		cnt_900us <= 20'd0;
    else if(key_out_buf != key_out)//key_out_buf相当于记录前一个时刻的按键状态和当前状态比较
		cnt_900us <= 20'd0;//只有在key_out_buf和key_out相等的时候 才记录时间
	else if(key_out_buf == key_out)
		cnt_900us <= cnt_900us + 1'b1;//当当前按键状态和前一个状态

reg [4:0] key_out_fliter;
always@(posedge clk)
    if(cnt_900us >= 20'd200_00 && key_out_buf!=5'd16)//稳定时间达到了20000(按键按下动作保持了2ms)并且按键有效的时候
		key_out_fliter <= key_out_buf;//过滤器 当满足条件的时候 才能将缓存器中的按键指令输出
	else 
		key_out_fliter <= key_out_fliter;
		
(*KEEP="TRUE"*)wire error_flag;//报错
assign error_flag = (key_out_buf != key_out)?1:0;//当缓存内容和接受的按键内容不相同的时候 报错


//======================BUZZER=============================//

//reg [15:0]testseq=16'b00000000_00011101;//00011101
reg [15:0]testseq=16'b00000000_10111000;
reg [3:0]times=4'd0;//计数器
always@(posedge clk)
if(key_out_fliter == 5'd13) 
begin
//	testseq={testseq[7:0],testseq[7:0]};
testseq={testseq[7:0],8'd0};
end
else if(key_out_fliter == 5'd15)   
begin
	buzzer = 1'b0;//蜂鸣器不响
	if(times==4'd8)
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
else if(key_out_fliter==5'd0)
begin
 //  testseq=16'b00000000_00011101;
 testseq=16'b00000000_10111000;
	buzzer=1'b0;
	times=4'd0;
end
else //点按其他按键 关闭蜂鸣器
	buzzer = 1'b0;
//=========================================================//

//======================LED================================//
assign led={testseq[7:0]};

endmodule