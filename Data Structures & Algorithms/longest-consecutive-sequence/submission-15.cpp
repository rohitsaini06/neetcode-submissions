class Solution {
   public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        if (n == 0) return 0;
        if (n == 1) return 1;

        int mx = 1;
        int count = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1]) continue;

            if (nums[i] == nums[i - 1] + 1) {
                count++;
            } else {
                count = 1;
            }
            mx = count > mx ? count : mx;
        }
        return mx;
    }
};
