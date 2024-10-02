class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        unordered_map<int,int> m;
        vector<int> s=arr;
        sort(s.begin(),s.end());
        s.erase(unique(s.begin(),s.end()),s.end());
        for(int i=0;i<s.size();i++){
            m[s[i]]=i+1;
        }
        for(int i=0;i<arr.size();i++){
            arr[i]=m[arr[i]];
        }
        return arr;

    }
};