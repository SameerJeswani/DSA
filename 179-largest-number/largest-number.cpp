class Solution {
public:
    string largestNumber(vector<int>& arr) {
        auto cmp = [](int a, int b) {
            return to_string(a) + to_string(b) >
                   to_string(b) + to_string(a);
        };

        sort(arr.begin(), arr.end(), cmp);

        // Handle all zeros
        if (arr[0] == 0)
            return "0";

        string ans;

        for (int x : arr)
            ans += to_string(x);

        return ans;
    }
};