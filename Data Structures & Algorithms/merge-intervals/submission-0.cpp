class Solution {
    struct VectorComparator {
        bool operator() (const vector<int>& a, const vector<int>& b) {
            int i=0;
            while (i<a.size() && i<b.size() && a[i] == b[i]) {
                ++i;
            }
            return i>=a.size() || i>=b.size() || a[i] < b[i];
        }
    };
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() <= 1) {
            return vector<vector<int>>(intervals);
        }

        sort(intervals.begin(), intervals.end(), VectorComparator());

        vector<vector<int>> merged{intervals[0]};

        for (int i=1 ; i<intervals.size() ; ++i) {
            cout << "interval: " << intervals[i][0] << " " << intervals[i][1] << endl;
            if (intervals[i].size() != 2) {
                throw runtime_error("Inter of invalid size found");
            }

            auto& currX = merged.back()[0];
            auto& currY = merged.back()[1];

            if (currX <= intervals[i][0] && intervals[i][0] <= currY) {
                currY = max(currY, intervals[i][1]);
            } else {
                merged.push_back(intervals[i]);
            }
        }

        return merged;
    }
};
