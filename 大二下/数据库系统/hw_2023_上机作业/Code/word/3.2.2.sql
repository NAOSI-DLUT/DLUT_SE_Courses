ALTER TABLE emp
ADD COLUMN total FLOAT;
UPDATE emp
SET total = sal + nvl(comm, 0);
SELECT ename,
    total
FROM emp;