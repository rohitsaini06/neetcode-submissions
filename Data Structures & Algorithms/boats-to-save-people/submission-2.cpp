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
                cout << people[i] << endl;
                cout << people[j] << endl;
                cout <<endl;
                k++;
                i++;
                j--;
                n -= 2;
            } else if (people[i] == limit) {
                cout << people[i] << endl;
                cout <<endl;
                k++;
                i++;
                n--;
            } else if (people[j] == limit) {
                cout << people[j] << endl;
                cout <<endl;
                k++;
                j--;
                n--;
            } else if (people[i]+people[j] > limit) j--;
            else i++;
        }
        return k+n;
    }
};