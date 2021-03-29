/*
a.游标：
1.

使用游标获取部门表（dept）中的部门号deptno，部门名，传递部门号到游标中，获取在此部门中工作的员工姓名，工作，参加工作时间，工资。
如
部门号   10                 部门名ACCOUNTING

张三      SALES     1999.1.1               3000

....

2.
对员工表中所有员工的姓名做如下处理：姓名的首字母在'A'到'G' 之间，合并为第一个字符串，在'H'到'O'之间，合并为第二个字符串，在'P'到'Z'之间，合并为第三个字符串，姓名之间用空格相隔。

3.
定义代表部门号的两个变量，屏幕上输出这两个部门的所有员工姓名与工资（这两个变量作为游标的参数）

4.

游标处理中使用for update和where current of在表中修改字段stars的值，sal字段中每一个1000，一个‘*’，如sal为3800，四舍五入，stars打印4个'*'
建表语句如下：
CREATE TABLE copy_emp  as select * from emp;
alter table copy_emp add stars varchar2(20);
*/

--1.
DECLARE CURSOR emp_dept_cursor IS
SELECT d.deptno,
    d.dname,
    e.ename,
    e.job,
    e.hiredate,
    e.sal
FROM dept d,
    emp e
WHERE d.deptno = e.deptno;

BEGIN 
for rec in emp_dept_cursor loop
dbms_output.put_line('部门号:' || rec.deptno || '    部门名:' || rec.dname);
dbms_output.put_line(
    rec.ename || '    ' || rec.job || '    ' || to_char(rec.hiredate, 'yyyy-mm-dd') || rec.sal
);
dbms_output.put_line(' ');
END LOOP;
END;

--1.
DECLARE CURSOR emp_dept_cursor IS
SELECT d.deptno,
    d.dname,
    e.ename,
    e.job,
    e.hiredate,
    e.sal
FROM dept d,
    emp e
WHERE d.deptno = e.deptno;
v_deptno dept.deptno %TYPE;
v_dname dept.dname %TYPE;
v_ename emp.ename %TYPE;
v_job emp.job %TYPE;
v_hiredate emp.hiredate %TYPE;
v_sal emp.sal %TYPE;
BEGIN IF NOT emp_dept_cursor %ISOPEN THEN OPEN emp_dept_cursor;
END IF;
LOOP FETCH emp_dept_cursor INTO v_deptno,
v_dname,
v_ename,
v_job,
v_hiredate,
v_sal;
EXIT
WHEN emp_dept_cursor %NOTFOUND;
dbms_output.put_line('部门号:' || v_deptno || '    部门名:' || v_dname);
dbms_output.put_line(
    v_ename || '    ' || v_job || '    ' || to_char(v_hiredate, 'yyyy-mm-dd') || v_sal
);
dbms_output.put_line(' ');
END LOOP;
CLOSE emp_dept_cursor;
END;
--2.(sp)
DECLARE
str1 string(100);
str2 string(100);
str3 string(100);
CURSOR NAME_AG IS
SELECT ENAME FROM EMP WHERE substr(ENAME,0,1) BETWEEN 'A' AND 'G';
name1 emp.ENAME%TYPE;
CURSOR NAME_HO IS
SELECT ENAME FROM EMP WHERE substr(ENAME,0,1) BETWEEN 'H' AND 'O';
name2 emp.ENAME%TYPE;
CURSOR NAME_PZ IS
SELECT ENAME FROM EMP WHERE substr(ENAME,0,1) BETWEEN 'P' AND 'Z';
name3 emp.ENAME%TYPE;
BEGIN
	for rec in name_ag loop
	str1:=str1||rec.ename||' ';--rec.name不可避
	end loop;
	for rec in name_ho loop
	str2:=str2||rec.ename||' ';
	end loop;
	for rec in name_pz loop
	str3:=str3||rec.ename||' ';
	end loop;
	dbms_output.put_line(str1);
	dbms_output.put_line(str2);
	dbms_output.put_line(str3);
END;

--2.
DECLARE
str1 string(100);
str2 string(100);
str3 string(100);
CURSOR NAME_AG IS
SELECT ENAME FROM EMP WHERE substr(ENAME,0,1) BETWEEN 'A' AND 'G';
name1 emp.ENAME%TYPE;
CURSOR NAME_HO IS
SELECT ENAME FROM EMP WHERE substr(ENAME,0,1) BETWEEN 'H' AND 'O';
name2 emp.ENAME%TYPE;
CURSOR NAME_PZ IS
SELECT ENAME FROM EMP WHERE substr(ENAME,0,1) BETWEEN 'P' AND 'Z';
name3 emp.ENAME%TYPE;
BEGIN
OPEN NAME_AG;
OPEN NAME_HO;
OPEN NAME_PZ;

LOOP
    FETCH NAME_AG INTO name1;
    EXIT WHEN NAME_AG%NOTFOUND;
    str1:=str1||name1||' ';
END LOOP;
LOOP
    FETCH NAME_HO INTO name2;
    EXIT WHEN NAME_HO%NOTFOUND;
    str2:=str2||name2||' ';
