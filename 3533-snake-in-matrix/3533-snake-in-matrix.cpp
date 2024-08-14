class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& commands) {
        int x=0,y=0, d=commands.size();
        for(int i=0;i<d;i++){
            string s=commands[i];
            if(s=="UP") x--;
            else if(s=="DOWN") x++;
            else if(s=="RIGHT") y++;
            else y--;
        }
        return (x*n)+y;
    }
};