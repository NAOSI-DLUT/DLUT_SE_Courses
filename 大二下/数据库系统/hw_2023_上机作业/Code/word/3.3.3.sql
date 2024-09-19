SELECT deptno,
  AVG(total) AS average,
  MAX(total) AS max
FROM emp
GROUP BY deptno
HAVING average < 2500;