# Write your MySQL query statement below
# select c1.user_id, round(if(count(c1.action), count(c1.action), 0)/(count(c2.action)+count(c1.action)), 2) as c_rate
# from Confirmations c1
# inner join Confirmations c2
# on c1.user_id=c2.user_id
# where c1.action = 'confirmed' and c2.action = 'timeout'
# group by 
# c1.user_id;

select s.user_id,round(sum(if(c.action="confirmed",1,0)) / count(*),2) 
as confirmation_rate from Signups s 
left join Confirmations c on s.user_id=c.user_id 
group by s.user_id;