class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int operations = 0;
        
        while (1) {
            set<int> s(nums.begin(), nums.end());
            if (s.size() == nums.size()) {
                return operations;
            }
            if (nums.size() <= 3) {
                nums.clear();
            } else {
                nums.erase(nums.begin(), nums.begin() + 3);
            }
            operations++;
        }
        return operations;
    }
};
