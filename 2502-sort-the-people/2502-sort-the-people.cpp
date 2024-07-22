class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n=names.size();
        unordered_map<int, string> m;
        for(int i=0;i<n;i++){
            m[heights[i]]=names[i];
        }
        sort(heights.rbegin(),heights.rend());
        for(int i=0;i<n;i++){
            names[i]=m[heights[i]];
        }
        return names;
    }
};