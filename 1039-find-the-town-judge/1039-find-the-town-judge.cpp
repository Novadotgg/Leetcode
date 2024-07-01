class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if(n==1) return 1;
        unordered_map<int,int> m;

        for(auto it:trust){
            m[it[0]]=-1;
            if(m[it[1]]!=-1)m[it[1]]++;
        }

        for(auto i:m){
            if(i.second==n-1)return i.first;
        }
        return -1;
    }
};