# Write your MySQL query statement below
SELECT "Low Salary" AS category, sum(if(income<20000, 1, 0)) as accounts_count from Accounts
UNION
SELECT "Average Salary" AS category, sum(if(income>=20000 and income<=50000, 1, 0)) as accounts_count from Accounts
UNION
SELECT "High Salary" AS category, sum(if(income>50000, 1, 0)) as accounts_count from Accounts;