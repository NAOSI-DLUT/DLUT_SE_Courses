----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    13:34:37 11/05/2014 
-- Design Name: 
-- Module Name:    sixty - Behavioral 
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

entity sixty is
PORT(
		clk : IN STD_LOGIC;           --实验箱时钟信号	
		rst : IN STD_LOGIC;           --实验箱复位信号
		ledH : OUT STD_LOGIC_VECTOR(3 downto 0);  --高位输出变量
		ledL:OUT STD_LOGIC_VECTOR(3 downto 0)     --低位输出变量
		
	);
end sixty;

architecture Behavioral of sixty is
SIGNAL clk_temp : std_logic; --分频后的时钟	
SIGNAL count : std_logic_vector(15 downto 0);   --分频计数变量
SIGNAL countH : STD_LOGIC_VECTOR(3 DOWNTO 0);   --高位变量
SIGNAL countL : STD_LOGIC_VECTOR(3 DOWNTO 0);   --低位变量
begin

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
			                  --
                              --
		ELSIF clk_temp'event AND clk_temp='1' THEN
			                                      --
			IF countL="1001" then countL <= (OTHERS =>'0');
											               --
											if countH="0101"then countH<= (OTHERS =>'0');
											end if;
			end IF;
			
		END IF;
		ledH<=countH;
		ledL<=countL;
		
		
		
	END PROCESS;
end Behavioral;

