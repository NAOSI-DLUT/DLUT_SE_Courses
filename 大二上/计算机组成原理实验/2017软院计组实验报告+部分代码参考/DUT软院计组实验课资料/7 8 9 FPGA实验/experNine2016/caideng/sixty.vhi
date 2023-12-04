
-- VHDL Instantiation Created from source file sixty.vhd -- 18:02:33 01/03/2018
--
-- Notes: 
-- 1) This instantiation template has been automatically generated using types
-- std_logic and std_logic_vector for the ports of the instantiated module
-- 2) To use this template to instantiate this entity, cut-and-paste and then edit

	COMPONENT sixty
	PORT(
		clk : IN std_logic;
		rst : IN std_logic;          
		ledH : OUT std_logic_vector(3 downto 0);
		ledL : OUT std_logic_vector(3 downto 0)
		);
	END COMPONENT;

	Inst_sixty: sixty PORT MAP(
		clk => ,
		rst => ,
		ledH => ,
		ledL => 
	);


