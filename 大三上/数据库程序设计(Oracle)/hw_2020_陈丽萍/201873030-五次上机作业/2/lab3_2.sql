--Q2
SELECT employee_id, last_name, salary,
ROUND(salary * 1.15, 0) "New Salary"
FROM employees;

--Q3
SELECT employee_id, last_name, salary,
ROUND(salary * 1.15, 0) "New Salary"
FROM employees;

--Q4
SELECT employee_id, last_name, salary,
ROUND(salary * 1.15, 0) "New Salary",
ROUND(salary * 1.15, 0) - salary "Increase"
FROM employees;

--Q5
SELECT INITCAP(last_name) "Name",LENGTH(last_name) "Length"
FROM employees
WHERE last_name LIKE 'J%'
OR last_name LIKE 'M%'
OR last_name LIKE 'A%'
ORDER BY last_name;

--Q6
SELECT last_name, ROUND(MONTHS_BETWEEN (SYSDATE, hire_date)) MONTHS_WORKED
FROM employees
ORDER BY MONTHS_BETWEEN(SYSDATE, hire_date);

--Q7
SELECT last_name || ' earns '|| TO_CHAR(salary, 'fm$99,999.00')|| ' monthly but wants '|| TO_CHAR(salary * 3, 'fm$99,999.00')|| '.' "Dream Salaries"
FROM employees;

--Q8
SELECT last_name,
LPAD(salary, 15, '$') SALARY
FROM employees;

--Q9
SELECT last_name, hire_date,TO_CHAR(NEXT_DAY(ADD_MONTHS(hire_date, 6),'星期一'),'fmDay, "the" Ddspth "of" Month, YYYY') REVIEW
FROM employees;

--Q10
SELECT last_name, hire_date,
TO_CHAR(hire_date, 'DAY') DAY
FROM employees
ORDER BY TO_CHAR(hire_date - 1, 'd');

--Q11
SELECT last_name,
NVL(TO_CHAR(commission_pct), 'No Commission') COMM
FROM employees;

--Q12
SELECT rpad(last_name, 8)||' '|| rpad(' ', salary/1000+1, '*')
EMPLOYEES_AND_THEIR_SALARIES
FROM employees
ORDER BY salary DESC;

--Q13
SELECT job_id, decode (job_id,
'ST_CLERK', 'E',
'SA_REP', 'D',
'IT_PROG', 'C',
'ST_MAN', 'B',
'AD_PRES', 'A',
'0')GRADE
FROM employees;

--Q14
SELECT job_id, CASE job_id
WHEN 'ST_CLERK' THEN 'E'
WHEN 'SA_REP' THEN 'D'
WHEN 'IT_PROG' THEN 'C'
WHEN 'ST_MAN' THEN 'B'
WHEN 'AD_PRES' THEN 'A'
ELSE '0' END GRADE
FROM employees;

/*
a.基础部分：
执行语句：
create table copy_emp 
as select * 
from emp；
下面两题使用copy_emp表
1.对名字以'A'或'S'开始的所有员工按原工资涨10%，对所有销售人员（SALESMAN）增加佣金500
2.为工作时间最长的普通员工(job为CLERK)调整工作(job调整为MANAGER)
*/
--Q1
BEGIN
update copy_emp
  set salary=salary+0.1*salary
    where last_name like 'A%'
    or last_name like 'S%';
update copy_emp
   set salary=salary+500
   where job_id='SA_MAN';
END;
--Q1
DECLARE CURSOR s2 IS
SELECT *
FROM copy_emp
WHERE (
        first_name LIKE 'A%'
        OR first_name LIKE 'S%'
    );
v_res copy_emp %ROWTYPE;
BEGIN OPEN s2;
FETCH s2 INTO v_res;
LOOP EXIT WHEN s2 % NOTFOUND;
  UPDATE copy_emp
  SET salary = salary * 0.1 + salary
  WHERE v_res.first_name = first_name;
  FETCH s2 INTO v_res;
END LOOP;
CLOSE s2;
END;

--Q2 mark
UPDATE copy_emp
SET job_id = 'MANAGER'
WHERE months_between(SYSDATE, hire_date) IN (
        SELECT max(months_between(SYSDATE, hire_date))
        FROM copy_emp
    )

/*
b.控制结构
1.
输入4位整数，判断是否是闰年
2.
定义员工号码，从emp表中获得工资，
     如果工资小于1000,'POOR',
         大于等于1000小于2000,'MEDIUM',
         大于等于2000小于3000  ,'GOOD',
         大于等于3000小于4000  ,'VERY GOOD',
         否则,'EXCELLENT' 
*/
--Q1
DECLARE
  years NUMBER;
BEGIN
  years:=&year;
  IF (years/100)=ROUND(years/100) THEN
    IF (years/4)=ROUND(years/4) THEN
      dbms_output.put_line(years||'年是闰年');
      ELSE
        dbms_output.put_line(years||'年不是闰年');
    END IF;
  ELSE IF (years/4)=ROUND(years/4) THEN
    dbms_output.put_line(years||'年是闰年');
    ELSE
        dbms_output.put_line(years||'年不是闰年');
    END IF;
    END IF;
END;

--Q2
DECLARE
p_empno emp.empno%TYPE;
p_sal emp.sal%TYPE;
begin
  p_empno:=&empno;
  select FLOOR(sal)
    into p_sal
    from emp
   where p_empno=empno;
  case p_sal
    when 0 then dbms_output.put_line('POOR');
    when 1 then dbms_output.put_line('MEDIUM');
    when 2 then dbms_output.put_line('GOOD');
    when 3 then dbms_output.put_line('VERY GOOD');
    else dbms_output.put_line('EXCELLENT');
  end;
end;
--
DECLARE
p_empno emp.empno%TYPE;
p_sal emp.sal%TYPE;
begin
  p_empno:=&empno;
  select sal
    into p_sal
    from emp
   where p_empno=empno;
  case
    when  p_sal BETWEEN 0 AND 1000 then dbms_output.put_line('POOR');
    when  p_sal BETWEEN 1000 AND 2000 then dbms_output.put_line('MEDIUM');
    when  p_sal BETWEEN 2000 AND 3000 then dbms_output.put_line('GOOD');
    when  p_sal BETWEEN 3000 AND 4000 then dbms_output.put_line('VERY GOOD');
    else dbms_output.put_line('EXCELLENT');
  end case;
end;
--Q2
DECLARE
  empnos NUMBER;
  emp_sal emp.sal%TYPE;
BEGIN
  empnos:=&empnos;
  SELECT salary INTO emp_sal FROM employees WHERE employee_id=empnos;
  IF emp_sal<1000 THEN
    dbms_output.put_line('POOR');
  ELSE IF emp_sal BETWEEN 1000 AND 2000 THEN
    dbms_output.put_line('MEDIUM');
  ELSE IF emp_sal BETWEEN 2000 AND 3000 THEN
    dbms_output.put_line('GOOD');
  ELSE IF emp_sal BETWEEN 3000 AND 4000 THEN
    dbms_output.put_line('VERY GOOD');
  ELSE 
    dbms_output.put_line('EXCELLENT');
    END IF;
    END IF;
    END IF;
    END IF;
END;