class Solution {
public:
    string sortStr(string& s) {
        vector<int> a(26);
        for(auto c: s) {
            a[c-'a']++;
        }

        string so;
        // so.reserve(s.size());
        // int j=0;
        for(int i=0 ; i<26 ; ++i) {
            if (a[i] == 0) continue;
            so += (char)('a'+(char)i) + to_string(a[i]);
        }

        // cout << s << " sorted: " << so << endl;

        return so;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, int> anagramIndex;
        vector<vector<string>> output;

        for(auto s: strs) {
            string ss = sortStr(s);

            if (anagramIndex.find(ss) == anagramIndex.end()) {
                output.push_back({});
                anagramIndex[ss] = output.size()-1;
            }

            output[anagramIndex[ss]].push_back(s);
        }

        return output;
    }
};
