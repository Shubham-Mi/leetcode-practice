class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int ans = 0;
        int p2 = people.size() - 1;
        int p1 = 0;
        while (p1 < p2) {
            if (people[p1] + people[p2] <= limit) p1++;
            p2--;
            ans++;
        }
        if (p1 == p2) ans++;
        return ans;
    }
};