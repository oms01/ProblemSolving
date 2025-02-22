

SELECT B.CATEGORY, SUM(BS.SALES) AS TOTAL_SALES
FROM BOOK AS B
JOIN BOOK_SALES AS BS ON BS.BOOK_ID = B.BOOK_ID
WHERE MONTH(BS.SALES_DATE) = "01"
GROUP BY B.CATEGORY
ORDER BY B.CATEGORY ASC