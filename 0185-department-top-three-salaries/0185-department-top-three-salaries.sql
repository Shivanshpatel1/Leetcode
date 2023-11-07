# Write your MySQL query statement below
select d.name as department, e.name as employee, e.salary as Salary
 from Employee e, Department d
where e.departmentId = d.id and 3 >= (select count(distinct e1.salary) from Employee e1 where e1.salary>=e.salary and
e1.departmentId=e.departmentId);
