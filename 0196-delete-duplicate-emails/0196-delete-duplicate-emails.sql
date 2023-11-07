# Write your MySQL query statement below
Delete p from Person p, Person p1 where p.id>p1.id and p.email=p1.email;