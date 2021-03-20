/*
1.创建并调用一个包，其中包含私有和公有的结构.
a.创建一个包，命名为EMP_PACK 它里面有公有的过程NEW_EMP 和私有的函数VALID_DEPTID (练习3中)
b.调用过程NEW_EMP, 将department number赋值为15 .如果DEPT表中没有department ID是15的值应该在存储过程中使用一个异常将错误其捕获
c.调用过程NEW_EMP,将一个存在的值10赋值给department ID.
2. 创建一个包CHK_PACK，它里面有过程CHK_HIREDATE和CHK_DEPT_MGR.
两个过程都是公有的（public）. 
过程CHK_HIREDATE用来检查一个员工的雇佣日期是否在下面的范围内：
     [SYSDATE - 50 years, SYSDATE + 3 months].
注意:
    如果日期无效, 你需要用一个恰当的信息提示为什么这个日期值是无效的
    确保在日期值中的时间组件是被忽略的（日期值中没有小时、分和秒）
    定义一个常量作为50年界限
    如果雇佣日期是一个空值,那它就是一个无效的日期。
过程CHK_DEPT_MGR用来检查某一员工的部门和经理信息
过程CHK_DEPT_MGR 接受参数员工编号（empno）和经理编号（mgr）.
过程要检查经理和员工是否在一个部门工作

*/
--1a
create or replace package emp_pack
as 
procedure new_emp
(
p_ename emp.ename%type,
p_hiredate date default sysdate,
p_comm emp.comm%type default 0,
p_sal emp.sal%type default 1000,
p_job emp.job%type default 'SA_REP',
p_deptno emp.deptno%type default 30) ;
end emp_pack;


create or replace package body  emp_pack as 
  function valid_deptid(deptid in emp.deptno%type) return boolean
  as
  d_count number(3);
  BEGIN 
    SELECT count(deptno) INTO d_count FROM dept WHERE DEPTNO =deptid;
    IF d_count=0 THEN
      RETURN FALSE  ;
    ELSE 
      RETURN TRUE ;
    END IF ;
  END VALID_DEPTID;
  
  procedure new_emp
(
p_ename emp.ename%type,
p_hiredate date default sysdate,
p_comm emp.comm%type default 0,
p_sal emp.sal%type default 1000,
p_job emp.job%type default 'SA_REP',
p_deptno emp.deptno%type default 30) 
is
begin
    if valid_deptid(p_deptno) then
      insert into emp(ename,hiredate,empno,comm,sal,job,deptno) values(p_ename,to_date(to_char(p_hiredate,'yyyy-mm-dd'),'yyyy-mm-dd'),employees_seq.nextval,p_comm,p_sal,p_job,p_deptno);
    else
      dbms_output.put_line('部门不存在');
    end if;
exception
  when others then
      dbms_output.put_line(sqlerrm);
end new_emp;
end;

--b

declare
begin 
  emp_pack.new_emp(p_deptno=>15,p_ename => 'test1');
exception
  when others
    then dbms_output.put_line(sqlerrm);
end;

--c
declare
begin
  emp_pack.new_emp(p_deptno=>10,p_ename => 'test2');
exception
  when others
    then dbms_output.put_line(sqlerrm);
end;

--2
create or replace package chk_pack
is
  procedure chk_hiredate
  (p_empno emp.empno%type);
  procedure chk_dept_mgr
  (p_empno emp.empno%type,
   p_mgr emp.mgr%type);
end chk_pack;

create or replace package body chk_pack
is
  procedure chk_hiredate
  (p_empno emp.empno%type)
  is
  v_hiredate emp.hiredate%type;
  begin
    select hiredate into v_hiredate
    from emp
    where empno=p_empno;
    if v_hiredate is null then
      dbms_output.put_line('日期无效，因为雇佣日期为空值');
    elsif v_hiredate between add_months(trunc(sysdate),-600) and add_months(trunc(sysdate),3) then
      dbms_output.put_line('日期有效');
    else
      dbms_output.put_line('日期无效，因为雇佣日期不在要求区间中');
    end if;
  end;
  
  procedure chk_dept_mgr
  (p_empno emp.empno%type,
   p_mgr emp.mgr%type)
  is
  v_empdeptno emp.empno%type;
  v_mgrdeptno emp.empno%type;
  begin
    select deptno into v_empdeptno
    from emp
    where empno=p_empno;
    select deptno into v_mgrdeptno
    from emp
    where empno=p_mgr;
    if v_empdeptno=v_mgrdeptno then
      dbms_output.put_line('经理和员工在一个部门工作');
    else
      dbms_output.put_line('经理和员工不在一个部门工作');
    end if;
  end;
end chk_pack;

--测试chk_hiredate
select * from emp;
declare
begin
  chk_pack.chk_hiredate(7369);
   exception 
      when others then dbms_output.put_line(sqlerrm);
 end;
 --测试chk_dept_mgr
 
declare
begin
  chk_pack.chk_dept_mgr(7369,7698);
   exception 
      when others then dbms_output.put_line(sqlerrm);
 end;



/*
触发器：

1.

编写触发器实现如下功能：

对修改职工工资进行合法性检查：

a.修改后的工资大于修改前的工资

b.工资增量不能超过原工资的10%

c.目前部门号为10号部门的员工不涨工资
*/

create or replace trigger tr1
after
update of sal on empfor each rowbegin if :new.sal <= :old.sal then raise_application_error(-20001, '修改后的薪金要大于修改前的薪金');
elsif :new.sal > :old.sal * 1.1 then raise_application_error(-20002, '工资增量不能超过原工资的10%');
elsif :old.deptno is null then raise_application_error(-20003, '没有单位的职工不能涨工资');
end if;
end;

/*
Produce a report showing an organization chart for Mourgos’s department. Print last names, salaries,
and department IDs.

Create a report that shows the hierarchy of the managers for the employee Lorentz. Display his
immediate manager first.
*/
/*SQL部分*/
--1
select * from employees;
select * from employees where last_name='Mourgos';
select last_name,salary,department_id
from employees
start with last_name='Mourgos'
connect by prior employee_id=manager_id;
--2
select last_name,employee_id,manager_id,department_id
from employees
start with last_name='Lorentz'
connect by prior manager_id=employee_id;