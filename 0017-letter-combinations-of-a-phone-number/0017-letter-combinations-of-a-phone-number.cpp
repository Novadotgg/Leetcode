class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
        unordered_map<char, string> m={
            {'2',"abc"}, {'3',"def"}, {'4',"ghi"}, {'5',"jkl"}, {'6',"mno"}, {'7',"pqrs"}, {'8',"tuv"}, {'9',"wxyz"}
        };
        vector<string> result;
        string current;
        backtrack(digits, m, 0,current, result);
        return result;
    }
    private:
        void backtrack(const string& digits, unordered_map<char, string>& m,int index, string& current, vector<string>& result){
           if(index==digits.size()){
            result.push_back(current);
            return;
           }
           char digit=digits[index];
           const string& letters=m[digit];
           for(char letter:letters){
            current.push_back(letter);
            backtrack(digits,m,index+1,current, result);
            current.pop_back();
           } 
        }
};