class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        if(arr.size()==0)return 0;
        int count=0,maxi=0;
        for(int i=0;i<arr.size();i++){
            // maxi=max(maxi,arr[i]);
            // count++;
            maxi+=arr[i]-i;
            count+=(maxi==0);
        }
        return count;
    }
};