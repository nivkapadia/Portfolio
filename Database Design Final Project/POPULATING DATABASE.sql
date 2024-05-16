INSERT INTO courses (course_code, course_name)
VALUES
    ('DBMGMT', 'Database Management'),
    ('LINUX1', "OS Linux"),
    ('SYSTPR','Web programming'),
    ('JAVAPR', 'JAVA PROGRAMMING'),
    ('CALC01','CALCULAS PART I'),
    ('CALC02','CALCULAS PART II'),
    ('NWENG', 'Network Engineering'), 
  ('WEBDEV', 'Web Development I'),
  ('DATANA', 'Data Analysis'),
  ('SYTPR2','Advanced Web Programming'),
  ('NETSEC', 'Network Security'),
  ('STAT10', 'Introduction to Statistics'),
  ('MGT101', 'Introduction to Management'),
  ('MGT202', 'Advanced Management'),
  ('ENGSH1', 'Introduction to English');

INSERT INTO programs (program_code, program)
VALUES ('WEBDEV', 'Web Development'),
       ('NETENG', 'Network Engineering'),
       ('DATAMY', 'Data Management'),
       ('BUSADM', 'Business Administration'),
       ('PCPRG1','Computer Science'),
       ('FINBUS','Business Finance'),
       ('GENBUS', 'General Business'),
       ('SYSADM', 'System Administrator');

INSERT INTO students (last_name, first_name, home_phone, cell_phone, email, program_code)
VALUES
  ('Kapadia','Niv',1234567890,1234567890,'nivkpd@gmail.con','PCPRG1'),
  ('Smith', 'John', 1234567890, 1234567890, 'john.smith@sheridancollege.ca', 'WEBDEV'),
  ('Lee', 'Jane', 1234567890, 1234567890, 'jane.lee@sheridancollege.ca', 'NETENG'),
  ('Chen', 'Michael', 1234567890, 1234567890, 'michael.chen@sheridancollege.ca', 'DATAMY'),
  ('Garcia', 'Antonio', 1234567890, 1234567890, 'antonio.garcia@sheridancollege.ca', 'BUSADM'),
  ('Brown', 'Emily', 1234567890, 1234567890, 'emily.brown@sheridancollege.ca', 'PCPRG1'),
  ('Miller', 'David', 1234567890, 1234567890, 'david.miller@sheridancollege.ca', 'WEBDEV'),  
  ('Robinson', 'Lisa', 1234567890, 1234567890, 'lisa.robinson@sheridancollege.ca', 'NETENG'), 
  ('Thomas', 'Sarah', 1234567890, 1234567890, 'sarah.thomas@sheridancollege.ca', 'DATAMY'), 
  ('Hall', 'William', 1234567890, 1234567890, 'william.hall@sheridancollege.ca', 'BUSADM'),
  ('Johnson', 'Elizabeth', 1234567890, 1234567890, 'elizabeth.johnson@sheridancollege.ca', 'PCPRG1');

INSERT INTO instructors ( last_name, first_name, home_phone, cell_phone, email, departmentcode, department)
VALUES
  ('Smith', 'John', 1234567890, 1234567890, 'john.smith@sheridancollege.ca', 'CSC', 'Computer Science'),
  ('Lee', 'Jane', 1234567890, 1234567890, 'jane.lee@sheridancollege.ca', 'BUS', 'Business'),
  ('Garcia', 'Antonio', 1234567890, 1234567890, 'antonio.garcia@sheridancollege.ca', 'ENG', 'Engineering'),
  ('Brown', 'Emily', 1234567890, 1234567890, 'emily.brown@sheridancollege.ca', 'NUR', 'Nursing'),
  ('Miller', 'David', 1234567890, 1234567890, 'david.miller@sheridancollege.ca', 'MAR', 'Marketing'),
  ('Robinson', 'Lisa', 1234567890, 1234567890, 'lisa.robinson@sheridancollege.ca', 'ACC', 'Accounting'),
  ('Chen', 'Michael', 1234567890, 1234567890, 'michael.chen@sheridancollege.ca', 'CSC', 'Computer Science'),
  ('Thomas', 'Sarah', 1234567890, 1234567890, 'sarah.thomas@sheridancollege.ca', 'GR', 'Graphic Design'),
  ('Hall', 'William', 1234567890, 1234567890, 'william.hall@sheridancollege.ca', 'CYB', 'Cybersecurity'),
  ('Johnson', 'Elizabeth', 1234567890, 1234567890, 'elizabeth.johnson@sheridancollege.ca', 'BUS', 'Business');

INSERT INTO course_offerings (offeringcode, course_code, coursename, semester, instructor_id, program_code, enrollment)
VALUES
  (1001, 'DBMGMT', 'Database Management', 'Fall', 1, 'WEBDEV', 20),
  (1002, 'LINUX1', 'OS Linux', 'Fall', 3, 'NETENG', 25),
  (1003, 'SYSTPR', 'Web programming', 'Winter', 5, 'WEBDEV', 30),
  (1004, 'JAVAPR', 'JAVA PROGRAMMING', 'Winter', 7, 'PCPRG1', 22),
  (1005, 'CALC01', 'CALCULAS PART I', 'Fall', 1, 'DATAMY', 18),
  (1006, 'CALC02', 'CALCULAS PART II', 'Winter', 1, 'DATAMY', 15),
  (1007, 'NWENG', 'Network Engineering', 'Fall', 3, 'NETENG', 28),
  (1008, 'WEBDEV', 'Web Development I', 'Winter', 5, 'WEBDEV', 23),
  (1009, 'DATANA', 'Data Analysis', 'Fall', 8, 'DATAMY', 20),
  (1010, 'SYTPR2', 'Advanced Web Programming', 'Winter', 5, 'WEBDEV', 18),
  (1011, 'NETSEC', 'Network Security', 'Spring', 3, 'NETENG', 16),
  (1012, 'STAT10', 'Introduction to Statistics', 'Fall', 8, 'DATAMY', 22),
  (1013, 'MGT101', 'Introduction to Management', 'Fall', 2, 'BUSADM', 30),
  (1014, 'MGT202', 'Advanced Management', 'Winter', 2, 'BUSADM', 25),
  (1015, 'ENGSH1', 'Introduction to English', 'Winter', 9, 'GENBUS', 28);

INSERT INTO add_course (add_id, course_code, course_name, prerequisites)
VALUES
  (101, 'NETSEC', 'Network Security', 'NETSEC'), 
  (102, 'CALC02', 'Calculus Part II', 'CALC01'),  
  (103, 'DATANA', 'Data Analysis', 'DBMGMT'),   
  (104, 'MGT202', 'Advanced Management', 'MGT101'), 
  (105, 'SYTPR2', 'Web Development II', 'WEBDEV');

INSERT INTO current_courses (current_id, course_code, student_id)
VALUES
  (201, 'SYTPR2', 1),  
  (202, 'NETSEC', 2),  
  (203, 'DBMGMT', 3),  
  (205, 'STAT10', 4);  

INSERT INTO academic_history (course_code, term, grade, student_id)
VALUES
  ('DBMGMT', 'Fall 2024', 'A+', 1), 
  ('SYSTPR', 'Winter 2024', 'A-', 1),  
  ('LINUX1','Winter 2024','A+',1),
  ('CALC02','Winter 2024','A',1),
  ('LINUX1', 'Fall 2024', 'A', 2),   
  ('NETSEC', 'Spring 2024', 'B', 2),  
  ('DATANA', 'Fall 2024', 'A', 3),  
  ('CALC02', 'Winter 2024', 'B-', 3); 