	
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
//修改 只有1~9的按钮被修改
//状态机输出逻辑
reg [4:0] key_out = 5'd0;//记录每个按键按下之后的输出 十进制 
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
						4'b1111:begin key_out <= 5'd17;end
						
					endcase
					
				end
				CHECK_R2:begin
					col <= 4'b1101;//12
					case(row)
						4'b1110:key_out <= 5'd2;  //J2
						4'b1101:key_out <= 5'd6;  //J6
						4'b1011:key_out <= 5'd10;  //J10
						4'b0111:key_out <= 5'd14; //J14
						4'b1111:begin key_out <= 5'd17;end
						
						
					endcase
				
				end
				CHECK_R3:begin
					col <= 4'b1011;//11
					case(row)
						4'b1110:key_out <= 5'd3;  //J3
						4'b1101:key_out <= 5'd7;  //J7
						4'b1011:key_out <= 5'd11; //J11
						4'b0111:key_out <= 5'd15; //J15
						4'b1111:begin key_out <= 5'd17;end
				
					endcase
				
				end
				CHECK_R4:begin
					col <= 4'b0111;//7
					case(row)
						4'b1110:key_out <= 5'd4;  //J4
						4'b1101:key_out <= 5'd8;  //J8
						4'b1011:key_out <= 5'd12; //J12
						4'b0111:key_out <= 5'd16; //J16
						4'b1111:begin key_out <= 5'd17;end
						
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
reg [4:0] key_flag = 5'd0; //用0和1标志两次读数
always@(posedge clk)
begin
	key_out_buf <= key_out;//上升沿的时候 将输出放入到key_out_buf buffer缓冲
end
	
(*KEEP="TRUE"*)reg [19:0] cnt_900us;	
always@(posedge clk)
	if(cnt_900us == 20'd600_00)//按照6000作为一个周期
		cnt_900us <= 20'd0;
	else if(key_out_buf != key_out)
		cnt_900us <= 20'd0;
	else if(key_out_buf == key_out)
		cnt_900us <= cnt_900us + 1'b1;//

reg [4:0] key_out_fliter;//过滤器
//reg [4:0] key_input_new=5'd0;//用于检验是否输入第二个数
reg [4:0] q1=5'd0;//临时存储数1
reg [4:0] q2=5'd0;//存储数2
reg[4:0] qans=5'd0;	//存和
reg [4:0] xiangtong=5'd0;
always@(posedge clk)
begin
	if(cnt_900us >= 20'd200_00 && key_out_buf!=5'd17)//条件 输出按键有定义 并且时间达到了20000
		begin
		key_out_fliter<= key_out_buf;//过滤器 当满足条件的时候 才能将缓存器中的按键指令输出
	   end
	else
      begin	
		key_out_fliter<= key_out_fliter;
		end
	//滤波
	//数据存入寄存器
	if(key_out_fliter>=5'd1&&key_out_fliter<=5'd12)//1~9范围内的加减法
	begin
		if(q1==5'd0&&key_flag==5'd0)//一个按键的数据只存放一次 除非有新的数据被读入
		begin	
			q1=key_out_fliter;
			key_flag=5'd1;//按键数据已经被读取
		end
		else
		begin
		  q2=key_out_fliter;
		  end
	
	 if((q1!=5'd0&&q2!=5'd0 && q1!=q2)||(q1!=5'd0&&q2!=5'd0 &&xiangtong==5'd1))
		//if(q1!=5'd0&&q2!=5'd0)//寄存器都不为0的时候进行加法运算
			begin 
			qans=q1+q2;
			end
	end
	else if(key_out_fliter==5'd14)//作为清零按键
	begin
		qans=5'd0;
		q1=5'd0;
		q2=5'd0;
		key_flag=5'd0;//解除封锁 可以读取下一组数据
		xiangtong=5'd0;
	end
	else if(key_out_fliter==5'd13)
	  xiangtong=5'd1;
	
end
		
(*KEEP="TRUE"*)wire error_flag;//报错
assign error_flag = (key_out_buf != key_out)?1:0;//当缓存内容和接受的按键内容不相同的时候 报错
//======================LED================================//
//输出显示
assign led = {qans[4:0],3'b0};
//======================BUZZER=============================//
always@(posedge clk)
if(key_out_fliter == 5'd15)    //按下J16时，蜂鸣器响//
	buzzer <= 1'b1;
else 
	buzzer <= 1'b0;

//=========================================================//
endmodule
