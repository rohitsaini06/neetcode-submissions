class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> window;
        int i = 0;
        int j = 0;
        int mx = 0;
        int prev = 0;
        while (j < s.size()) {

            if (window.count(s[j])) {
                window.erase(s[i]);
                i++;
                continue;
            }

            window.insert(s[j]);
            j++;
            if (mx < window.size()) mx = window.size();
        }

        return mx;
    }
};
