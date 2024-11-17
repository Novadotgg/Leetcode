class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> prefixSum(n + 1, 0); // Prefix sum array
        
        for (int i = 0; i < n; ++i) {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }
        
        deque<int> dq; // Monotonic deque to store indices
        int minLength = INT_MAX;

        for (int i = 0; i <= n; ++i) {
            // Remove indices from the front where the subarray sum is >= k
            while (!dq.empty() && prefixSum[i] - prefixSum[dq.front()] >= k) {
                minLength = min(minLength, i - dq.front());
                dq.pop_front();
            }

            // Remove indices from the back to maintain increasing order of prefixSum
            while (!dq.empty() && prefixSum[i] <= prefixSum[dq.back()]) {
                dq.pop_back();
            }

            // Add the current index to the deque
            dq.push_back(i);
        }

        return minLength == INT_MAX ? -1 : minLength;
    }
};
