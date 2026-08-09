# Write your MySQL query statement below
select contest_id, round((coalesce(count(r.user_id), 0)/(SELECT COUNT(*) FROM Users))*100, 2) as percentage from Users as u right join Register as r
on r.user_id = u.user_id group by contest_id order by percentage desc , contest_id asc;