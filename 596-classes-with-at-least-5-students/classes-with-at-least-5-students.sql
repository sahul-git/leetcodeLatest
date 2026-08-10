# Write your MySQL query statement below
select class from
(select class, count(distinct student) as student_count from Courses group by class) as t where student_count >= 5;