class Solution {
public:
    bool check(vector <int>& time, long long mid, int totalTrips) {
        long long int trips = 0;
        for (int time: time) {
            trips += 1LL * (mid / time);
        }
        if (trips >= totalTrips) return true;
        return false;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        int n = time.size();
        long long low = 0;
        long long high = 1LL * time[0] * totalTrips;
        while (low <= high) {
            long long mid = (low + high) / 2;
            if (check(time, mid, totalTrips)) high = mid - 1;
            else low = mid + 1;
        }
        return high + 1;
    }
};