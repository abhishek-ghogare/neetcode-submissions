class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<bool> visited(256, false);
        int longestUniqueStrLength = 0;
        int start = 0;

        for (int i=0 ; i<s.size() ; ++i) {
            if (visited[s[i]]) {
                while (s[start] != s[i]) {
                    visited[s[start]] = false;
                    start++;
                }
                start++;
            } else {
                visited[s[i]] = true;
                longestUniqueStrLength = max(longestUniqueStrLength, i-start+1);
            }
        }

        return longestUniqueStrLength;
    }
};
