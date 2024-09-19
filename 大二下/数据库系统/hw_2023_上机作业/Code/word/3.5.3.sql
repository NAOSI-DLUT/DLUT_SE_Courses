SELECT ename,
    job,
    sal,
    deptno
from emp
WHERE job IN (
        SELECT job
        FROM emp
        WHERE deptno = 10
    );