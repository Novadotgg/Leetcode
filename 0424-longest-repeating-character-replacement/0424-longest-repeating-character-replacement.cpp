/*
unordered mapping
ABAB
S 0
B 1
A 2
B 3
same character difference check 
if difference is less than or equal to k 
then swap it to the number of that character whose value is been identified
*/

class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> count;
        int maxFreq = 0, res = 0;
        int left = 0;
        
        for (int right = 0; right < s.size(); right++) {
            count[s[right]]++;
            maxFreq = max(maxFreq, count[s[right]]);
            
            // if current window size - maxFreq > k, shrink the window
            while ((right - left + 1) - maxFreq > k) {
                count[s[left]]--;
                left++;
            }
            
            res = max(res, right - left + 1);
        }
        
        return res;
    }
};
