class Solution {
public:
    bool divideArray(vector<int>& nums) {
        if(nums.size()%2!=0)return false;
        unordered_map<int,int> m;
        for(int i:nums){
            m[i]++;
        }
        for(auto i:m){
            if(i.second%2!=0){
                return false;
            }
        }
        return true;


    }
};