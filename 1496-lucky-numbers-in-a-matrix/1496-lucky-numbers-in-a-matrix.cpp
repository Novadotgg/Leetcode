// class Solution {
// public:
//     vector<int> luckyNumbers (vector<vector<int>>& matrix) {
//         int ans;
//         for(int i=0;i<matrix.size();i++){
//             for(int j=0;j<matrix.size();j++){
//                 if(j==0 && i!=j|| i==j){
//                     if(i==0 && i!=j || i==j){
//                         ans=min(matrix[i][j]);
//                     }
//                 } 
//             }
//         }
//     return ans;
//     }
// };
class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> luckyNumbers;

        for (int i = 0; i < n; i++) {
            int num = numeric_limits<int>::max();
            int index = -1;
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] < num) {
                    num = matrix[i][j];
                    index = j;
                }
            }
            bool flag = true;
            for (int row = 0; row < n; row++) {
                if (matrix[row][index] > num) {
                    flag = false;
                    break;
                }
            }

            if (flag) {
                luckyNumbers.push_back(num);
            }
        }

        return luckyNumbers;
    }
};