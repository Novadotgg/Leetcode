class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int count = 0;
        long long total = 0;
        for(int i = 0; i < chalk.size(); i++) {
            total += chalk[i];
        }
        k %= total;
        for(int i = 0; i < chalk.size(); i++) {
            if(k < chalk[i]) {
                count = i;
                break; 
            }
            k -= chalk[i]; 
        }
        
        return count;
    }
};