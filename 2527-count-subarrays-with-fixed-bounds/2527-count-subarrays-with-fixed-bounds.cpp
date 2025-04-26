class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long count = 0;
        int minPos = -1, maxPos = -1, leftBound = -1;

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] < minK || nums[i] > maxK) {
                leftBound = i; // reset window
            }
            if (nums[i] == minK) minPos = i;
            if (nums[i] == maxK) maxPos = i;

            int validStart = min(minPos, maxPos);
            count += max(0, validStart - leftBound);
        }
        return count;
    }
};
