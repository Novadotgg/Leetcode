// class Solution {
// public:
//     vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
//         vector<int> ans;
//         // vector<int>& a;
//         // vector<int>& b;
//         // for(int i=0;i<nums1.size();i++){
//         //     a.insert(nums1[i]);
//         // }
//         // for(int i=0;i<nums2.size();i++){
//         //     if(a.find(nums2[i])!=a.end()){
//         //         b.insert(nums2[i]);
//         //     }
//         // }
//         // for(auto it:b){
//         //     ans.push_back(it);
//         // }
//         // return ans;
//         sort(nums1.begin(),nums1.end());
//         sort(nums2.begin(),nums2.end());
//         int n=nums1.size();
//         int m=nums2.size();
//         int i=0;
//         int j=0;
//         while(i<n && j<m){
//             if(nums1[i]==nums2[j]){
//                 ans.push_back(nums1[i]);
//                 i++;
//                 j++;
//             }
//             else if(nums1[i]<nums2[i]){
//                 i++;
//             }
//             else{
//                 j++;
//             }   
//         }
//         return ans;
//     }
// };
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        map<int,int> count;
        vector<int> ans;
        for(int i=0;i<nums1.size();i++)
        {
            count[nums1[i]]++;
        }
        
        for(int i=0;i<nums2.size();i++)
        {
            if(count[nums2[i]])
            {
                ans.push_back(nums2[i]);
                count[nums2[i]]--;
            }
        }
        return ans;
    }
};