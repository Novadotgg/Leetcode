#include <vector>
using namespace std;

class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        // First Pass: Merge equal adjacent numbers
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] == nums[i + 1]) {
                nums[i] *= 2;
                nums[i + 1] = 0;
            }
        }

        // Second Pass: Move all nonzero elements to the left
        int j = 0; // Pointer for placing nonzero elements
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                swap(nums[i], nums[j]);
                j++; // Move nonzero index forward
            }
        }

        return nums;
    }
};
