class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        map<int, int> mp;
        sort(nums.begin(),nums.end());
        int res=-1;
        for(int num:nums){
            int sqt=sqrt(num);
            if(sqt*sqt==num && mp.find(sqt)!=mp.end()){
                mp[num]=mp[sqt]+1;
                res=max(res,mp[num]);
            }
            else mp[num]=1;
        }
        return res;
    }
};