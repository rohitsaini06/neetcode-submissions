class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> hash;
        int n = nums.size();
        for (auto& num:nums) {
            hash[num]++;
        }
        
        vector<int> res;
        int i = 3;
        for (auto& [key, val]:hash) {
            if (val > n/3) res.push_back(key); i++;
            if (i == 2) return res;
        }
      
        return res;
    }
};