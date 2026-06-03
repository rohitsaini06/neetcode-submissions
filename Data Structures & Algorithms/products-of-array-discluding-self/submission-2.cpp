class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        vector<int> prefix (n, 1);
        vector<int> suffix (n, 1);
        vector<int> result;

        int i = 1;
        int j = n-2;

        while (i < n && j >= 0) {
            prefix[i] = prefix[i-1] * nums[i-1];
            suffix[j] = suffix[j+1] * nums[j+1];
            j--;
            i++;
        }

        for (int k = 0; k < n; k++) {
            result.push_back(prefix[k] * suffix[k]);
        }

        return result;
    }
};
