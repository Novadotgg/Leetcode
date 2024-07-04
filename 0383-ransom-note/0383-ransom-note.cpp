class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        // int x=0;
        // for(int it:ransomNote){
        //     x=x^it;
        // }
        // for(int it:magazine){
        //     x=x^it;
        // }
        // // if(x==0)return true;
        // // return false;
        // return x==0;
        int charCount[26] = {0};
        
        // Count each character in the magazine
        for (char c : magazine) {
            charCount[c - 'a']++;
        }
        
        // Check if we can construct the ransom note
        for (char c : ransomNote) {
            if (charCount[c - 'a'] == 0) {
                return false; // Character not available or used up
            }
            charCount[c - 'a']--; // Use the character
        }
        
        return true; // All characters needed are available
    }
};