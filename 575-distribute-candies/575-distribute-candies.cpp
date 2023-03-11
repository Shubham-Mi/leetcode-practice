class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_set <int> st;
        for (int candy: candyType) st.insert(candy);
        return min(st.size(), candyType.size() / 2);
    }
};