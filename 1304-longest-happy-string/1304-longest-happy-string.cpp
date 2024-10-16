class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string ans = "";
        vector<pair<int, char>> counts = {{a, 'a'}, {b, 'b'}, {c, 'c'}};
        
        while (true) {
            // Sort the counts in descending order based on the number of characters left
            sort(counts.rbegin(), counts.rend());
            
            bool added = false;
            for (int i = 0; i < 3; i++) {
                if (counts[i].first == 0) {
                    continue; // No more characters of this type left
                }
                
                // If the last two characters in the answer are the same as the current character, skip it
                if (ans.size() >= 2 && ans[ans.size() - 1] == counts[i].second && ans[ans.size() - 2] == counts[i].second) {
                    continue;
                }
                
                // Add the character and decrease its count
                ans += counts[i].second;
                counts[i].first--;
                added = true;
                break;
            }
            
            if (!added) {
                // If no character could be added, break the loop
                break;
            }
        }
        
        return ans;
    }
};
