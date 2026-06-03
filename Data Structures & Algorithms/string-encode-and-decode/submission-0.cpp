class Solution {
    public:
    string delimiter = "!@#$%^!@#$%^";
    int n = delimiter.size();
    string encode(vector<string>& strs) {
        string code = "";

        for (string str : strs) {
            code += str + delimiter;
        }
        return code;
    }

    vector<string> decode(string s) {
        vector<string> strs;

        string str;
        for (int i = 0; i < s.size(); i++) {
            if (s.substr(i, n) != delimiter) {
                str += s[i];
            } else{
                strs.push_back(str);
                str = "";
                i += n - 1;
            }
                
        }
        return strs;
    }
};
