class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = (k % n);

        nums.insert(nums.end(), nums.begin(), nums.begin()-k+n);
        nums.erase(nums.begin(), nums.begin()+n-k);
    }
};