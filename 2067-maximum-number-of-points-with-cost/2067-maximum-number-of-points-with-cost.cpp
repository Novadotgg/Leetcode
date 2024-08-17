class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int m = points.size(), n = points[0].size();
        vector<long long> prev(points[0].begin(), points[0].end());

        for (int i = 1; i < m; ++i) {
            vector<long long> left_max(n), right_max(n);

            left_max[0] = prev[0];
            for (int j = 1; j < n; ++j)
                left_max[j] = max(left_max[j-1] - 1, prev[j]);

            right_max[n-1] = prev[n-1];
            for (int j = n-2; j >= 0; --j)
                right_max[j] = max(right_max[j+1] - 1, prev[j]);

            for (int j = 0; j < n; ++j)
                prev[j] = points[i][j] + max(left_max[j], right_max[j]);
        }

        return *max_element(prev.begin(), prev.end());
    }
};