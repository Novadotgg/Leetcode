class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        // unordered_map<int, int>m;
        // sort(nums.begin(),nums.end());
        // int count=0;
        // m.first()=nums;
        // for(int i=1;i<nums.size();i++){
        //     if(nums[i-1]==nums[i]){
        //         count++;
        //         m.second()=count
        //     }
        //     count=0;
        // }
        // sort(m.second.begin(),m.second.end());
        // return m;
         unordered_map<int, int> freqMap;
        
        // Step 1: Count the frequency of each number
        for (int num : nums) {
            freqMap[num]++;
        }

        // Step 2: Sort the numbers based on frequency and value
        sort(nums.begin(), nums.end(), [&freqMap](int a, int b) {
            if (freqMap[a] == freqMap[b]) {
                return a > b;  // If frequencies are the same, sort by value in descending order
            }
            return freqMap[a] < freqMap[b];  // Sort by frequency in ascending order
        });
        
        return nums;
    }
};