class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int left = 0, noOfWhiteBlocks = 0, minBlocksToRecolor = INT_MAX;

        for (int right = 0; right < blocks.size(); right++) {
            if (blocks[right] == 'W') {
                noOfWhiteBlocks++; // Count the number of white blocks in the current window
            }

            // When the window reaches size k
            if (right - left + 1 == k) {
                minBlocksToRecolor = min(minBlocksToRecolor, noOfWhiteBlocks); // Update the minimum recoloring needed
                
                // If we already found a perfect window, return immediately
                if (minBlocksToRecolor == 0) return 0;

                // Slide the window: If the leftmost block is white, reduce the count
                if (blocks[left] == 'W') {
                    noOfWhiteBlocks--;
                }

                left++; // Move the window forward
            }
        }

        return minBlocksToRecolor;
    }
};