ALTER TABLE ly.ly_emp
    RENAME COLUMN empjob TO job;
ALTER TABLE ly.ly_dept
ADD dleader varchar(30);
ALTER TABLE ly.ly_dept DROP COLUMN dleader;