class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.size();
        int m = t.size();
        
        if (n != m) {
            return false;
        }

        unordered_map<char, int> hs1;
        for(int i = 0; i < n; i++) {
            hs1[s[i]]++;
        }
        unordered_map<char, int> hs2;
        for(int i = 0; i < n; i++) {
            hs2[t[i]]++;
        }
        return hs1 == hs2;
    }
};
