class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end()); // Sort events by start time
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        int maxVal = 0, ans = 0;

        for (auto& event : events) {
            int start = event[0], end = event[1], value = event[2];

            // Remove events that end before the current event's start time
            while (!pq.empty() && pq.top().first < start) {
                maxVal = max(maxVal, pq.top().second);
                pq.pop();
            }

            // Update the maximum sum of values
            ans = max(ans, maxVal + value);

            // Add the current event to the priority queue
            pq.push({end, value});
        }

        return ans;
    }
};