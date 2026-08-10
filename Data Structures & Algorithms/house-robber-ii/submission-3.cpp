class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }

        if (nums.size() == 1) {
            return nums[0];
        }

        if (nums.size() == 2) {
            return max(nums[0], nums[1]);
        }

        int p1=nums[0], c1=nums[0], p2=0, c2=nums[1];

        for (int i=2 ; i<nums.size()-1 ; ++i) {
            int t = c1;
            c1 = max(c1, p1+nums[i]);
            p1 = t;

            t = c2;
            c2 = max(c2, p2+nums[i]);
            p2 = t;
        }

        int t = c2;
        c2 = max(c2, p2+nums[nums.size()-1]);
        p2 = c2;

        return max(c1, c2);
    }
};
