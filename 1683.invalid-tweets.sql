--
-- @lc app=leetcode id=1683 lang=mysql
--
-- [1683] Invalid Tweets
--

-- @lc code=start
SELECT tweet_id FROM Tweets WHERE LENGTH(content) > 15;
-- @lc code=end

