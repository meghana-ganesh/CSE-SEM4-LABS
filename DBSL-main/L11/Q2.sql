create table  Old_Data_Instructor(ID varchar(5), name varchar(20), dept_name varchar(20), salary numeric(8,2)); 
SET SERVEROUTPUT ON
create or replace trigger q2
after
	update
on instructor
for each ROW
BEGIN
insert into Old_Data_Instructor values(:old.ID,:old.name,:old.dept_name,:old.salary);
end;
/ 