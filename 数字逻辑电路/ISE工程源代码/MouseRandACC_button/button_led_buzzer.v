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
output reg [7:0] led,
output reg [3:0] col,
output reg       buzzer
);

//================4x4按键=========================//
localparam CHECK_R1 = 3'b000; //检测COL1
localparam CHECK_R2 = 3'b001; //检测COL2
localparam CHECK_R3 = 3'b011; //检测COL3
localparam CHECK_R4 = 3'b010; //检测COL4

//================分频计数器逻辑=====================//
reg [16:0] div_cnt = 0; //用于计时1ms
reg        cnt_full = 0; //状态转移标志

always @(posedge clk)
if(div_cnt == 17'd100_000)
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
always @(posedge clk)
begin
    if (game_over) begin
        state <= state; // 保持当前状态
    end else begin
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
end

//状态机输出逻辑
reg [4:0] key_out = 6'd0;
always @(posedge clk)
begin
    case(state)
        CHECK_R1: begin
            col <= 4'b1110;
            case(row)
                4'b1110: key_out <= 5'd0;  //J1
                4'b1101: key_out <= 5'd4;  //J5
                4'b1011: key_out <= 5'd8;  //J9
                4'b0111: key_out <= 5'd12; //J13
                4'b1111: key_out <= 5'd16; //无按键按下
            endcase
        end
        CHECK_R2: begin
            col <= 4'b1101;
            case(row)
                4'b1110: key_out <= 5'd1;  //J2
                4'b1101: key_out <= 5'd5;  //J6
                4'b1011: key_out <= 5'd9;  //J10
                4'b0111: key_out <= 5'd13; //J14
                4'b1111: key_out <= 5'd16; //无按键按下
            endcase
        end
        CHECK_R3: begin
            col <= 4'b1011;
            case(row)
                4'b1110: key_out <= 5'd2;  //J3
                4'b1101: key_out <= 5'd6;  //J7
                4'b1011: key_out <= 5'd10; //J11
                4'b0111: key_out <= 5'd14; //J15
                4'b1111: key_out <= 5'd16; //无按键按下
            endcase
        end
        CHECK_R4: begin
            col <= 4'b0111;
            case(row)
                4'b1110: key_out <= 5'd3;  //J4
                4'b1101: key_out <= 5'd7;  //J8
                4'b1011: key_out <= 5'd11; //J12
                4'b0111: key_out <= 5'd15; //J16
                4'b1111: key_out <= 5'd16; //无按键按下
            endcase
        end    
        default: begin
            col <= 4'b1111;
            key_out <= 5'd16;
        end
    endcase
end

//======================keyfilter==========================//    
reg [4:0] key_out_buf = 5'd0; 
always @(posedge clk)
    key_out_buf <= key_out;

(*KEEP="TRUE"*) reg [19:0] cnt_900us;    
always @(posedge clk)
    if(cnt_900us == 20'd600_00)
        cnt_900us <= 20'd0;
    else if(key_out_buf != key_out)
        cnt_900us <= 20'd0;
    else if(key_out_buf == key_out)
        cnt_900us <= cnt_900us + 1'b1;

reg [4:0] key_out_fliter;
always @(posedge clk)
    if(cnt_900us >= 20'd200_00 && key_out_buf != 5'd16)
        key_out_fliter <= key_out_buf;
    else 
        key_out_fliter <= key_out_fliter;

(*KEEP="TRUE"*) wire error_flag;
assign error_flag = (key_out_buf != key_out) ? 1 : 0;

//======================LED================================//
//assign led = {key_out[3:0],2'b0,state[1:0]};
//[D8,D7,D6,D5]表示按键数，D2,D1长亮表示按键功能正常//
reg [31:0] time_cnt = 0 ;
reg [31:0] time_rand = 0;
reg [31:0] rand;
reg [2:0] temp = 3'd0;
reg [2:0] temp1 = 3'd0;
reg [31:0] cnt = 32'd0;
reg [31:0] limit = 32'd20000_0000;
reg game_over = 0;
reg [7:0] hit_count = 0;

always @(posedge clk) 
begin
    if (game_over) begin
        time_rand <= time_rand;
    end else begin
        temp = temp1 % 4;
        if (temp == 3'd0)
            time_rand <= time_rand + 3'b011;
        else if (temp == 3'd1)
            time_rand <= time_rand + 3'b001;
        else if (temp == 3'd2)
            time_rand <= time_rand + 3'b100;
        else if (temp == 3'd3)
            time_rand <= time_rand + 3'b010;
        else if (temp == 3'd4)
            time_rand <= time_rand + 3'b011;
    end
end

always @(posedge clk)
begin
    if (game_over) begin
        time_cnt <= time_cnt;
        rand <= rand;
        temp1 <= temp1;
    end else begin
        if (key_out_buf == 5'd12 && key_out_fliter == 5'd12)
            limit = 32'd5000_0000;
        else if (key_out_buf == 5'd13 && key_out_fliter == 5'd13)
            limit = 32'd40000_0000;
        
        if (time_cnt == limit)
        begin
            time_cnt <= 32'd0;
            rand <= time_rand % 8;
            temp1 <= temp1 + 3'd1;
        end
        else
        begin
            time_cnt <= time_cnt + 1'b1;
        end
    end
end

// 流水灯
reg [7:0] led_reg;
always @(posedge clk) 
begin
    if (game_over) begin
        led_reg <= 8'b0;
    end else begin
        case (rand)
            32'd0: led_reg <= 8'b0000_0001;
            32'd1: led_reg <= 8'b0000_0010;
            32'd2: led_reg <= 8'b0000_0100;
            32'd3: led_reg <= 8'b0000_1000;
            32'd4: led_reg <= 8'b0001_0000;
            32'd5: led_reg <= 8'b0010_0000;
            32'd6: led_reg <= 8'b0100_0000;            32'd7: led_reg <= 8'b1000_0000;
            default: led_reg <= 8'b0000_0000;
        endcase
    end
end

reg [31:0] time_cnt_1 = 0;
always @(posedge clk) 
    if (time_cnt_1 == 32'd1000_0000)
        time_cnt_1 <= 32'd0;
    else
        time_cnt_1 <= time_cnt_1 + 1'b1;

always @(posedge clk) begin
    if (game_over) begin
        buzzer <= 1'b0;
    end else begin
        if (led_reg == 8'b0000_0001 && key_out_buf == 5'd0) begin
            buzzer <= 1'b1;
            //hit_count <= hit_count + 1;
        end else if (led_reg == 8'b0000_0010 && key_out_buf == 5'd1) begin
            buzzer <= 1'b1;
           //hit_count <= hit_count + 1;
        end else if (led_reg == 8'b0000_0100 && key_out_buf == 5'd2) begin
            buzzer <= 1'b1;
            //hit_count <= hit_count + 1;
        end else if (led_reg == 8'b0000_1000 && key_out_buf == 5'd3) begin
            buzzer <= 1'b1;
            //hit_count <= hit_count + 1;
        end else if (led_reg == 8'b0001_0000 && key_out_buf == 5'd4) begin
            buzzer <= 1'b1;
           // hit_count <= hit_count + 1;
        end else if (led_reg == 8'b0010_0000 && key_out_buf == 5'd5) begin
            buzzer <= 1'b1;
           // hit_count <= hit_count + 1;
        end else if (led_reg == 8'b0100_0000 && key_out_buf == 5'd6) begin
            buzzer <= 1'b1;
           // hit_count <= hit_count + 1;
        end else if (led_reg == 8'b1000_0000 && key_out_buf == 5'd7) begin
            buzzer <= 1'b1;
           // hit_count <= hit_count + 1;
        end else if (time_cnt_1 == 32'd1000_0000)
            buzzer <= 1'b0;
        else
            buzzer <= 1'b0;
				if (buzzer) hit_count <= hit_count + 1;
    end
end

//======================停止游戏与计数显示==========================//
reg [31:0] delay_cnt = 0;
always @(posedge clk) begin
    if (key_out_buf == 5'd14 && key_out_fliter == 5'd14) begin
        game_over <= 1;
    end
    
    if (game_over && delay_cnt < 32'd50_000_000) begin // 0.5秒延迟
        delay_cnt <= delay_cnt + 1;
    end else if (game_over && delay_cnt >= 32'd50_000_000) begin
        led <= 8'b00000000; // 以二进制形式显示打到地鼠的次数
    end else begin
        led <= led_reg;
    end
end

endmodule

            
