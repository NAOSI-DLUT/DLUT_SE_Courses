SELECT DISTINCT student.name,
    instructor.name
FROM student
    JOIN takes ON student.id = takes.id
    JOIN teaches ON takes.course_id = teaches.course_id
    AND takes.sec_id = teaches.sec_id
    AND takes.semester = teaches.semester
    AND takes.year = teaches.year
    JOIN instructor ON teaches.id = instructor.id
    JOIN advisor ON advisor.s_id = student.id
    AND advisor.i_id = instructor.id;