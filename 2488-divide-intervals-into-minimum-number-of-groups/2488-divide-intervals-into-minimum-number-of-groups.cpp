class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        vector<int> start_t,end_t;
        for(const auto& interval:intervals){
            start_t.push_back(interval[0]);
            end_t.push_back(interval[1]);
        }
        sort(start_t.begin(),start_t.end());
        sort(end_t.begin(),end_t.end());
        int pointer=0, group=0;
        for(int start:start_t){
        
                if(start>end_t[pointer]){
                    pointer++;
                }
                else{
                    group++;
                }
           
        }
        return group;
    }
};