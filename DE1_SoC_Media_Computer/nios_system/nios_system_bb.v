
module nios_system (
	audio_clk_out_clk,
	audio_config_external_interface_SDAT,
	audio_config_external_interface_SCLK,
	audio_external_interface_ADCDAT,
	audio_external_interface_ADCLRCK,
	audio_external_interface_BCLK,
	audio_external_interface_DACDAT,
	audio_external_interface_DACLRCK,
	clk_50_2_in_clk,
	clk_50_3_in_clk,
	clk_50_in_clk,
	hex2_hex0_external_interface_HEX0,
	hex2_hex0_external_interface_HEX1,
	hex2_hex0_external_interface_HEX2,
	hex5_hex3_external_interface_HEX0,
	hex5_hex3_external_interface_HEX1,
	hex5_hex3_external_interface_HEX2,
	mtl_clk_out_clk,
	parallel_port_0_external_interface_export,
	parallel_port_1_external_interface_export,
	ps2_0_external_interface_CLK,
	ps2_0_external_interface_DAT,
	ps2_mouse_external_interface_CLK,
	ps2_mouse_external_interface_DAT,
	red_leds_external_interface_export,
	reset_bridge_in_reset_n,
	sdram_clk_out_clk,
	sdram_wire_addr,
	sdram_wire_ba,
	sdram_wire_cas_n,
	sdram_wire_cke,
	sdram_wire_cs_n,
	sdram_wire_dq,
	sdram_wire_dqm,
	sdram_wire_ras_n,
	sdram_wire_we_n,
	sys_clk_out_clk,
	vga_clk_out_clk,
	video_controller_external_interface_CLK,
	video_controller_external_interface_HS,
	video_controller_external_interface_VS,
	video_controller_external_interface_BLANK,
	video_controller_external_interface_SYNC,
	video_controller_external_interface_R,
	video_controller_external_interface_G,
	video_controller_external_interface_B);	

	output		audio_clk_out_clk;
	inout		audio_config_external_interface_SDAT;
	output		audio_config_external_interface_SCLK;
	input		audio_external_interface_ADCDAT;
	input		audio_external_interface_ADCLRCK;
	input		audio_external_interface_BCLK;
	output		audio_external_interface_DACDAT;
	input		audio_external_interface_DACLRCK;
	input		clk_50_2_in_clk;
	input		clk_50_3_in_clk;
	input		clk_50_in_clk;
	output	[6:0]	hex2_hex0_external_interface_HEX0;
	output	[6:0]	hex2_hex0_external_interface_HEX1;
	output	[6:0]	hex2_hex0_external_interface_HEX2;
	output	[6:0]	hex5_hex3_external_interface_HEX0;
	output	[6:0]	hex5_hex3_external_interface_HEX1;
	output	[6:0]	hex5_hex3_external_interface_HEX2;
	output		mtl_clk_out_clk;
	input	[9:0]	parallel_port_0_external_interface_export;
	input	[3:0]	parallel_port_1_external_interface_export;
	inout		ps2_0_external_interface_CLK;
	inout		ps2_0_external_interface_DAT;
	inout		ps2_mouse_external_interface_CLK;
	inout		ps2_mouse_external_interface_DAT;
	output	[9:0]	red_leds_external_interface_export;
	input		reset_bridge_in_reset_n;
	output		sdram_clk_out_clk;
	output	[12:0]	sdram_wire_addr;
	output	[1:0]	sdram_wire_ba;
	output		sdram_wire_cas_n;
	output		sdram_wire_cke;
	output		sdram_wire_cs_n;
	inout	[15:0]	sdram_wire_dq;
	output	[1:0]	sdram_wire_dqm;
	output		sdram_wire_ras_n;
	output		sdram_wire_we_n;
	output		sys_clk_out_clk;
	output		vga_clk_out_clk;
	output		video_controller_external_interface_CLK;
	output		video_controller_external_interface_HS;
	output		video_controller_external_interface_VS;
	output		video_controller_external_interface_BLANK;
	output		video_controller_external_interface_SYNC;
	output	[7:0]	video_controller_external_interface_R;
	output	[7:0]	video_controller_external_interface_G;
	output	[7:0]	video_controller_external_interface_B;
endmodule
