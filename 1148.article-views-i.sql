--
-- @lc app=leetcode id=1148 lang=mysql
--
-- [1148] Article Views I
--

-- @lc code=start
SELECT DISTINCT author_id AS id FROM Views WHERE author_id = viewer_id ORDER BY id;

-- @lc code=end

