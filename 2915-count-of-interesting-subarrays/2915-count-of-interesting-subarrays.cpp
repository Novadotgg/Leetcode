// class Solution {
//     public:
//         int countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
//             int res = 0;
    
//             for (int i = 0; i < nums.size(); i++) {
//                 int cnt = 0;
//                 for (int j = i; j < nums.size(); j++) {
//                     if (nums[j] % modulo == k) cnt++;
//                     if (cnt % modulo == k) res++;
//                 }
//             }
//             return res;
//         }
//     };
class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        long long count = 0, equals = 0;
        unordered_map<int, long long> mpp;
        mpp[0] = 1;

        for (int i : nums) {
            if (i % modulo == k) equals++;

            int rem = equals % modulo;
            int needed = (rem - k + modulo) % modulo;

            count += mpp[needed];
            mpp[rem]++;
        }

        return count;
    }
};