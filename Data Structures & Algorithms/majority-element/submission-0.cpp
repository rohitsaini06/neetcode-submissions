class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> hash;

        for (int num : nums) {
            hash[num] += 1;
            if (hash[num] > nums.size()/2) return num;
        }


    }
};