set serveroutput on 
create or replace procedure list_details(dname varchar) IS
pl_dname varchar(20);
cursor c(pl_name instructor.name%TYPE) is select name from instructor where dept_name = pl_dname;
BEGIN
pl_dname := dname;
for i in c(pl_dname) LOOP
dbms_output.put_line(i.name);
end loop;
end;
/
