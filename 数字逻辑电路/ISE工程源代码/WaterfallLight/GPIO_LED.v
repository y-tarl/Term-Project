`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Design Name: 
// Module Name:    GPIO_LED 
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
module GPIO_LED(

input            clk,
output     [7:0] led

    );
//===================LED====================//
//9s¼ÆÊ±
reg [31:0] time_cnt =0 ;             
always@(posedge clk) 
if(time_cnt == 32'd90000_0000)
	time_cnt <= 32'd0;
else
	time_cnt <= time_cnt + 1'b1;
	
//1S
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
else 
      led_reg<=8'b0000_0000;
assign led = led_reg;	
//===================LED===================//	
endmodule



