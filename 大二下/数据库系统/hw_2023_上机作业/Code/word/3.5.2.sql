--不相关子查询
SELECT ename,
    sal
FROM emp
    JOIN (
        SELECT losal,
            hisal,
            grade
        FROM salgrade
        WHERE grade = 2
    ) AS sg ON sal BETWEEN sg.losal AND sg.hisal;
--相关子查询
SELECT ename,
    sal
FROM emp
WHERE (
        SELECT grade
        FROM salgrade
        WHERE sal BETWEEN losal AND hisal
    ) = 2;