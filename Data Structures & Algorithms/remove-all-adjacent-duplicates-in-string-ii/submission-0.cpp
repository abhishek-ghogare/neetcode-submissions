class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector<pair<int, char>> stack;

        for (int i=0 ; i<s.size() ; ++i) {
            if (stack.empty() || stack.back().second != s[i]) {
                stack.push_back({1, s[i]});
            } else {
                stack.back().first++;
                if (stack.back().first == k) {
                    stack.pop_back();
                }
            }
        }

        string out;
        for (int i=0 ; i<stack.size() ; ++i) {
            out.append(stack[i].first, stack[i].second);
        }

        return out;
    }
};