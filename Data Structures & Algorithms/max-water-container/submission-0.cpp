class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int i = 0;
        int j = n - 1;
        int area = -1;
        while (i < j) {
            int a = (j-i)*min(heights[i], heights[j]);
            if (a > area) area = a;
            if (heights[i] > heights[j]) j--;
            else i++;
        }

        return area;
    }
};
