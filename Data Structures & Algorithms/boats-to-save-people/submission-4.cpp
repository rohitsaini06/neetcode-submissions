class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int k = 0;
        int n = people.size();
        int i = 0;
        int j = n-1;

        while (i < j) {
            if (people[i]+people[j] <= limit) {
                k++;
                i++;
                j--;
                n -= 2;
            } else if (people[i] == limit) {
                k++;
                i++;
                n--;
            } else if (people[j] == limit) {
                k++;
                j--;
                n--;
            } else if (people[i]+people[j] > limit) j--;
            else i++;
        }
        return k+n;
    }
};