class Solution {

    private:
    string getNext(const string& s) {
        string next = "";
        int count = 1;
        
        for (size_t i = 1; i < s.size(); ++i) {
            if (s[i] == s[i - 1]) {
                ++count;
            } else {
                next += to_string(count) + s[i - 1];
                count = 1;
            }
        }
        // Handle the last group of characters
        next += to_string(count) + s.back();
        return next;}
public:
    string countAndSay(int n) {
        // int count=0;
        // vector<int> ans;
        // int i=0;
        // while(i<n){
        //     if(n[i]==n[i+1]){
        //         ans[i+1].push_back(n[i]);
        //         count+=1;
        //         ans[i].push_back(count);
        //         i++;
        //         count=0;
        //     }
        // }
        // return ans;
        if (n == 1) return "1";
        
        string result = "1";
        for (int i = 1; i < n; ++i) {
            result = getNext(result);
        }
        return result;
    }
};