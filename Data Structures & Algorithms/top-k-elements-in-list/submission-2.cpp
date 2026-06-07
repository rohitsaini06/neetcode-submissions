class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> hash;
        for (auto num:nums) {
            hash[num]++;
        }

        vector<pair<int, int>> vec(hash.begin(), hash.end());
        sort(vec.begin(), vec.end(),
            [] (auto& a, auto& b) {
                return a.second > b.second;
            }
        );

        vector<int> res;
        for (int i = 0; i < k; i++) {
            res.push_back(vec[i].first);
        }
        return res;
    }
};
