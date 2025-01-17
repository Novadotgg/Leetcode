class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        vector<int> original={0};
        for(int i=0;i<derived.size();i++){
            original.push_back(original[i]^derived[i]);
        }
        bool check_zero=(original[0]==original[original.size()-1]);
        original={1};
        for(int i=0;i<derived.size();i++){
            original.push_back((derived[i]^original[i]));
        }
        bool check_one=(original[0]==original[original.size()-1]);
        return check_zero|check_one;
    }
};