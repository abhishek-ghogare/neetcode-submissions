class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size())
            return false;
        
        vector<int> cc(26, 0);

        for (int i=0 ; i<s.size() ; ++i) {
            cc[s[i]-'a']++;
            cc[t[i]-'a']--;
        }
        
        for (int i: cc) {
            if (i!=0)
                return false;
        }
        
        return true;
    }
};
