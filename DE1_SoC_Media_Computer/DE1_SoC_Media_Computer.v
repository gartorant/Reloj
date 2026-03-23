// verilog_format: off
//=======================================================
//  Ricardo J. Colom
//  Diciembre 2024
//=======================================================

module DE1_SoC_Media_Computer (

    //////////// ADC //////////
    output ADC_CONVST,
    output ADC_DIN,
    input  ADC_DOUT,
    output ADC_SCLK,

    //////////// Audio //////////
    input  AUD_ADCDAT,
    inout  AUD_ADCLRCK,
    inout  AUD_BCLK,
    output AUD_DACDAT,
    inout  AUD_DACLRCK,
    output AUD_XCK,

    //////////// CLOCK //////////
    input CLOCK2_50,
    input CLOCK3_50,
    input CLOCK4_50,
    input CLOCK_50,

    //////////// SDRAM //////////
    output [12:0] DRAM_ADDR,
    output [ 1:0] DRAM_BA,
    output        DRAM_CAS_N,
    output        DRAM_CKE,
    output        DRAM_CLK,
    output        DRAM_CS_N,
    inout  [15:0] DRAM_DQ,
    output        DRAM_LDQM,
    output        DRAM_RAS_N,
    output        DRAM_UDQM,
    output        DRAM_WE_N,

    //////////// I2C for Audio and Video-In //////////
    output FPGA_I2C_SCLK,
    inout  FPGA_I2C_SDAT,

    //////////// SEG7 //////////
    output [6:0] HEX0,
    output [6:0] HEX1,
    output [6:0] HEX2,
    output [6:0] HEX3,
    output [6:0] HEX4,
    output [6:0] HEX5,

    //////////// IR //////////
    input  IRDA_RXD,
    output IRDA_TXD,

    //////////// KEY //////////
    input [3:0] KEY,

    //////////// LED //////////
    output [9:0] LEDR,

    //////////// PS2 //////////
    inout PS2_CLK,
    inout PS2_CLK2,
    inout PS2_DAT,
    inout PS2_DAT2,

    //////////// SW //////////
    input [9:0] SW,

    //////////// Video-In //////////
    input        TD_CLK27,
    input  [7:0] TD_DATA,
    input        TD_HS,
    output       TD_RESET_N,
    input        TD_VS,

    //////////// VGA //////////
    output       VGA_BLANK_N,
    output [7:0] VGA_B,
    output       VGA_CLK,
    output [7:0] VGA_G,
    output       VGA_HS,
    output [7:0] VGA_R,
    output       VGA_SYNC_N,
    output       VGA_VS

);



  //=======================================================
  //  REG/WIRE declarations
  //=======================================================

  assign TD_RESET_N = 1'b1;


  //=======================================================
  //  Structural coding
  //=======================================================

  //Aquí es donde va vuestro Sistema generado en la Platform Designer

  nios_system u0 (
      .audio_clk_out_clk(AUD_XCK),                                  //                       audio_clk_out.clk
      .clk_50_2_in_clk(CLOCK2_50),                                  //                         clk_50_2_in.clk
      .clk_50_3_in_clk(CLOCK3_50),                                  //                         clk_50_3_in.clk
      .clk_50_in_clk(CLOCK_50),                                     //                           clk_50_in.clk
      .hex2_hex0_external_interface_HEX0(HEX0),                     //        hex2_hex0_external_interface.HEX0
      .hex2_hex0_external_interface_HEX1(HEX1),                     //                                    .HEX1
      .hex2_hex0_external_interface_HEX2(HEX2),                     //                                    .HEX2
      .mtl_clk_out_clk(),                                           //                           mtl_clk_out.clk
      .red_leds_external_interface_export(LEDR),                    //         red_leds_external_interface.export
      .reset_bridge_in_reset_n(1'b1),                               //                     reset_bridge_in.reset_n
      .sdram_clk_out_clk(DRAM_CLK),                                 //                       sdram_clk_out.clk
      .sdram_wire_addr(DRAM_ADDR),                                  //                          sdram_wire.addr
      .sdram_wire_ba(DRAM_BA),                                      //                                    .ba
      .sdram_wire_cas_n(DRAM_CAS_N),                                //                                    .cas_n
      .sdram_wire_cke(DRAM_CKE),                                    //                                    .cke
      .sdram_wire_cs_n(DRAM_CS_N),                                  //                                    .cs_n
      .sdram_wire_dq(DRAM_DQ),                                      //                                    .dq
      .sdram_wire_dqm(DRAM_LDQM),                                   //                                    .dqm
      .sdram_wire_ras_n(DRAM_RAS_N),                                //                                    .ras_n
      .sdram_wire_we_n(DRAM_WE_N),                                  //                                    .we_n
      .sys_clk_out_clk(),                                           //                         sys_clk_out.clk
      .vga_clk_out_clk(),                                           //                         vga_clk_out.clk
      .hex5_hex3_external_interface_HEX0(HEX3),                     //        hex5_hex3_external_interface.HEX3
      .hex5_hex3_external_interface_HEX1(HEX4),                     //                                    .HEX4
      .hex5_hex3_external_interface_HEX2(HEX5),                     //                                    .HEX5
      .parallel_port_0_external_interface_export(SW),               //  parallel_port_0_external_interface.export
      .parallel_port_1_external_interface_export (KEY),             //  parallel_port_1_external_interface.export
      .ps2_0_external_interface_CLK(PS2_CLK),                       //            ps2_0_external_interface.CLK
      .ps2_0_external_interface_DAT(PS2_DAT),                       //                                    .DAT
      .ps2_mouse_external_interface_CLK(PS2_CLK2),                  //        ps2_mouse_external_interface.CLK
      .ps2_mouse_external_interface_DAT(PS2_DAT2),                  //                                    .DAT
      .audio_config_external_interface_SDAT      (FPGA_I2C_SDAT),   //     audio_config_external_interface.SDAT
      .audio_config_external_interface_SCLK      (FPGA_I2C_SCLK),   //                                    .SCLK
      .audio_external_interface_ADCDAT(AUD_ADCDAT),                 //            audio_external_interface.ADCDAT
      .audio_external_interface_ADCLRCK          (AUD_ADCLRCK),     //                                    .ADCLRCK
      .audio_external_interface_BCLK(AUD_BCLK),                     //                                    .BCLK
      .audio_external_interface_DACDAT(AUD_DACDAT),                 //                                    .DACDAT
      .audio_external_interface_DACLRCK(AUD_XCK),                   //                                    .DACLRCK
      .video_controller_external_interface_CLK(VGA_CLK),            // video_controller_external_interface.CLK
      .video_controller_external_interface_HS(VGA_HS),              //                                    .HS
      .video_controller_external_interface_VS(VGA_VS),              //                                    .VS
      .video_controller_external_interface_BLANK (VGA_BLANK_N),     //                                    .BLANK
      .video_controller_external_interface_SYNC  (VGA_SYNC_N),      //                                    .SYNC
      .video_controller_external_interface_R(VGA_R),                //                                    .R
      .video_controller_external_interface_G(VGA_G),                //                                    .G
      .video_controller_external_interface_B(VGA_B)                 //                                    .B
  );

endmodule
// verilog_format: on