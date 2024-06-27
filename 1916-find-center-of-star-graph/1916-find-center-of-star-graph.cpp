class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        map<int, int> mp;
        for(int i=0;i<edges.size();i++){
            mp[edges[i][0]]++;
            mp[edges[i][1]]++;
        }
        int n=0;
        for(auto a:mp){
            n++;
        }
        for(auto b:mp){
            if(b.second==n-1){
                return b.first;
            }
        }
        return 1;
    }
};