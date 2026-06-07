class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_set<int> hash_set(nums.begin(), nums.end());
        vector<int> res;

        for (auto& key : hash_set) {
            int freq = 0;
            for (int num : nums) {
                if (num == key) freq++;
            }
            if (freq > nums.size() / 3) {
                res.push_back(key);
            }
        }
      
        return res;
    }
};