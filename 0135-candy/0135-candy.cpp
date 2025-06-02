class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        vector<int> candy(n,1);
        /*
        map both the array of candy and ratings
        Then check
            if the current's neighbour rating is more than current rating
                then  increase the neighbour candy by 1
            else increase the current candy by 1
            then incremenet the current then again check until current is taken to  the last
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