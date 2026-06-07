class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string str;
        int i = 0, j = 0;
        int n = word1.size(), m = word2.size();
        while (i < n && j < m) {
            str += word1[i++];
            str += word2[j++];
        }
        str += word1.substr(i);
        str += word2.substr(j);
        return str;
    }
};