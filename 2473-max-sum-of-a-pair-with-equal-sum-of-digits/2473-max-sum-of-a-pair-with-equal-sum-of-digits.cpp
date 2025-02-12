// class Solution {
// public:
//     int maximumSum(vector<int>& nums) {
//         int maxi=0;
//         vector<int> check(nums.size());
//         vector<int> yo;
//         for(int i=0;i<nums.size();i++){
//             check.push_back(nums[i]%10+nums[i]/10);
//         }
//         for(int i=1;i<check.size();i++){
//             if(check[i]==check[i-1]){
//                 yo.push_back(i);
//             }
//         }
//         maxi=nums[yo[i]]+nums[yo[i+1]];
//         int maxu=max(maxu,maxi);
//     }
// };
class Solution {
public:
    int maximumSum(vector<int>& nums) {
        int max[82] = {0};
        int ans = -1;
        for (int x : nums) {
            int sum = 0, temp = x;
            while (temp != 0) {
                sum += temp % 10;
                temp /= 10;
            }
            if (max[sum] != 0) ans = std::max(ans, x + max[sum]);
            max[sum] = std::max(max[sum], x);
        }
        return ans;
    }
};