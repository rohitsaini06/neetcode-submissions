class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hash;
        hash.reserve(strs.size());

        for (string str: strs) {
            string temp = str;
            sort(temp.begin(), temp.end());
            hash[temp].push_back(str);
        }

        vector<vector<string>> vec;
        for (auto it : hash) {
            vec.push_back(it.second);
        }

        return vec;
    }
};
