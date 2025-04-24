class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int k=unordered_set<int>(nums.begin(),nums.end()).size();
        int r=0;
        for(int i=0;i<nums.size();i++){
            unordered_set<int> s;
            for(int j=i;j<nums.size();j++){
                s.insert(nums[j]);
                if(s.size()==k)r++;
            }
        }
        return r;
    }
};