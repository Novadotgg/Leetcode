
// /*
// 3 digin number
// set()
// find all the possible combination with the numbers
// put the numbers in the set
// count = 0
// numbers in the set % 2 == 0: count ++;
// return count


// */


// class Solution {
// public:
//     int totalNumbers(vector<int>& digits) {
//         int n=digits.size();
//         if(n<3)return 0;
//         set<int> numbers;
//         int count=0;
        
//         for(int i=0;i<pow(2,n);i++){
//             vector<int> current;
//             int temp=i;
//             for(int j=0;j<n;j++){
//                 if(temp % 2 == 1){
//                     current.push_back(digits[j]);
//                     if(current.size()==3){
//                         int formed = current[0]*100 + current[1]*10 + current[2];
//                         numbers.insert(formed);
//                     }
//                     current.clear();
//                 }
//                 temp=temp/2;
//             }
//         }
//         for(auto it:numbers){
//             if(it%2==0){
//                 count++;
//             }
//         }
//         return count;
//     }
// };
class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int n = digits.size();

        if(n < 3)
            return 0;

        set<int> numbers;
        int count = 0;

        // Choose first digit
        for(int i = 0; i < n; i++) {

            // 3-digit number cannot start with 0
            if(digits[i] == 0)
                continue;

            // Choose second digit
            for(int j = 0; j < n; j++) {

                if(j == i)
                    continue;

                // Choose third digit
                for(int k = 0; k < n; k++) {

                    if(k == i || k == j)
                        continue;

                    int formed = digits[i] * 100
                               + digits[j] * 10
                               + digits[k];

                    numbers.insert(formed);
                }
            }
        }

        // Count even numbers
        for(auto it : numbers) {
            if(it % 2 == 0)
                count++;
        }

        return count;
    }
};