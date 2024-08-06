class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        // int count=0;
        // vector<int> ans;
        // for(int i=0;i<sentences.size();i++){
        //     if(sentences[i]==''){
        //         count+=1;
        //     }
        //     if(sentences[i]==','){
        //         ans.push_back(count);
        //         count=0;
        //     }
        // }
        // return max(count);
        int maxWords = 0;  // To store the maximum number of words found
        for (int i = 0; i < sentences.size(); i++) {
            int count = 1; // Start counting words from 1 (the first word)
            for (int j = 0; j < sentences[i].size(); j++) {
                if (sentences[i][j] == ' ') {
                    count++;
                }
            }
            maxWords = max(maxWords, count);
        }

        return maxWords;
    }
};