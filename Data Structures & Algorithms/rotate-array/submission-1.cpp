class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = (k % n);

        // int i = n-1;
        // while (k >= 0) {
        //     swap(nums[i--], nums[k--]);
        // }

        reverse(nums.begin(), nums.end());
        reverse(nums.begin()+k, nums.end());
        reverse(nums.begin(), nums.begin()+k);

    }
};