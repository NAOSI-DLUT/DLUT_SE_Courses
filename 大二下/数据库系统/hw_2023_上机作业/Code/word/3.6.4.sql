SELECT dname
FROM dept
WHERE NOT EXISTS(
                SELECT job
                FROM emp
                GROUP BY job
                HAVING MAX(sal) > 2000
                        AND MIN(sal) < 5000
                EXCEPT
                SELECT job
                FROM emp
                WHERE emp.deptno = dept.deptno
        );