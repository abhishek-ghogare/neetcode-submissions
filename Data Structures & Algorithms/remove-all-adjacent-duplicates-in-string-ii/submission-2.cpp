class Solution {
private:
    struct Node {
        char ch;
        int count;
    };
public:
    string removeDuplicates(string s, int k) {
        vector<Node> stack;
        int outSize = 0;

        for (int i=0 ; i<s.size() ; ++i) {
            if (stack.empty() || stack.back().ch != s[i]) {
                stack.push_back({s[i], 1});
                outSize++;
            } else {
                auto& top = stack.back();
                top.count++;
                outSize++;
                if (top.count == k) {
                    stack.pop_back();
                    outSize -= k;
                }
            }
        }

        string out;
        out.reserve(outSize);
        for (auto node: stack) {
            out.append(node.count, node.ch);
        }

        return out;
    }
};