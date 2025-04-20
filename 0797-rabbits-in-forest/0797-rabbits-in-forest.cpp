class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int total=0;
        unordered_map<int,int> mp;
        for(int i:answers)mp[i]++;
        for(auto& p:mp){
            total+=ceil((double)p.second/(p.first+1))*(p.first+1);
        }
        return total;
    }
};