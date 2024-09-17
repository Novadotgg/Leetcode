class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        // Note:
        // A word is uncommon if it appears exactly in one of the sentences and not present in the other sentence.
        // Given two sentences we need to return the uncommon words.
        // Best data structure to store the word along with the count or the element and the corresponding value is map
        unordered_map<string, int> mp;
        string curr = "";
        for(auto &ch : s1){
            if(ch == ' '){
                mp[curr]++;
                curr = "";
                continue;
            }
            curr += ch;
        }
        mp[curr]++;
        curr = "";
        for(auto &ch : s2){
            if(ch == ' '){
                mp[curr]++;
                curr = "";
                continue;
            }
            curr += ch;
        }
        mp[curr]++;
        vector<string> ans;
        for(auto &ele : mp){
            if(ele.second == 1) ans.push_back(ele.first);
        }
        return ans;
    }
};