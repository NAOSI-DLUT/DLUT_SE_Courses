----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    09:25:32 03/31/2014 
-- Design Name: 
-- Module Name:    TestVHDL - Behavioral 
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

entity TestVHDL is
    Port ( key1 : in  STD_LOGIC;
           key2 : in  STD_LOGIC;
           key3 : in  STD_LOGIC;
           key4 : in  STD_LOGIC;
           key5 : in  STD_LOGIC;
           key6 : in  STD_LOGIC;
			  key7:  in  STD_LOGIC;
			  key8:  in  STD_LOGIC;
           led1 : out  STD_LOGIC;
           led2 : out  STD_LOGIC;
           led3 : out  STD_LOGIC;
           led4 : out  STD_LOGIC;
           led5 : out  STD_LOGIC;
           led6 : out  STD_LOGIC;
			  led7 : out  STD_LOGIC;
			  led8 : out  STD_LOGIC);
end TestVHDL;

architecture Behavioral of TestVHDL is

begin
    led1<=key1;
	 led2<=key2;
	 led3<=key3;
	 led4<=key4;
	 led5<=key5;
	 led6<=key6;
	 led7<=key7;
	 led8<=key8;

end Behavioral;

