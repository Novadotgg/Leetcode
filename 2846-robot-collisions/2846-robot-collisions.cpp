class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        // for(int i=0;i<positions.size();i++){
        //     if(direction[i]=='R'){
        //         position[i]++;
        //     }
        //     if(direction[i]=='L'){
        //         position[i]--;
        //     }
        //     if(position[i]==position[i+1]){
        //         if(healts[i]<healths[i+1]){
        //             delete(healts[i]);
        //         }
        //     }
        // }
        int n = positions.size();
        vector<int> indices(n);
    
        for (int i = 0; i < n; ++i) {
            indices[i] = i;
        }
        sort(indices.begin(), indices.end(), [&](int a, int b) {
            return positions[a] < positions[b];
        });

        stack<int> st; 

        for (int idx : indices) {
            if (directions[idx] == 'R') {
                st.push(idx);
            } else { 
                while (!st.empty() && healths[idx] > 0) {
                    int topIdx = st.top();
                    if (healths[topIdx] < healths[idx]) {
                        healths[idx] -= 1;
                        st.pop();
                        healths[topIdx] = 0; 
                    } else if (healths[topIdx] > healths[idx]) {
                        healths[topIdx] -= 1;
                        healths[idx] = 0;
                    } else {
                        healths[topIdx] = 0; 
                        healths[idx] = 0;
                        st.pop();
                    }
                }
            }
        }
        vector<int> result;
        for (int i = 0; i < n; ++i) {
            if (healths[i] > 0) {
                result.push_back(healths[i]);
            }
        }
        
        return result;
    }
};