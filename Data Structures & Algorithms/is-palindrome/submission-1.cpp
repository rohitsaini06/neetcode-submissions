class Solution {
public:
    bool isPalindrome(string s) {
        for (char &c : s)
            c = toupper(c);
        
        int i = 0, j = s.length()-1;
        
        while (i <= j) {
            if (!isalnum(s[i])) {
                i++;
                continue;
            }
            if (!isalnum(s[j])) {
                j--;
                continue;
            }

            if (s[i] != s[j]) return false;
            cout << s[i] << ' ';
            i++;
            j--;
        }
        return true;
    }
};
