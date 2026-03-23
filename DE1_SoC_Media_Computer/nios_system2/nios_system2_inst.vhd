	component nios_system2 is
		port (
			audio_clk_out_clk                         : out   std_logic;                                        -- clk
			audio_config_external_interface_SDAT      : inout std_logic                     := 'X';             -- SDAT
			audio_config_external_interface_SCLK      : out   std_logic;                                        -- SCLK
			audio_external_interface_ADCDAT           : in    std_logic                     := 'X';             -- ADCDAT
			audio_external_interface_ADCLRCK          : in    std_logic                     := 'X';             -- ADCLRCK
			audio_external_interface_BCLK             : in    std_logic                     := 'X';             -- BCLK
			audio_external_interface_DACDAT           : out   std_logic;                                        -- DACDAT
			audio_external_interface_DACLRCK          : in    std_logic                     := 'X';             -- DACLRCK
			clk_50_2_in_clk                           : in    std_logic                     := 'X';             -- clk
			clk_50_3_in_clk                           : in    std_logic                     := 'X';             -- clk
			clk_50_in_clk                             : in    std_logic                     := 'X';             -- clk
			hex2_hex0_external_interface_HEX0         : out   std_logic_vector(6 downto 0);                     -- HEX0
			hex2_hex0_external_interface_HEX1         : out   std_logic_vector(6 downto 0);                     -- HEX1
			hex2_hex0_external_interface_HEX2         : out   std_logic_vector(6 downto 0);                     -- HEX2
			hex5_hex3_external_interface_HEX0         : out   std_logic_vector(6 downto 0);                     -- HEX0
			hex5_hex3_external_interface_HEX1         : out   std_logic_vector(6 downto 0);                     -- HEX1
			hex5_hex3_external_interface_HEX2         : out   std_logic_vector(6 downto 0);                     -- HEX2
			mtl_clk_out_clk                           : out   std_logic;                                        -- clk
			parallel_port_0_external_interface_export : in    std_logic_vector(9 downto 0)  := (others => 'X'); -- export
			parallel_port_1_external_interface_export : in    std_logic_vector(3 downto 0)  := (others => 'X'); -- export
			ps2_0_external_interface_CLK              : inout std_logic                     := 'X';             -- CLK
			ps2_0_external_interface_DAT              : inout std_logic                     := 'X';             -- DAT
			ps2_mouse_external_interface_CLK          : inout std_logic                     := 'X';             -- CLK
			ps2_mouse_external_interface_DAT          : inout std_logic                     := 'X';             -- DAT
			red_leds_external_interface_export        : out   std_logic_vector(9 downto 0);                     -- export
			reset_bridge_in_reset_n                   : in    std_logic                     := 'X';             -- reset_n
			sdram_clk_out_clk                         : out   std_logic;                                        -- clk
			sdram_wire_addr                           : out   std_logic_vector(12 downto 0);                    -- addr
			sdram_wire_ba                             : out   std_logic_vector(1 downto 0);                     -- ba
			sdram_wire_cas_n                          : out   std_logic;                                        -- cas_n
			sdram_wire_cke                            : out   std_logic;                                        -- cke
			sdram_wire_cs_n                           : out   std_logic;                                        -- cs_n
			sdram_wire_dq                             : inout std_logic_vector(15 downto 0) := (others => 'X'); -- dq
			sdram_wire_dqm                            : out   std_logic_vector(1 downto 0);                     -- dqm
			sdram_wire_ras_n                          : out   std_logic;                                        -- ras_n
			sdram_wire_we_n                           : out   std_logic;                                        -- we_n
			sys_clk_out_clk                           : out   std_logic;                                        -- clk
			vga_clk_out_clk                           : out   std_logic;                                        -- clk
			video_controller_external_interface_CLK   : out   std_logic;                                        -- CLK
			video_controller_external_interface_HS    : out   std_logic;                                        -- HS
			video_controller_external_interface_VS    : out   std_logic;                                        -- VS
			video_controller_external_interface_BLANK : out   std_logic;                                        -- BLANK
			video_controller_external_interface_SYNC  : out   std_logic;                                        -- SYNC
			video_controller_external_interface_R     : out   std_logic_vector(7 downto 0);                     -- R
			video_controller_external_interface_G     : out   std_logic_vector(7 downto 0);                     -- G
			video_controller_external_interface_B     : out   std_logic_vector(7 downto 0)                      -- B
		);
	end component nios_system2;

	u0 : component nios_system2
		port map (
			audio_clk_out_clk                         => CONNECTED_TO_audio_clk_out_clk,                         --                       audio_clk_out.clk
			audio_config_external_interface_SDAT      => CONNECTED_TO_audio_config_external_interface_SDAT,      --     audio_config_external_interface.SDAT
			audio_config_external_interface_SCLK      => CONNECTED_TO_audio_config_external_interface_SCLK,      --                                    .SCLK
			audio_external_interface_ADCDAT           => CONNECTED_TO_audio_external_interface_ADCDAT,           --            audio_external_interface.ADCDAT
			audio_external_interface_ADCLRCK          => CONNECTED_TO_audio_external_interface_ADCLRCK,          --                                    .ADCLRCK
			audio_external_interface_BCLK             => CONNECTED_TO_audio_external_interface_BCLK,             --                                    .BCLK
			audio_external_interface_DACDAT           => CONNECTED_TO_audio_external_interface_DACDAT,           --                                    .DACDAT
			audio_external_interface_DACLRCK          => CONNECTED_TO_audio_external_interface_DACLRCK,          --                                    .DACLRCK
			clk_50_2_in_clk                           => CONNECTED_TO_clk_50_2_in_clk,                           --                         clk_50_2_in.clk
			clk_50_3_in_clk                           => CONNECTED_TO_clk_50_3_in_clk,                           --                         clk_50_3_in.clk
			clk_50_in_clk                             => CONNECTED_TO_clk_50_in_clk,                             --                           clk_50_in.clk
			hex2_hex0_external_interface_HEX0         => CONNECTED_TO_hex2_hex0_external_interface_HEX0,         --        hex2_hex0_external_interface.HEX0
			hex2_hex0_external_interface_HEX1         => CONNECTED_TO_hex2_hex0_external_interface_HEX1,         --                                    .HEX1
			hex2_hex0_external_interface_HEX2         => CONNECTED_TO_hex2_hex0_external_interface_HEX2,         --                                    .HEX2
			hex5_hex3_external_interface_HEX0         => CONNECTED_TO_hex5_hex3_external_interface_HEX0,         --        hex5_hex3_external_interface.HEX0
			hex5_hex3_external_interface_HEX1         => CONNECTED_TO_hex5_hex3_external_interface_HEX1,         --                                    .HEX1
			hex5_hex3_external_interface_HEX2         => CONNECTED_TO_hex5_hex3_external_interface_HEX2,         --                                    .HEX2
			mtl_clk_out_clk                           => CONNECTED_TO_mtl_clk_out_clk,                           --                         mtl_clk_out.clk
			parallel_port_0_external_interface_export => CONNECTED_TO_parallel_port_0_external_interface_export, --  parallel_port_0_external_interface.export
			parallel_port_1_external_interface_export => CONNECTED_TO_parallel_port_1_external_interface_export, --  parallel_port_1_external_interface.export
			ps2_0_external_interface_CLK              => CONNECTED_TO_ps2_0_external_interface_CLK,              --            ps2_0_external_interface.CLK
			ps2_0_external_interface_DAT              => CONNECTED_TO_ps2_0_external_interface_DAT,              --                                    .DAT
			ps2_mouse_external_interface_CLK          => CONNECTED_TO_ps2_mouse_external_interface_CLK,          --        ps2_mouse_external_interface.CLK
			ps2_mouse_external_interface_DAT          => CONNECTED_TO_ps2_mouse_external_interface_DAT,          --                                    .DAT
			red_leds_external_interface_export        => CONNECTED_TO_red_leds_external_interface_export,        --         red_leds_external_interface.export
			reset_bridge_in_reset_n                   => CONNECTED_TO_reset_bridge_in_reset_n,                   --                     reset_bridge_in.reset_n
			sdram_clk_out_clk                         => CONNECTED_TO_sdram_clk_out_clk,                         --                       sdram_clk_out.clk
			sdram_wire_addr                           => CONNECTED_TO_sdram_wire_addr,                           --                          sdram_wire.addr
			sdram_wire_ba                             => CONNECTED_TO_sdram_wire_ba,                             --                                    .ba
			sdram_wire_cas_n                          => CONNECTED_TO_sdram_wire_cas_n,                          --                                    .cas_n
			sdram_wire_cke                            => CONNECTED_TO_sdram_wire_cke,                            --                                    .cke
			sdram_wire_cs_n                           => CONNECTED_TO_sdram_wire_cs_n,                           --                                    .cs_n
			sdram_wire_dq                             => CONNECTED_TO_sdram_wire_dq,                             --                                    .dq
			sdram_wire_dqm                            => CONNECTED_TO_sdram_wire_dqm,                            --                                    .dqm
			sdram_wire_ras_n                          => CONNECTED_TO_sdram_wire_ras_n,                          --                                    .ras_n
			sdram_wire_we_n                           => CONNECTED_TO_sdram_wire_we_n,                           --                                    .we_n
			sys_clk_out_clk                           => CONNECTED_TO_sys_clk_out_clk,                           --                         sys_clk_out.clk
			vga_clk_out_clk                           => CONNECTED_TO_vga_clk_out_clk,                           --                         vga_clk_out.clk
			video_controller_external_interface_CLK   => CONNECTED_TO_video_controller_external_interface_CLK,   -- video_controller_external_interface.CLK
			video_controller_external_interface_HS    => CONNECTED_TO_video_controller_external_interface_HS,    --                                    .HS
			video_controller_external_interface_VS    => CONNECTED_TO_video_controller_external_interface_VS,    --                                    .VS
			video_controller_external_interface_BLANK => CONNECTED_TO_video_controller_external_interface_BLANK, --                                    .BLANK
			video_controller_external_interface_SYNC  => CONNECTED_TO_video_controller_external_interface_SYNC,  --                                    .SYNC
			video_controller_external_interface_R     => CONNECTED_TO_video_controller_external_interface_R,     --                                    .R
			video_controller_external_interface_G     => CONNECTED_TO_video_controller_external_interface_G,     --                                    .G
			video_controller_external_interface_B     => CONNECTED_TO_video_controller_external_interface_B      --                                    .B
		);

