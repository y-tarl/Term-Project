`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Design Name:   button_led_buzzer
// Module Name:   F:/Aiyaninfo/demo_button/button_tb.v
// Project Name:  demo_button
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: button_led_buzzer
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module button_tb;

	// Inputs
	reg clk;
	reg [3:0] row;

	// Outputs
	wire [7:0] led;
	wire [3:0] col;
	wire buzzer;

	// Instantiate the Unit Under Test (UUT)
	button_led_buzzer uut (
		.clk(clk), 
		.row(row), 
		.led(led), 
		.col(col), 
		.buzzer(buzzer)
	);

	initial begin
		// Initialize Inputs
		clk = 0;
		row = 0;

		// Wait 100 ns for global reset to finish
		#100;
      row = 4'b1110;  
		#1000000;
		row = 4'b1111;

		// Add stimulus here

	end
   always #5 clk = !clk;
endmodule

