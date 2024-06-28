class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        // bool visited=false;
        // vector<int> degree(n,0);
        long ans=0,c=1;
        vector<int> connect(n,0);
        for(auto it:roads){
            connect[it[0]]++;
            connect[it[1]]++;
        }
        sort(connect.begin(),connect.end());
        for(auto it:connect) ans+=it*(c++);
        return ans;


    }
};