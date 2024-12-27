class Solution {
public:
    int score=0;
    int f(int i, vector<int>& values){
        if (i<0) return 0;
    
        int x=values[i], prev=f(i-1, values);
        score=max(score, prev+x-i);
        return max(prev, x+i);
    }
    int maxScoreSightseeingPair(vector<int>& values) {
        const int n=values.size();

        f(n-1, values);
        return score;
    }
};