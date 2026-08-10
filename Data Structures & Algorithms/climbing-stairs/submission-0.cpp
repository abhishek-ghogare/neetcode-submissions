class Solution {
public:
    int climbStairs(int n, vector<int>& DP) {
        if (n<0 || n>=DP.size())
            return 0;

        if (DP[n] != -1)
            return DP[n];

        return DP[n] = climbStairs(n-1, DP) + climbStairs(n-2, DP);
    }

    int climbStairs(int n) {
        vector<int> DP (n+1, -1);
        DP[0] = 1;
        DP[1] = 1;

        return climbStairs(n, DP); 
    }
};
