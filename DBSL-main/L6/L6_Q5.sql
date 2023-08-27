alter table student_table add(lettergrade varchar(2));

set serveroutput on
declare
pl_gpa student_table.gpa%TYPE;
pl_rollno student_table.rollno%TYPE;
pl_grade student_table.lettergrade%TYPE;

BEGIN

FOR i in 1..5 LOOP
pl_rollno := i;

select gpa,lettergrade
into pl_gpa,pl_grade
from student_table
where rollno = pl_rollno;


IF pl_gpa>=0 AND pl_gpa<4 THEN
pl_grade := 'F';
ELSIF pl_gpa>=4 AND pl_gpa<5 THEN
pl_grade := 'E';
ELSIF pl_gpa>=5 AND pl_gpa<6 THEN
pl_grade := 'D';
ELSIF pl_gpa>=6 AND pl_gpa<7 THEN
pl_grade := 'C';
ELSIF pl_gpa>=7 AND pl_gpa<8 THEN
pl_grade := 'B';
ELSIF pl_gpa>=8 AND pl_gpa<9 THEN
pl_grade := 'A';
ELSIF pl_gpa>=9 AND pl_gpa<10 THEN
pl_grade := 'A+';
END IF;
update student_table set lettergrade = pl_grade where rollno = pl_rollno;
END LOOP;
END;
/