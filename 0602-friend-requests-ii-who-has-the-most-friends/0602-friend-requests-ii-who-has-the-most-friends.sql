# Write your MySQL query statement below
SELECT id, COUNT(*) AS num 
FROM (
    SELECT requester_id as id FROM RequestAccepted
    UNION ALL
    SELECT accepter_id FROM RequestAccepted
) AS friends_count
GROUP BY id
ORDER BY num DESC
LIMIT 1;