# Write your MySQL query statement below

(Select u.name as results 
from MovieRating as m inner join  Users as u 
on u.user_id = m.user_id Group By m.user_id 
Order by count(m.user_id) desc, u.name limit 1)
union all
(Select m.title as results
from MovieRating as r inner join Movies as m
on m.movie_id = r.movie_id 
where r.created_at like "2020-02-%"
Group By r.movie_id 
Order by avg(r.rating) desc, m.title limit 1);