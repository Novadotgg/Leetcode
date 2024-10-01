// class Solution {
// public:
//     bool canArrange(vector<int>& arr, int k) {
        
//         int n=arr.size();
        
//         if(n/2!=0) return false;
//         sort(arr.begin(),arr.end());
//         int i=0;
//         int j=n-1;
//         // for(int i=0;i<n;i++){
//         //     if(arr[i]+arr[j]==k) return true;
//         //     else{
//         //         i++;
//         //         j--;
//         //     }
//         // }
//         while(i<j){
//             if((arr[i]+arr[j])%k!=0) {return false;}
//             i++;
//             j--;
        
//         }
//         return true;
//     }
// };
class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int> remainderCount(k, 0);
        
        // Calculate remainder frequencies
        for (int num : arr) {
            int remainder = ((num % k) + k) % k;  // Handle negative remainders
            remainderCount[remainder]++;
        }

        // Check pairs
        if (remainderCount[0] % 2 != 0) {
            return false; // Numbers fully divisible by k must be paired with themselves
        }

        for (int i = 1; i <= k / 2; i++) {
            if (remainderCount[i] != remainderCount[k - i]) {
                return false; // Remainder i must be paired with remainder k-i
            }
        }

        return true;  // All conditions are satisfied
    }
};
