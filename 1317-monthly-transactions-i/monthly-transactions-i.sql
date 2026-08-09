# Write your MySQL query statement below
select left(trans_date, 7) as month,
country, count(id) as trans_count,
SUM(state = 'Approved') as approved_count,
SUM(amount) as trans_total_amount,
SUM((state = 'Approved') * amount) as approved_total_amount

from Transactions
group by month, country;