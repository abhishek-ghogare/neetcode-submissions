class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> cc(26, 0);

        for (char c: s) {
            cc[c-'a']++;
        }
        for (char c: t) {
            cc[c-'a']--;
        }
        for (int i: cc) {
            if (i!=0)
                return false;
        }
        return true;
    }
};
