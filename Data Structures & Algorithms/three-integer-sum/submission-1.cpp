class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> res;
        int n = nums.size();
        for (int k = 0; k < n - 2; k++) {
            if (k > 0 && nums[k] == nums[k-1]) continue;
            int i = k + 1;
            int j = n - 1;
            int sum;
            while (i < j) {
                sum = nums[i] + nums[j] + nums[k];
                if (sum == 0) {
                    res.push_back({nums[i], nums[j], nums[k]});
                    i++;
                    j--;

                    while (i < j && nums[i] == nums[i-1]) i++;
                    while (i < j && nums[j] == nums[j+1]) j--;

                } else if (sum > 0) j--;
                else i++;
            }
        }

        return res;
    }
};
