class Solution {
public:
    long long binaryToDecimal(string str) {
        long long int dec_num = 0LL;
        long long int power = 0LL;
        int n = str.size();
        for(int i=n-1; i>=0; --i) {
            if(str[i] == '1') dec_num = (1LL) * (dec_num + (1LL<<power));
            power++;
        }
        return dec_num;
    }
    vector<vector<int>> substringXorQueries(string s, vector<vector<int>>& queries) {
        int n = s.size();
        unordered_map <long long int, vector <int>> mp;
        for (int i=0; i<n; ++i) {
            for (int j=i; j>=0 && j>=i-32; --j) {
                string curr = s.substr(j, i - j + 1);
                long long int val = binaryToDecimal(curr);
                if (mp.find(val) == mp.end()) mp[val] = {j, i};
                else {
                    if ((mp[val][1] - mp[val][0]) > (i - j)) mp[val] = {j, i};
                }
            }
        }
        vector <vector <int>> ans;
        for (vector <int> query: queries) {
            int xorValue = (1LL) * (query[0] ^ query[1]);
            if (mp.find(xorValue) == mp.end()) ans.push_back({-1, -1});
            else ans.push_back(mp[xorValue]);
        }
        return ans;
    }
};