class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> visited;

        for (int i=0 ; i<nums.size() ; ++i) {
            if (visited.find(target-nums[i]) != visited.end()) {
                return {visited[target-nums[i]], i};
            }

            visited[nums[i]] = i;
        }

        return {0,0};
    }
};
