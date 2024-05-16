-- VIEW ALL STUDENTS
SELECT * FROM students;

-- VIEW THE ACADEMIC HISTORY OF A PARTICULAR STUDENT
SELECT course_code, term, a.student_id,  last_name, first_name, email, grade FROM academic_history a
LEFT JOIN students s ON a.student_id = s.student_id
WHERE a.student_id = 1;

-- View all students grade in particular subject
SELECT s.first_name, s.last_name, grade, term, course_code
FROM academic_history a
JOIN students s ON a.student_id = s.student_id
WHERE course_code = 'DBMGMT';

-- VIEW ALL INSTRUCTORS
SELECT * FROM instructors;

-- Display course offerings along with number of enrolled students
SELECT co.*, COUNT(cc.student_id) AS num_enrolled
FROM course_offerings AS co
LEFT JOIN current_courses AS cc ON co.course_code = cc.course_code
GROUP BY co.offeringcode;

-- List courses with their prerequisites
SELECT ac.course_code, ac.course_name, ac.prerequisites, c.course_name AS prerequisite_name
FROM add_course AS ac
LEFT JOIN courses AS c ON ac.prerequisites = c.course_code;

-- Name of students and courses they enrolled in 
SELECT s.first_name, s.last_name, c.course_name
FROM students AS s
INNER JOIN current_courses AS cc ON s.student_id = cc.student_id
INNER JOIN courses AS c ON cc.course_code = c.course_code;

-- Contact details of instructors in Winter semester
SELECT i.first_name, i.last_name, i.email
FROM instructors AS i
INNER JOIN course_offerings AS co ON i.instructor_id = co.instructor_id
WHERE co.semester = 'Winter';
