class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        vector<int> c1(1001);
        vector<int> c2(1001);
        for(int &i:target){
            ++c1[i];
        }
        for(int &i:arr){
            ++c2[i];
        }
        return c1==c2;
    }
};