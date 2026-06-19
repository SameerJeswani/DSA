class Solution {
public:
    typedef vector<double> v;

    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {

        int n = arr.size();

        priority_queue<v, vector<v>, greater<v>> pq;

        for (int i = 0; i < n - 1; i++) {
            pq.push({1.0 * arr[i] / arr[n - 1], (double)i, (double)(n - 1)});
        }

        int smallest = 1;

        while (smallest < k) {

            v cur = pq.top();
            pq.pop();

            int i = cur[1];
            int j = cur[2];

            j--;

            if (j > i) {
                pq.push({1.0 * arr[i] / arr[j], (double)i, (double)j});
            }

            smallest++;
        }

        v ans = pq.top();

        return {arr[(int)ans[1]], arr[(int)ans[2]]};
    }
};