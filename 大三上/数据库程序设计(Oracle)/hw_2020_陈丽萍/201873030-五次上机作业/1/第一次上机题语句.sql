--第一章上机题

--9.
SELECT DISTINCT job_id
FROM employees;

--11.
SELECT last_name||', '||job_id "Employee and Title"
FROM employees;

--12.
SELECT employee_id || ',' || first_name || ',' || last_name || ',' || email || ',' || phone_number || ','|| job_id || ',' || manager_id || ',' || hire_date || ',' ||salary || ',' || commission_pct || ',' || department_id THE_OUTPUT
FROM employees;

--第二章: 4,8,11,12
--4.
SELECT last_name, job_id, hire_date
FROM employees
WHERE hire_date BETWEEN to_date('1998/02/20','yyyy-mm-dd') AND to_date('1998/05/01','yyyy-mm-dd')
ORDER BY hire_date;
--注：题目日期太老了，数据库内表的时间不在范围内

--8.
SELECT last_name, job_id
FROM employees
WHERE manager_id IS NULL;

--11.
SELECT last_name
FROM employees
WHERE last_name LIKE '%a%' AND last_name LIKE '%e%';

--12.
SELECT last_name, job_id, salary
FROM employees
WHERE job_id IN ('SA_REP', 'ST_CLERK') AND salary NOT IN (2500, 3500, 7000);

--第四章: 2,5,10,11
--2.
SELECT DISTINCT job_id, location_id
FROM employees, departments
WHERE employees.department_id = departments.department_id AND employees.department_id = 80;

--5.
SELECT e.last_name, e.job_id, e.department_id, d.department_name
FROM employees e JOIN departments d
ON (e.department_id = d.department_id)
JOIN locations l
ON (d.location_id = l.location_id)
WHERE LOWER(l.city) = 'toronto';

--10.
SELECT e.last_name, e.hire_date
FROM employees e, employees davies
WHERE davies.last_name = 'Davies'
AND davies.hire_date < e.hire_date

--11.
SELECT w.last_name "Employee", w.hire_date "Emp Hired", m.last_name "Manager", m.hire_date "Mgr Hired"
FROM employees w, employees m
WHERE w.manager_id = m.employee_id
AND w.hire_date < m.hire_date;

--第五章: 6,7,9,10,11,12
--6.
SELECT job_id, COUNT(*)
FROM employees
GROUP BY job_id;

--7.
SELECT COUNT(DISTINCT manager_id) "Number of Managers"
FROM employees;

--9.
SELECT manager_id, MIN(salary)
FROM employees
WHERE manager_id IS NOT NULL
GROUP BY manager_id
HAVING MIN(salary) > 6000
ORDER BY MIN(salary) DESC;

--10.
SELECT d.department_name "Name", d.location_id "Location ",
COUNT(*) "Number of People",
ROUND(AVG(salary),2) "Salary"
FROM employees e, departments d
WHERE e.department_id = d.department_id
GROUP BY d.department_name, d.location_id;

--11.
SELECT COUNT(*) total,
SUM(DECODE(TO_CHAR(hire_date, 'YYYY'),1995,1,0))"1995",
SUM(DECODE(TO_CHAR(hire_date, 'YYYY'),1996,1,0))"1996",
SUM(DECODE(TO_CHAR(hire_date, 'YYYY'),1997,1,0))"1997",
SUM(DECODE(TO_CHAR(hire_date, 'YYYY'),1998,1,0))"1998"
FROM employees;


--12.
SELECT job_id "Job",
SUM(DECODE(department_id , 20, salary)) "Dept 20",
SUM(DECODE(department_id , 50, salary)) "Dept 50",
SUM(DECODE(department_id , 80, salary)) "Dept 80",
SUM(DECODE(department_id , 90, salary)) "Dept 90",
SUM(salary) "Total"
FROM employees
GROUP BY job_id;

--第六章: 4,5,6,7
--4.
SELECT last_name, department_id, job_id
FROM employees
WHERE department_id IN 
(SELECT department_id
FROM departments
WHERE location_id = 1700);

--5.
SELECT last_name, salary
FROM employees
WHERE manager_id = (SELECT employee_id
FROM employees
WHERE last_name = 'King');

--6.
SELECT department_id, last_name, job_id
FROM employees
WHERE department_id IN (SELECT department_id
FROM departments
WHERE department_name = 'Executive');

--7.
SELECT employee_id, last_name, salary
FROM employees
WHERE department_id IN (SELECT department_id
FROM employees
WHERE last_name like '%u%')
AND salary > (SELECT AVG(salary)
FROM employees);