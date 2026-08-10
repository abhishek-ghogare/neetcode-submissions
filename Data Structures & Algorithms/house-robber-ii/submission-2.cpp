class Solution {
public:
    int rob(vector<int>& nums, vector<int>& cache, int n) {
        if (n<0 || n>=nums.size())
            return 0;
        
        if (cache[n] != -1)
            return cache[n];

        cache[n] = max(cache[n], rob(nums, cache, n+1));
        cache[n] = max(cache[n], rob(nums, cache, n+2) + nums[n]);

        return cache[n];
    }

    int rob(vector<int>& nums) {
        if (nums.size() == 1)
            return nums[0];

        vector<int> cache(nums.size(), -1);
        cache[nums.size()-1] = nums[nums.size()-1];
        int sum1 = rob(nums, cache, 1);
        cout << sum1 << endl;

        cache = vector<int>(nums.size(), -1);
        cache[nums.size()-1] = 0;
        int sum2 = rob(nums, cache, 0);
        cout << sum2 << endl;

        return max(sum1, sum2);
    }
};
