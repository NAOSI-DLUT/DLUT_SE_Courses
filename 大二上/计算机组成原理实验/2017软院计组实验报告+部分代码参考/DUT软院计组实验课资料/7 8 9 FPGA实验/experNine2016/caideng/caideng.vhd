----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    15:24:40 04/08/2013 
-- Design Name: 
-- Module Name:    caideng - Behavioral 
-- Project Name: 
-- Target Devices: 
-- Tool versions: 
-- Description: 
--
-- Dependencies: 
--
-- Revision: 
-- Revision 0.01 - File Created
-- Additional Comments: 
--
----------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_ARITH.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

---- Uncomment the following library declaration if instantiating
---- any Xilinx primitives in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity caideng is
	PORT(
		clk : IN STD_LOGIC;
		rst : IN STD_LOGIC;
		led : OUT STD_LOGIC_VECTOR(7 downto 0)
	);
end caideng;

architecture Behavioral of caideng is
	TYPE color IS (S0,S1,S2,S3,S4,S5,S6,s7,s8); --九种状态  
	SIGNAL Cur_STATE,Next_STATE : color;
	SIGNAL clk_temp : std_logic; --分频后的时钟
	SIGNAL count : std_logic_vector(15 downto 0); --计数器，用来统计时钟上升沿
BEGIN

	PROCESS(clk)
	BEGIN
		IF (clk'event AND clk='1') THEN
			IF(count="1111111111111111") THEN --没想到要这么大的分频才能看到效果
				count <= (OTHERS =>'0');
				clk_temp <= NOT clk_temp;
			ELSE
				count <= count + 1;
			END IF ;
		END IF ;
	END PROCESS;

	PROCESS(clk_temp, rst)
	BEGIN
		IF rst='1' THEN 
			Cur_STATE<=S0;
		ELSIF clk_temp'event AND clk_temp='1' THEN
			Cur_STATE<=Next_STATE;
		END IF;
	END PROCESS;

	COM1:
	PROCESS(Cur_STATE) 
	BEGIN
		CASE Cur_STATE IS 
			WHEN S0=>Next_STATE<=S1;
			WHEN S1=>Next_STATE<=S2;
			WHEN S2=>Next_STATE<=S3;
			WHEN S3=>Next_STATE<=S4;
			WHEN S4=>Next_STATE<=S5;
			WHEN S5=>Next_STATE<=S6;
			WHEN S6=>Next_STATE<=S7;
			WHEN S7=>Next_STATE<=S8;
			WHEN S8=>Next_STATE<=S0;
			WHEN OTHERS =>Next_STATE<=S0;
		END CASE;
	END PROCESS COM1;
	
	COM2:
	PROCESS(Cur_STATE) 
	BEGIN
		CASE Cur_STATE IS
			WHEN S0 => led <= "11111111";
			WHEN S1 => led <= "00000000";
			WHEN S2 => led <= "11110000";
			WHEN S3 => led <= "00001111";
			WHEN S4 => led <= "10101010";
			WHEN S5 => led <= "01010101";
			WHEN S6 => led <= "11001100";
			WHEN S7 => led <= "00110011";
			WHEN S8 => led <= "11001100";
			WHEN OTHERS => led <= "11111111";
		END CASE;
	END PROCESS COM2;

end Behavioral;