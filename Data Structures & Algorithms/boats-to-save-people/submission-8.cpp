class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        vector<int> count(limit+1, 0);
        int n = 0;
        for (int num: people) {
            count[num]++;
        }

        int i = 1;
        int j = limit;
        while (i <= j) {
            cout << i << " -> " << count[i] << endl << j << " -> " << count[j] << endl << "Boat: " << n << endl << endl;
            if (count[i] < 1) {i++; continue;}
            if (count[j] < 1) {j--; continue;}
            if (i+j <= limit && count[i]+count[j] >= 2) {
                count[i]--;
                count[j]--;
                n++;
            }
            else if (j <= limit) {
                count[j]--;
                n++;
            }
            else if (i == limit) {
                count[i]--;
                n++;
            }
        }

        return n;
    }
};