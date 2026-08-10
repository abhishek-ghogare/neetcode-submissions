class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost, vector<int>& DP, int i) {
        if (i<0 || i>=DP.size()) {
            return 0;
        }

        if (DP[i] != -1) {
            return DP[i];
        }

        return DP[i] = min(minCostClimbingStairs(cost, DP, i-1), minCostClimbingStairs(cost, DP, i-2)) + cost[i];
    }

    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> DP(cost.size(), -1);
        
        DP[0] = cost[0];
        DP[1] = cost[1];

        minCostClimbingStairs(cost, DP, cost.size()-1);

        return min(DP[cost.size()-1], DP[cost.size()-2]);
    }
};
