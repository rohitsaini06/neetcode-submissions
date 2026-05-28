class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        unordered_map<int, int> hash;
        for (int i = 0; i < nums.size(); i++) {
            int n = target - nums[i];
            if (hash.count(n)) {
                return {hash[n], i};
            }
            hash.insert({nums[i], i});
        }
        return {};
    }
};