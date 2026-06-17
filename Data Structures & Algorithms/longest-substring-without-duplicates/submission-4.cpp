class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> window;
        int i = 0;
        int j = 0;
        int mx = 0;
        while (j < s.size()) {
            if (window.find(s[j]) != window.end()) {
                window.erase(s[i]);
                i++;
            } else {
                window.insert(s[j]);
                j++;
                mx = max(mx, j-i);
            }
        }

        return mx;
    }
};
