class Solution {
public:
    long long minimumSteps(string s) {
        vector<int> black_positions;
        int n = s.size();
        
        // Step 1: Collect positions of all '1's (black balls)
        for (int p = 0; p < n; p++) {
            if (s[p] == '1') {
                black_positions.push_back(p);
            }
        }
        
        long long count = 0;  // Variable to track the total number of swaps
        int m = black_positions.size();
        
        // Step 2: Calculate the minimum swaps to group all '1's to the right
        for (int i = 0; i < m; i++) {
            // Target position for the ith black ball is where the i-th '1' should go
            int target_position = n - m + i;
            
            // Add the distance between the current position and the target position
            count += target_position - black_positions[i];
        }
        
        return count;
    }
};
