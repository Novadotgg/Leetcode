
/*
                [3,3]
            (2,2)    
    [1,1]
(0,0)       

x2-x1 =a
y2-y1=b
a*b is the area

                
                [2,1]
[1,0]    1,1  
0,0         

*/



class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        // for(int i=0;i<4;i++){
        //     //First find the intersection coordinates
            
        // }
        int x1=max(rec1[0],rec2[0]);
        int x2=min(rec1[2],rec2[2]);

        int y1=max(rec1[1],rec2[1]);
        int y2=min(rec1[3],rec2[3]);


        int length=x2-x1;
        int width=y2-y1;

        if(length>0 && width>0){
            return true;
        }
        return false;

    }
};