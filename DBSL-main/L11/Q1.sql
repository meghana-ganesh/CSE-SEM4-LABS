create table log_change_takes (time_of_change date, ID varchar(5), course_id varchar(8),sec_id varchar(8),
semester varchar(6), year number(4), grade varchar(2));
SET SERVEROUTPUT ON

create or replace trigger takes_update_trigger
before 
	UPDATE
on takes
for each ROW
BEGIN
insert into log_change_takes values(CURRENT_TIMESTAMP,:old.ID,:old.course_id,:old.sec_id, 
:old.semester,:old.year,:old.grade);
end;
/