class Solution {
public:
    void insertionSort(std::vector<int>& arr, int start, int end) {
        for (int i = start + 1; i <= end; ++i) {
            int key = arr[i];
            int j = i - 1;
            while (j >= start && arr[j] > key) {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = key;
        }
    }

    void sortColors(vector<int>& nums) {
        insertionSort(nums, 0, nums.size()-1);
    }
};