# Write your MySQL query statement below


SELECT  IF(id % 2 = 0 , #condition checks when id is even 
           id-1 ,       # when true then directly do - 1
           IF(id != ( SELECT MAX(id) FROM SEAT ),id+1,id)) AS id #when false then check that if id is not last id (in case of odd numbered data set) then do id+1 else dont change id. 
        ,student
    FROM SEAT
    ORDER BY id;
                 