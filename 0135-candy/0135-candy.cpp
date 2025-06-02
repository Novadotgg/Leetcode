class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        vector<int> candy(n,1);
        /*
        1. Give each child 1 candy initially.
        2. From left to right:
            - If current child's rating is greater than the left neighbor,
            give current child (left neighbor's candies + 1).
        3. From right to left:
            - If current child's rating is greater than the right neighbor,
            set current child's candy = max(current, right neighbor's candy + 1).
        4. Sum all candies and return.
        */
        
        int sum=0;
        //One case from left to right
        for(int i=1;i< n;i++){
            if(ratings[i]>ratings[i-1]){
                candy[i]=candy[i-1]+1;
            }   
        }
        //Second case from right to left
        for (int i = n - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                candy[i] = max(candy[i], candy[i + 1] + 1);
            }
        }



        for(int i=0;i<n;i++){
            sum+=candy[i];
        }
        return sum;
    }
};