select ROUND(count(a2.player_id)/(select count(distinct player_id) from Activity), 2) as fraction 
from (
    select player_id, MIN(event_date) as first_login
    from Activity group by player_id
) a1
left join Activity a2 on a1.player_id = a2.player_id and 
a2.event_date = DATE_ADD(a1.first_login, INTERVAL 1 DAY);
