DROP DATABASE IF EXISTS sheridan_registrar;
CREATE SCHEMA sheridan_registrar;

USE sheridan_registrar;

DROP TABLE IF EXISTS course_offerings;
DROP TABLE IF EXISTS courses;
DROP TABLE IF EXISTS instructors;
DROP TABLE IF EXISTS programs;
DROP TABLE IF EXISTS students;
DROP TABLE IF EXISTS academic_history;
DROP TABLE IF EXISTS current_courses;
DROP TABLE IF EXISTS add_course;


CREATE TABLE courses(
    course_code         VARCHAR(6) PRIMARY KEY,
    course_name         CHAR(50)
);

CREATE TABLE programs(
    program_code        VARCHAR(20) PRIMARY KEY,
    program             VARCHAR(50),
    enrollment          INT
);

CREATE TABLE students(
    student_id          INT PRIMARY KEY AUTO_INCREMENT,
    last_name           CHAR(45),
    first_name          CHAR(45),
    home_phone          BIGINT,
    cell_phone          BIGINT,
    email               VARCHAR(100),
    program_code        VARCHAR(20),
    FOREIGN KEY (program_code) REFERENCES programs(program_code)
);

CREATE TABLE instructors(
    instructor_id       INT PRIMARY KEY AUTO_INCREMENT,
    last_name           CHAR(45),
    first_name          CHAR(45),
    home_phone          BIGINT,
    cell_phone          BIGINT,
    email               VARCHAR(100),
    departmentcode      VARCHAR(10),
    department          VARCHAR(50)
);


CREATE TABLE course_offerings(
    offeringcode        INT PRIMARY KEY NOT NULL,
    course_code         VARCHAR(6),
    coursename          CHAR(50),
    semester            VARCHAR(6),
    instructor_id       INT,
    program_code		VARCHAR(20),
    enrollment          INT,
    FOREIGN KEY (instructor_id) REFERENCES instructors(instructor_id),
    FOREIGN KEY (course_code) REFERENCES courses(course_code),
    FOREIGN KEY (program_code) REFERENCES programs(program_code)
);


CREATE TABLE add_course(
	add_id				INT PRIMARY KEY,
    course_code	VARCHAR(6),
    course_name	CHAR(20),
    prerequisites		VARCHAR(100),
    FOREIGN KEY (course_code) REFERENCES courses(course_code),
	FOREIGN KEY (prerequisites) REFERENCES courses(course_code)
);


CREATE TABLE current_courses(
	current_id				INT PRIMARY KEY,
    course_code		VARCHAR(6),
    student_id			INT,
    FOREIGN KEY (course_code) REFERENCES courses(course_code),
    FOREIGN KEY (student_id) REFERENCES students(student_id)
);

CREATE TABLE academic_history (
	course_code 		VARCHAR(6),
    term						CHAR(30),
    grade					CHAR(2),
    student_id			INT,
    FOREIGN KEY (course_code) REFERENCES course_offerings(course_code),
    FOREIGN KEY (student_id) REFERENCES students(student_id)
);
