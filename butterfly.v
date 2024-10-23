`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 10/18/2024 01:51:25 PM
// Design Name: 
// Module Name: butterfly
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////


module butterfly #(parameter integer BITS = 32, parameter Q = 5)
                  (input wire [BITS-1:0] x0, x1, w, output reg [BITS-1:0] a0, a1);
    always@*
        begin
            a0 <= (x0 + w*x1)%Q;
            a1 <= (x0 + (Q-w)*x1)%Q;
        end
endmodule
