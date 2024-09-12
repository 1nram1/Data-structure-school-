/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        for (int i = 0, length = nums.size(); i < length; ++i) {
            auto iter = map.find(target - nums[i]);
            if (iter != map.end()) {
                vector<int> result = {iter->second, i};
                return result;
            }
            map[nums[i]] = i;
            //map.insert({nums[i], i})
            //map.insert(pair<int,int>(nums[i], i));
        }
        vector<int> b = {-1, -1};
        return b;
    }
};
// @lc code=end

