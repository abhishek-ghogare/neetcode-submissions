class Solution {
public:
    string sortStr(string& s) {
        vector<int> a(26);
        for(auto c: s) {
            a[c-'a']++;
        }

        string so;
        so.reserve(s.size());
        // int j=0;
        for(int i=0 ; i<26 ; ++i) {
            while(a[i]>0) {
                so.push_back(i+'a');
                a[i]--;
            }
        }

        // cout << s << " sorted: " << so << endl;

        return so;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> a;

        for(auto s: strs) {
            a[sortStr(s)].push_back(s);
        }

        vector<vector<string>> o;
        for (auto e: a) {
            o.push_back(e.second);
        }

        return o;
    }
};
