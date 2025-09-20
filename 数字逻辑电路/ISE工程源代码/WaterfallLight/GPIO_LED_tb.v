`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   11:21:58 05/27/2023
// Design Name:   GPIO_LED
// Module Name:   E:/shudian/demo_GPIO/GPIO_LED_tb.v
// Project Name:  demo_GPIO
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: GPIO_LED
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module GPIO_LED_tb;

	// Inputs
	reg clk;

	// Outputs
	wire [7:0] led;

	// Instantiate the Unit Under Test (UUT)
	GPIO_LED uut (
		.clk(clk), 
		.led(led)
	);

	initial begin
		// Initialize Inputs
		clk = 0;

		// Wait 100 ns for global reset to finish
		#100;
        
		// Add stimulus here

	end
always #5 clk = !clk;      

endmodule
