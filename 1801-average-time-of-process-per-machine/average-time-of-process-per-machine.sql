# Write your MySQL query statement below
select a1.machine_id, Round(AVG(a1.timestamp-a2.timestamp), 3) 
as processing_time from
Activity as a1 join Activity as a2 on a1.machine_id = a2.machine_id 
where a1.activity_type ='end' AND a2.activity_type = 'start' 
AND a1.process_id = a2.process_id
group by a1.machine_id 
order by a1.machine_id asc;