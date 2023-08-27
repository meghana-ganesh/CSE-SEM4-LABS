drop table users;
drop table department;
drop table manages;
drop table professor;
drop table student;
drop table course;
drop table prerequisite;
drop table classroom;
drop table grade;
drop table teaches;
drop table takes;
drop table addresses;


create table users(user_id number(5) PRIMARY KEY,
                    username varchar(20) UNIQUE NOT NULL,
                    password_hash varchar(50) NOT NULL,
                    role_name varchar(20) NOT NULL 
                    );




create table department(dno number(5) PRIMARY KEY,
                        dname varchar(20),
                        bldg varchar(10),
                        budget numeric(5,2));

create table professor(professor_id number(5) PRIMARY KEY,
                        name varchar(20) NOT NULL,
                        email varchar(40) UNIQUE,
                        ph_number number(10) UNIQUE,
                        post varchar(10),
                        dno number(5),
                        CONSTRAINT professor_id_fk FOREIGN KEY(dno) REFERENCES department(dno)
                    );


CREATE TABLE student (stu_id number(5) PRIMARY KEY,
                        name VARCHAR(20) NOT NULL,
                        email VARCHAR(50) NOT NULL,
                        phno VARCHAR(20) NOT NULL,
                        address VARCHAR(255) NOT NULL,
                        DOB DATE NOT NULL,
                        DOJ DATE NOT NULL,
                        dno number(5) NOT NULL,
                        CONSTRAINT dno_fk FOREIGN KEY (dno) REFERENCES department (dno),
                    );

create table course(course_id varchar(5) PRIMARY KEY,
                    course_name varchar(50) NOT NULL,
                    course_description varchar(100),
                    course_start_date date NOT NULL,
                    course_end_date date NOT NULL,
                    course_fee numeric(5,2) NOT NULL
                    );

create table prerequisite(prerequisite_id number(10),
                            course_id varchar(10),
                            prerequisite_name varchar(50) NOT NULL,
                            CONSTRAINT prereq_pk PRIMARY KEY(prerequisite_id,course_id),
                            CONSTRAINT course_id_fk FOREIGN KEY(course_id) REFERENCES course(course_id)
                    );
CREATE TABLE classroom (professor_id number(5) NOT NULL,
                        stu_id number(5) NOT NULL,
                        course_id varchar(5) NOT NULL,
                        semester number(1) NOT NULL,
                        year date,
                        section VARCHAR(1) NOT NULL check(section in('A','B','C','D')),
                        room VARCHAR(10) NOT NULL,
                        CONSTRAINT class_pk PRIMARY KEY (professor_id, stu_id, course_id, semester, year, section, room),
                        CONSTRAINT class_fk FOREIGN KEY (professor_id) REFERENCES professor(professor_id),
                        CONSTRAINT class_fk1 FOREIGN KEY(stu_id) REFERENCES student(stu_id),
                        CONSTRAINT class_fk2 FOREIGN KEY (course_id) REFERENCES course(course_id)
                    );

create table grade(stu_id number(5),
                    course_id varchar(10),
                    semester number(1),
                    year date,
                    section VARCHAR(1) NOT NULL,
                    room VARCHAR(10) NOT NULL,
                    scorecard_id number(5),
                    grade varchar(2) check(grade in ('A+','A','B','C','D','E','F')),
                    pass_fail VARCHAR(10) NOT NULL,
                    CONSTRAINT grade_pk PRIMARY KEY(stu_id,course_id,semester,year,section,room,scorecard_id),
                    CONSTRAINT grade_fk FOREIGN KEY(semester,year,section,room) REFERENCES classroom(semester,year,section,room),
                    CONSTRAINT grade_fk1 FOREIGN KEY(stu_id) REFERENCES student(stu_id),
                    CONSTRAINT grade_fk2 FOREIGN KEY(course_id) REFERENCES course(course_id)
                    );

CREATE TABLE takes (
    stu_id number(5) NOT NULL,
    course_id varchar(5) NOT NULL,
    CONSTRAINT takes_pk PRIMARY KEY (stu_id, course_id),
    CONSTRAINT takes_fk FOREIGN KEY (stu_id) REFERENCES student(stu_id),
    CONSTRAINT takes_fk1 FOREIGN KEY (course_id) REFERENCES course(course_id)
);

CREATE TABLE teaches (
    professor_id number(5) NOT NULL,
    course_id varchar(5) NOT NULL,
    CONSTRAINT teaches_pk PRIMARY KEY (professor_id, course_id),
    FOREIGN KEY (professor_id) REFERENCES professor(professor_id),
    FOREIGN KEY (course_id) REFERENCES course(course_id)
);

CREATE TABLE addresses (
professor_id number(5) NOT NULL,
semester VARCHAR(10) NOT NULL,
year date NOT NULL,
section VARCHAR(1) NOT NULL ,
room VARCHAR(10) NOT NULL,
constraint ADD_PK PRIMARY KEY(professor_id,semester, year, section, room)
CONSTRAINT add_fk FOREIGN KEY (semester, year, section, room) REFERENCES classroom(semester, year, section, room),
CONSTRAINT add_fk1 FOREIGN KEY (professor_id) REFERENCES professor(professor_id)
);

CREATE TABLE manages (
    user_id number(5) NOT NULL,
    professor_id number(5) NOT NULL,
    stu_id number(5) NOT NULL,
    CONSTRAINT man_pk PRIMARY KEY (user_id),
    CONSTRAINT man_fk FOREIGN KEY (user_id) REFERENCES users(user_id),
    CONSTRAINT man_fk1 FOREIGN KEY (professor_id) REFERENCES professor(professor_id),
    CONSTRAINT man_fk2 FOREIGN KEY(stu_id) REFERENCES student(stu_id),
);

create table student_prof(stu_id number(5) NOT NULL,
                        professor_id number(5) NOT NULL,
                        constraint sp_pk PRIMARY KEY(stu_id),
                        CONSTRAINT sp_fk FOREIGN KEY (stu_id) REFERENCES student(stu_id),
                        CONSTRAINT sp_fk1 FOREIGN KEY (professor_id) REFERENCES professor(professor_id),
);
