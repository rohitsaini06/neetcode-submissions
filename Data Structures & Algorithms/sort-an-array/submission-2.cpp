
// Forward declarations of our sub-algorithms
void insertionSort(std::vector<int>& arr, int start, int end);
int partition(std::vector<int>& arr, int start, int end);
void mergeSort(std::vector<int>& arr, int start, int end);
void merge(std::vector<int>& arr, int start, int mid, int end);
void introSortHelper(std::vector<int>& arr, int start, int end, int maxDepth);

// The Master Hybrid Function
void hybridSort(std::vector<int>& arr) {
    if (arr.empty()) return;
    
    // Calculate maximum depth allowed for Quick Sort before it's considered "stuck"
    // Formula: 2 * log2(N)
    int maxDepth = 2 * std::floor(std::log2(arr.size()));
    
    introSortHelper(arr, 0, arr.size() - 1, maxDepth);
}

// The core brain that switches between algorithms dynamically
void introSortHelper(std::vector<int>& arr, int start, int end, int maxDepth) {
    int size = end - start + 1;

    // Rule 1: If the chunk is tiny, Insertion Sort is faster than recursion
    if (size < 16) {
        insertionSort(arr, start, end);
        return;
    }

    // Rule 2: If Quick Sort is recursing too deeply (endangering O(N^2)), switch to Merge Sort
    if (maxDepth == 0) {
        mergeSort(arr, start, end);
        return;
    }

    // Rule 3: Otherwise, standard Quick Sort behavior
    if (start < end) {
        int pivotIndex = partition(arr, start, end);
        introSortHelper(arr, start, pivotIndex - 1, maxDepth - 1);
        introSortHelper(arr, pivotIndex + 1, end, maxDepth - 1);
    }
}

// --- 1. INSERTION SORT ---
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

// --- 2. QUICK SORT PARTITION (Median-of-Three) ---
int partition(std::vector<int>& arr, int start, int end) {
    int mid = start + (end - start) / 2;
    
    // Median-of-three logic to pick a smart pivot and avoid worst-case scenarios
    if (arr[mid] < arr[start]) std::swap(arr[mid], arr[start]);
    if (arr[end] < arr[start]) std::swap(arr[end], arr[start]);
    if (arr[end] < arr[mid]) std::swap(arr[end], arr[mid]);
    
    // arr[mid] is now the median. Hide it at the end to act as our pivot.
    std::swap(arr[mid], arr[end]);
    int pivot = arr[end];
    
    int i = start - 1;
    for (int j = start; j < end; ++j) {
        if (arr[j] <= pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[end]);
    return i + 1;
}

// --- 3. MERGE SORT FALLBACK ---
void mergeSort(std::vector<int>& arr, int start, int end) {
    if (start < end) {
        int mid = start + (end - start) / 2;
        mergeSort(arr, start, mid);
        mergeSort(arr, mid + 1, end);
        merge(arr, start, mid, end);
    }
}

void merge(std::vector<int>& arr, int start, int mid, int end) {
    // Create temporary vectors for left and right halves
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

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        hybridSort(nums);
        return nums;    
    }
};