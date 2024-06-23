class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int i=0;
        // int j=nums.size()-1;
        int count=0;
        deque<int> maxDeque, minDeque; // deques to keep track of max and min values

        for (int j = 0; j < nums.size(); j++) {
            // maintain the max deque
            while (!maxDeque.empty() && nums[j] > maxDeque.back()) {
                maxDeque.pop_back();
            }
            maxDeque.push_back(nums[j]);

            // maintain the min deque
            while (!minDeque.empty() && nums[j] < minDeque.back()) {
                minDeque.pop_back();
            }
            minDeque.push_back(nums[j]);

            // if the current window is invalid, shrink it from the left
            while (!maxDeque.empty() && !minDeque.empty() && maxDeque.front() - minDeque.front() > limit) {
                if (maxDeque.front() == nums[i]) {
                    maxDeque.pop_front();
                }
                if (minDeque.front() == nums[i]) {
                    minDeque.pop_front();
                }
                i++;
            }

            // calculate the length of the current valid window
            count = max(count, j - i + 1);
        }

        return count;
    }
};