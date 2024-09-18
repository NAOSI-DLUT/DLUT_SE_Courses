SELECT ename,
    sal,
    job,
    deptno
FROM emp
WHERE sal > 2500
    OR job = 'MANAGER';