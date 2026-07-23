class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector<pair<int, char>> stack;
        int outSize = 0;

        for (int i=0 ; i<s.size() ; ++i) {
            if (stack.empty() || stack.back().second != s[i]) {
                stack.push_back({1, s[i]});
                outSize++;
            } else {
                stack.back().first++;
                outSize++;
                if (stack.back().first == k) {
                    stack.pop_back();
                    outSize -= k;
                }
            }
        }

        string out;
        out.reserve(outSize);
        for (int i=0 ; i<stack.size() ; ++i) {
            out.append(stack[i].first, stack[i].second);
        }

        return out;
    }
};