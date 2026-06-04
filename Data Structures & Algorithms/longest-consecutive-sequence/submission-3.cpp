class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> seq;

        for (int i = 0; i < nums.size(); i++) {
            seq.insert(nums[i]);
        }

        int mx = 0;
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            while (seq.count(num++)) count++;
            if (count > mx) {
                mx = count;
            }
            count = 0;
        }
        return mx;
    }
};
