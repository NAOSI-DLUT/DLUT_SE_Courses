SELECT dept.dname,
    dept.loc
FROM dept
WHERE deptno IN (
        SELECT deptno
        FROM emp
        WHERE (
                SELECT grade
                FROM salgrade
                WHERE sal BETWEEN losal AND hisal
            ) = 4
    );