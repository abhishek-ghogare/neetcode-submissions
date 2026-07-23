class Solution {
    int DP(vector<vector<int>>& cache, const vector<vector<int>>& costs, int aCount, int bCount) {
        int N = costs.size();

        int i = N-(aCount+bCount);

        if (i>=N)
            return 0;
        
        if (cache[aCount][bCount] != -1)
            return cache[aCount][bCount];

        int curCost = INT_MAX;

        if (bCount > 0) {
            curCost = costs[i][1] + DP(cache, costs, aCount, bCount-1);
        }

        if (aCount > 0) {
            curCost = min(curCost, costs[i][0] + DP(cache, costs, aCount-1, bCount));
        }
 
        return cache[aCount][bCount] = curCost;
    } 
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        vector<vector<int>> cache(costs.size(), vector<int>(costs.size(), -1));
        return DP(cache, costs, costs.size()/2, costs.size()/2);
    }
};