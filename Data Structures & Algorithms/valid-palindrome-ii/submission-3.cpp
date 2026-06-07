class Solution {
public:
    bool isPalindrome(string str, int l, int r) {
        while (l < r) {
            if (str[l] != str[r]) return false;
            l++;
            r--;
        }
        return true;
    }

    bool validPalindrome(string s) {
        if (s.size() <= 1) return true;
        int i = 0, j = s.length()-1;
        while (i <= j) {
            if (s[i] != s[j]) {
                return isPalindrome(s, i+1, j) || isPalindrome(s, i, j-1);
            }
            i++;
            j--;
        }
        return true;
    }
};