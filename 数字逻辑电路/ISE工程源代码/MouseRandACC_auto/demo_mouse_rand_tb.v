`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   09:42:41 06/13/2024
// Design Name:   button_led_buzzer
// Module Name:   C:/Users/Lenovo/Desktop/demo_mouse_rand/demo_mouse_rand_tb.v
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

module demo_mouse_rand_tb;

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
        
		// Add stimulus here

	end
endmodule

