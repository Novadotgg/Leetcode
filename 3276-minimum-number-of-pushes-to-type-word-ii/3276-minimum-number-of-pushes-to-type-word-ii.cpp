class Solution {
public:
    int minimumPushes(string word) {
        // int count=0;
        // unordered_map<int, char> m;
        vector<int> count(26);
        for(char& c:word){
            ++count[c-'a'];
        }
        sort(count.rbegin(),count.rend());
        int ans=0;
        for(int i=0;i<26;i++){
            ans+=(i/8+1)*count[i];
        }
        return ans;
    }
};