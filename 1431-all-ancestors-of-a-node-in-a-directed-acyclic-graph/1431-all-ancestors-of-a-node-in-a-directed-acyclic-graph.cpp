// class Solution {
// public:
//     vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
//         vector<vector<int>> ans(n), dc(n);
//         for(auto& e:edges){
//             dc[e[0]].push_back(e[1]);
//         }
//         for(int i=0;i<n;i++){
//             dfs(i,i,ans,dc);
//         }
//         return ans;
//     }
// private:
// void dfs(int x,int current, vector<vector<int>>& ans,vector<vector<int>> dc){
//     for(int ch: dc[current]){
//         if(ans[ch].empty() || ans[ch].back()!=x){
//             ans[ch].push_back(x);
//             dfs(x,ch,ans,dc);
//         }
//     }
// }
// };
class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> ans(n), adj(n);
        vector<set<int>> ancestors(n);
        
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
        }
        
        for (int i = 0; i < n; i++) {
            dfs(i, i, ancestors, adj);
        }
        
        for (int i = 0; i < n; i++) {
            ans[i] = vector<int>(ancestors[i].begin(), ancestors[i].end());
        }
        
        return ans;
    }
    
private:
    void dfs(int ancestor, int current, vector<set<int>>& ancestors, vector<vector<int>>& adj) {
        for (int child : adj[current]) {
            if (ancestors[child].insert(ancestor).second) { // Only continue if ancestor was newly added
                dfs(ancestor, child, ancestors, adj);
            }
        }
    }
};
