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

    void mergeSort(std::vector<int>& arr, int start, int end) {
        if (start < end) {
            int mid = start + (end - start) / 2;
            mergeSort(arr, start, mid);
            mergeSort(arr, mid + 1, end);
            merge(arr, start, mid, end);
        }
    }

    void merge(std::vector<int>& arr, int start, int mid, int end) {
        std::vector<int> left(arr.begin() + start, arr.begin() + mid + 1);
        std::vector<int> right(arr.begin() + mid + 1, arr.begin() + end + 1);

        size_t i = 0, j = 0;
        int k = start;

        while (i < left.size() && j < right.size()) {
            if (left[i] <= right[j]) {
                arr[k++] = left[i++];
            } else {
                arr[k++] = right[j++];
            }
        }

        while (i < left.size()) arr[k++] = left[i++];
        while (j < right.size()) arr[k++] = right[j++];
    }


    void sortColors(vector<int>& nums) {
        // insertionSort(nums, 0, nums.size()-1);
        mergeSort(nums, 0, nums.size()-1);
    }
};