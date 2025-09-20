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
    
input            clk,
input      [3:0] row,
output     [7:0] led,
output reg [3:0] col,
output reg       buzzer
);

//================4x4按键=========================//
   localparam				CHECK_R1=3'b000;//检测COL1
	localparam				CHECK_R2=3'b001;//检测COL2
	localparam				CHECK_R3=3'b011;//检测COL3
	localparam				CHECK_R4=3'b010;//检测COL4

//================分频计数器逻辑=====================//
reg [16:0] div_cnt = 0 ;	//用于计时1ms
reg        cnt_full = 0 ;  //状态转移标志

always@(posedge clk )      //此处设计每次拉高一列时间为1ms
if(div_cnt==17'd1000_00)
	begin
		div_cnt <= 16'd0;
		cnt_full <= 1'b1;
	end
else 
	begin
		div_cnt <= div_cnt + 1'b1;
		cnt_full <= 1'b0;
	end
	
//状态组合判断
reg [2:0] state = 3'b000;
always@(posedge clk)
	begin
			case(state)
				CHECK_R1:
					if(cnt_full)
						state <= CHECK_R2;
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
reg [4:0] key_out = 6'd0;
always@(posedge clk)
	begin
			case(state)
				CHECK_R1:begin
					col <= 4'b1110;
					case(row)					   
						4'b1110:key_out <= 5'd0;  //J1
						4'b1101:key_out <= 5'd4;  //J5
						4'b1011:key_out <= 5'd8;  //J9
						4'b0111:key_out <= 5'd12; //J13
						4'b1111:key_out <= 5'd16; //无按键按下
					endcase
				end
				CHECK_R2:begin
					col <= 4'b1101;
					case(row)
						4'b1110:key_out <= 5'd1;  //J2
						4'b1101:key_out <= 5'd5;  //J6
						4'b1011:key_out <= 5'd9;  //J10
						4'b0111:key_out <= 5'd13; //J14
						4'b1111:key_out <= 5'd16; //无按键按下
					endcase
				end
				CHECK_R3:begin
					col <= 4'b1011;
					case(row)
						4'b1110:key_out <= 5'd2;  //J3
						4'b1101:key_out <= 5'd6;  //J7
						4'b1011:key_out <= 5'd10; //J11
						4'b0111:key_out <= 5'd14; //J15
						4'b1111:key_out <= 5'd16; //无按键按下
					endcase
				end
				CHECK_R4:begin
					col <= 4'b0111;
					case(row)
						4'b1110:key_out <= 5'd3;  //J4
						4'b1101:key_out <= 5'd7;  //J8
						4'b1011:key_out <= 5'd11; //J12
						4'b0111:key_out <= 5'd15; //J16
						4'b1111:key_out <= 5'd16; //无按键按下
					endcase
				end	
				default:begin
					col <= 4'b1111;
					key_out <= 5'd16;
				end
			endcase
	end
//======================keyfilter==========================//	
reg [4:0] key_out_buf = 5'd0; 
always@(posedge clk)
	key_out_buf <= key_out;
	
(*KEEP="TRUE"*)reg [19:0] cnt_900us;	
always@(posedge clk)
	if(cnt_900us == 20'd600_00)
		cnt_900us <= 20'd0;
	else if(key_out_buf != key_out)
		cnt_900us <= 20'd0;
	else if(key_out_buf == key_out)
		cnt_900us <= cnt_900us + 1'b1;

reg [4:0] key_out_fliter;
always@(posedge clk)
	if(cnt_900us >= 20'd200_00 && key_out_buf!=5'd16)
		key_out_fliter <= key_out_buf;
	else 
		key_out_fliter <= key_out_fliter;
		
(*KEEP="TRUE"*)wire error_flag;
assign error_flag = (key_out_buf != key_out)?1:0;
//always@(posedge clk)
//if(key_out_buf != key_out)
//		error_flag <= 1'b1;
//else 
//		error_flag <= 1'b0;
//======================LED================================//
//assign led = {key_out[3:0],2'b0,state[1:0]};
//[D8,D7,D6,D5]表示按键数，D2,D1长亮表示按键功能正常//
reg [31:0] time_cnt =0 ;             
always@(posedge clk) 
if(time_cnt == 32'd80000_0000)
	time_cnt <= 32'd0;
else
	time_cnt <= time_cnt + 1'b1;

// 流水灯
reg [7:0] led_reg;
always@(posedge clk) 
if(time_cnt <= 32'd10000_0000)
	led_reg<=8'b0000_0001;
else if(time_cnt <= 32'd20000_0000)
	led_reg<=8'b0000_0010;
else if(time_cnt <= 32'd30000_0000)
	led_reg<=8'b0000_0100;
else if(time_cnt <= 32'd40000_0000)
	led_reg<=8'b0000_1000;
else if(time_cnt <= 32'd50000_0000)
	led_reg<=8'b0001_0000;
else if(time_cnt <= 32'd60000_0000)
	led_reg<=8'b0010_0000;
else if(time_cnt <= 32'd70000_0000)
	led_reg<=8'b0100_0000;
else if(time_cnt <= 32'd80000_0000)
	led_reg<=8'b1000_0000;
	

	
reg [31:0] time_cnt_1 =0 ;
always@(posedge clk) 
	if(time_cnt_1 == 32'd1000_0000)
		time_cnt_1 <= 32'd0;
	else
		time_cnt_1 <= time_cnt_1 + 1'b1;

always@(posedge clk) begin
	if(led_reg==8'b0000_0001&&key_out_buf==5'd0)
		buzzer <= 1'b1;
	else if(led_reg==8'b0000_0010&&key_out_buf==5'd1)
		buzzer <= 1'b1;
	else if(led_reg==8'b0000_0100&&key_out_buf==5'd2)
		buzzer <= 1'b1;
	else if(led_reg==8'b0000_1000&&key_out_buf==5'd3)
		buzzer <= 1'b1;
	else if(led_reg==8'b0001_0000&&key_out_buf==5'd4)
		buzzer <= 1'b1;
	else if(led_reg==8'b0010_0000&&key_out_buf==5'd5)
		buzzer <= 1'b1;
	else if(led_reg==8'b0100_0000&&key_out_buf==5'd6)
		buzzer <= 1'b1;
	else if(led_reg==8'b1000_0000&&key_out_buf==5'd7)
		buzzer <= 1'b1;
	else if(time_cnt_1 == 32'd1000_0000)
		buzzer <= 1'b0;
	else
		buzzer <= 1'b0;
end

assign led = led_reg;
//=========================================================//

endmodule