END LOOP;
LOOP
    FETCH NAME_PZ INTO name3;
    EXIT WHEN NAME_PZ%NOTFOUND;
    str3:=str3||name3||' ';
END LOOP;
dbms_output.put_line(str1);
dbms_output.put_line(str2);
dbms_output.put_line(str3);
END;

--3.
declare 
  cursor testcur(deptno1 emp.deptno%type,deptno2 emp.deptno%type) is
  select ename,sal 
  from emp
  where deptno=deptno1 or deptno=deptno2;
begin
  for rec in testcur(30,30) loop
    dbms_output.put_line('Name:'||rec.ename||' sal:'||rec.sal);
  end loop;
end;

--3.
 DECLARE
   CURSOR emp_cursor(v_deptno1 NUMBER DEFAULT 30,v_deptno2 NUMBER DEFAULT 30) IS
          SELECT ename,sal FROM emp WHERE deptno=v_deptno1 OR deptno=v_deptno2;
   
   v_ename emp.ename%TYPE;
	 v_sal emp.sal%TYPE;
 BEGIN  
   OPEN emp_cursor(v_deptno1=>&deptno1,v_deptno2=>&deptno2);
   LOOP
     FETCH emp_cursor INTO v_ename,v_sal;
     EXIT WHEN emp_cursor%NOTFOUND;
     dbms_output.put_line('员工姓名:'||v_ename||'    员工工资:'||v_sal);
   END LOOP;
   CLOSE emp_cursor;
 END;

--4.
CREATE TABLE copy_emp  as select * from emp;
alter table copy_emp add starts varchar(20);
DECLARE
  CURSOR sal_emp IS
         SELECT sal FROM copy_emp FOR UPDATE NOWAIT;
  v_sal copy_emp.sal%TYPE;
BEGIN
  IF NOT sal_emp%ISOPEN THEN     
      OPEN sal_emp;
  END IF;
  LOOP
    FETCH sal_emp INTO v_sal;
		EXIT WHEN sal_emp%NOTFOUND;
		dbms_output.put_line(ROUND(v_sal/1000));
		UPDATE copy_emp SET starts=LPAD(' ',ROUND(v_sal/1000)+1,'*') 
		WHERE CURRENT OF sal_emp; 
    END LOOP;
END;

/*
b.过程：

1. 
特殊员工加薪10%后，如果该员工参加工作时间超过5年，额外加薪3000,根据输入的员工号，输出加薪后的员工工资

2. 
检查员工工资是否在有效的范围内，不同工作的工资范围为：
CLERK            1500-2500
SALES            2501-3500
ANALYST          3501-4500
MANAGER          4500以上
如果工资在此范围内，输出工资正常，否则输出工资太低，并且更新工资为该范围内的最低工资 
*/

--1.

CREATE OR REPLACE PROCEDURE add_sal IS
BEGIN
	UPDATE copy_emp_2 SET sal=sal*1.1;
	UPDATE copy_emp_2 SET sal=sal+3000 WHERE months_between(SYSDATE,hiredate)>60;
	COMMIT;
END add_sal;
 
DECLARE
BEGIN
    add_sal;
END;


--2.
CREATE OR REPLACE PROCEDURE check_sal(names copy_emp_2.ename%TYPE,sal copy_emp_2.sal%TYPE,job emp.job%TYPE) IS
BEGIN
	IF job='CLERK' THEN
		IF sal BETWEEN 1500 AND 2500 THEN
			dbms_output.put_line(names||'工资正常');
		ELSE IF sal< 1500 THEN
			dbms_output.put_line(names||'工资太低');	
		ELSE 
			dbms_output.put_line(names||'工资太高');	
		END IF;
		END IF;
	END IF;
	IF job='SALES' THEN
		IF sal BETWEEN 2501 AND 3500 THEN
			dbms_output.put_line(names||'工资正常');
		ELSE IF sal< 2501 THEN
			dbms_output.put_line(names||'工资太低');	
		ELSE 
			dbms_output.put_line(names||'工资太高');	
		END IF;
		END IF;
	END IF;
	IF job='ANALYST' THEN
		IF sal BETWEEN 3501 AND 4500 THEN
			dbms_output.put_line(names||'工资正常');
		ELSE IF sal< 3501 THEN
			dbms_output.put_line(names||'工资太低');	
		ELSE 
			dbms_output.put_line(names||'工资太高');
		END IF;
		END IF;
	END IF;
	IF job='MANAGER' THEN
		IF sal >4500 THEN
			dbms_output.put_line(names||'工资正常');
		ELSE  
			dbms_output.put_line(names||'工资太低');
		END IF;
	END IF;
END check_sal;
 
DECLARE
    CURSOR emp_cursor IS
		       SELECT ename,sal,job FROM copy_emp_2;
		v_name copy_emp_2.ename%TYPE;
		v_sal  copy_emp_2.sal%TYPE;
		v_job copy_emp_2.job%TYPE;
BEGIN
	OPEN emp_cursor;
	LOOP
		FETCH emp_cursor INTO v_name,v_sal,v_job;
		EXIT WHEN emp_cursor%NOTFOUND;
		check_sal(v_name,v_sal,v_job);
	END LOOP;
END;