class Solution {
public:
    int rob(vector<int>& nums, vector<int>& cache, int n) {
        if (n<0 || n>=nums.size()) {
            return 0;
        }

        if (cache[n] != -1) {
            return cache[n];
        }

        cache[n] = max(cache[n], nums[n] + rob(nums, cache, n+2));
        cache[n] = max(cache[n], rob(nums, cache, n+1));

        return cache[n];
    }

    int rob(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        if (nums.size() == 1)
            return nums[0];

        vector<int> DP(nums.size(), -1);
        DP[nums.size()-1] = nums[nums.size()-1];
        rob(nums, DP, 0);

        return max(DP[0], DP[1]);
    }
};
