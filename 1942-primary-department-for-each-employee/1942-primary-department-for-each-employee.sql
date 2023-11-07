# Write your MySQL query statement below
select employee_id, department_id from Employee e where primary_flag = 'Y'
UNION
select employee_id, department_id from Employee e1 group by employee_id having
count(employee_id)=1; 