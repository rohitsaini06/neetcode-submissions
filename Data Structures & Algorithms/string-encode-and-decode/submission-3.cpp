class Solution {
    public:

    string encode(vector<string>& strs) {
        string code = "";

        for (string str : strs) {
            code += to_string(str.length()) + '~' + str;
        }
        return code;
    }

    vector<string> decode(string s) {
        vector<string> strs;
        int i = 0;
        while (i < s.length()) {
            int idx = s.find('~', i);
            int lenght = stoi(s.substr(i, idx-i));
            strs.push_back(s.substr(idx+1, lenght));
            i = idx+lenght+1;
        }
        return strs;
    }
};
