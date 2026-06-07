class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> hash;
        for (auto num:nums) {
            hash[num]++;
        }

        vector<vector<int>> vec(nums.size()+1);
        for (auto& entry:hash) {
            vec[entry.second].push_back(entry.first);
        }

        vector<int> res;
        for (int i = vec.size() - 1; i > 0; --i) {
            for (auto n : vec[i]) {
                res.push_back(n);
                if (res.size() == k) return res;
            }
        }
        return res;
    }
};
