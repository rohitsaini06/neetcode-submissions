class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> prefix = height;
        vector<int> suffix = height;

        int n = height.size();
        int i = 1;
        int j = n-2;
        while (i < n && j >= 0) {
            cout << i << " " << j << endl;
            prefix[i] = max(prefix[i], prefix[i-1]);
            suffix[j] = max(suffix[j], suffix[j+1]);
            i++;
            j--;
        }

        int water = 0;
        for (int i = 0; i < n; i++) {
            water += min(prefix[i], suffix[i]) - height[i];
        }

        return water;

    }
};
