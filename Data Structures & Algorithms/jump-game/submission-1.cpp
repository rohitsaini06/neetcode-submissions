class Solution {
public:
    bool canJump(vector<int>& nums, int i = 0) {
        int n = nums.size();
        while (i < n-1) {
            if (nums[i] == 0) return false;
            else if (nums[i] == 1) i++;
            else {
                for (int j = 1; j <= nums[i]; j++) {
                    if (canJump(nums, i+j)) return true;
                }
                return false;
            }
        }
        return i>=n-1;
    }
};