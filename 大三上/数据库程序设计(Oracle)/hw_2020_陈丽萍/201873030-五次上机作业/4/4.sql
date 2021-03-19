/*
 创建一个过程, 命名为NEW_EMP, 向EMP表中插入一个新员工. 
这个过程序要调用函数VALID_DEPTID 来检查新员工的部门编号在DEPT表中是否存在。
  a.创建函数VALID_DEPTID来验证指定的 department ID. 此函数需要返回一个布尔值。

  b.创建一个过程NEW_EMP 添加一个员工到 EMP 表.如果函数返回值是真的话，EMP表中需要增加一条  新的记录。如果函数返回值是假，过程需要给用户一个恰当的提示。为参数定义默认值。佣金（comm）的默认值是0，工资（sal）的默认值是1000部门号码（deptno）的默认值是30，工作（job）的默认值是SA_REP，对于员工的ID号码，使用序列EMPLOYEES_SEQ，提供员工姓名和参加工作日期。

 c.添加一个叫Harris的员工到部门号为15 的部门，来测试过程NEW_EMP允许所有其他参数为默认，结果是什么?

 d.添加一个叫Harris的员工到部门号为10的部门，允许所有其他参数为默认，结果又是什么?
*/

--3.
--A.


CREATE OR REPLACE FUNCTION valid_deptid(deptid emp.deptno%TYPE) RETURN BOOLEAN IS
   deptnos NUMBER(3);
   BEGIN
     SELECT count(deptno) INTO deptnos FROM emp WHERE deptno=deptid;--deptno==deptid查询到对应部门，则有计数
     IF deptnos=0 THEN
         RETURN FALSE;
     ELSE
        RETURN TRUE;
    END IF;
END valid_deptid;

--B.

CREATE SEQUENCE EMPLOYEES_SEQ minvalue 8000 maxvalue 9999 START WITH 8000 INCREMENT BY 1--ID队列8000-9999

CREATE OR REPLACE PROCEDURE new_emp(
       ename emp.ename%TYPE,
			 hiredate DATE DEFAULT SYSDATE,
       comm emp.comm%TYPE DEFAULT 0,
       sal emp.sal%TYPE DEFAULT 1000,
       job emp.job%TYPE DEFAULT 'SA_REP',
       deptno emp.deptno%TYPE DEFAULT 30) IS
  BEGIN
		IF valid_deptid(deptno) THEN
			INSERT INTO emp(ename,hiredate,empno,comm,sal,job,deptno) VALUES(ename,to_date(to_char(hiredate,'yyyy-mm-dd'),'yyyy-mm-dd'),EMPLOYEES_SEQ.NEXTVAL,comm,sal,job,deptno);--对于员工的ID号码，使用序列EMPLOYEES_SEQ
		ELSE
			dbms_output.put_line('部门不存在');
		END IF;
	END;

--C.结果为：输出“部门不存在”

DECLARE  
BEGIN
 new_emp(deptno=>15,ename=>'Harris');
END;

--D.姓名为‘Harris’，部门为10，其余均为默认值。
DECLARE  
BEGIN
 new_emp(deptno=>10,ename=>'Harris');
END;

/*
1.

函数查看字符串中共包含几个某特殊字符，如'A**B*CEDF'中包含几个‘*’

2.

函数把员工表中不同的工作连接成一个字符串
3.
函数计算个人所得税，工资，薪金所得减
个人所得税计算公式：
应纳税所得额 = 工资收入金额 － 各项社会保险费 － 起征点。
应纳税额 = 应纳税所得额 x 税率 － 速算扣除数。
个税法修稿后，个人所得税的起征点调到了5000。并适用新的综合所得税率。2019.1.1新法适用级数	全年应纳税所得额	税率（%）	速算扣除数
1	不超过36000元的	3	0
2	超过36000元至144000元的部分	10	2520
3	超过144000元至300000元的部分	20	16920
4	超过300000元至420000元的部分	25	31920
*/
--1
CREATE OR REPLACE function special_char   
(c  IN VARCHAR2,v IN VARCHAR2)    --c为待查字符串，v为待查特殊字符
    RETURN  NUMBER
IS  
    s_num  NUMBER;  
BEGIN
  s_num:=length(c)-length(replace(c,v,''));--replace(原字段，'原字段旧内容','替换字段新内容')
  RETURN(s_num);  
END;  

--1测试
DECLARE 
num NUMBER;
BEGIN 
num := special_char('A**B*CEDF','*'); 
dbms_output.put_line(num);
END;

--2
CREATE OR REPLACE function all_work
return VARCHAR2
 IS
  wname VARCHAR2(100);
BEGIN
  SELECT listagg(job,',') within group(order by job)--listagg聚合列到单行，用','分割
  INTO wname
  FROM (SELECT DISTINCT job FROM emp);
  RETURN (wname);
END all_work;

--2测试

DECLARE 
wname VARCHAR(100);
BEGIN
  wname:=all_work();
  dbms_output.put_line(wname); 
END;

--3
CREATE OR REPLACE function tax(p_empno IN emp.empno%type) 
return  NUMBER IS
  t NUMBER ;
BEGIN
  SELECT sal*12+nvl(comm,0)-5000 --判断是否有comm
  INTO t
  FROM emp
  WHERE empno = p_empno;
  IF t<0 THEN
  t:=0;
  ELSIF t<30000 THEN
  t:=t*0.03;
  ELSIF t<144000 THEN
  t:=t*0.1-2520;
  ELSIF t<300000 THEN
  t:=t*0.2-16920;
  ELSIF t<420000 THEN
  t:=t*0.25-31920;
  END IF;
  RETURN(t);
END tax;

--3测试（用例king）

DECLARE 
t NUMBER;
BEGIN
t:=tax(7839);
dbms_output.put_line(t);
END;