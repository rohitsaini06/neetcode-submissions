class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0;
        while (i < n) {
            for (int j = i+1; j <= i+k && j < n; j++) {
                if (nums[i] == nums[j]) return true;
            }
            i++;
        }
        return false;
    }
};