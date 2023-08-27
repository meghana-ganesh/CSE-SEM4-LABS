set serveroutput on
declare
pl_gpa student_table.gpa%TYPE;
pl_rollno student_table.rollno%TYPE;

BEGIN
pl_rollno := '&rollno';

select gpa
into pl_gpa
from student_table
where rollno = pl_rollno;
DBMS_OUTPUT.PUT_LINE('GRADE:');
IF pl_gpa>=0 AND pl_gpa<4 THEN
DBMS_OUTPUT.PUT_LINE('F');
ELSIF pl_gpa>=4 AND pl_gpa<5 THEN
DBMS_OUTPUT.PUT_LINE('E');
ELSIF pl_gpa>=5 AND pl_gpa<6 THEN
DBMS_OUTPUT.PUT_LINE('D');
ELSIF pl_gpa>=6 AND pl_gpa<7 THEN
DBMS_OUTPUT.PUT_LINE('C');
ELSIF pl_gpa>=7 AND pl_gpa<8 THEN
DBMS_OUTPUT.PUT_LINE('B');
ELSIF pl_gpa>=8 AND pl_gpa<9 THEN
DBMS_OUTPUT.PUT_LINE('A');
ELSIF pl_gpa>=9 AND pl_gpa<10 THEN
DBMS_OUTPUT.PUT_LINE('A+');
END IF;

END;
/




