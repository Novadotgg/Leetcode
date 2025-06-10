// class Solution {
// public:
//     int maxDifference(string s) {
//         unordered_map<char, int> mp;
//         for(char i:s){
//             mp[i]++;
//         }
//         vector<int> even;
//         vector<int>odd;
//         for(auto &i:mp){
//             if(i.second%2==0)even.push_back(i.second);
//             else odd.push_back(i.second);
//         }
//         if(odd.empty()||even.empty())return -1;
//         int e=*max_element(even.begin(),even.end());
//         int o=*max_element(odd.begin(),odd.end());
//         return abs(e - o);
//     }
// };
class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char, int> mp;

        // Step 1: Count character frequencies
        for (char c : s) {
            mp[c]++;
        }

        vector<int> oddFreq;
        vector<int> evenFreq;

        // Step 2: Separate odd and even frequencies
        for (auto &p : mp) {
            if (p.second % 2 == 0)
                evenFreq.push_back(p.second);
            else
                oddFreq.push_back(p.second);
        }

        // Step 3: If no valid pair exists
        if (oddFreq.empty() || evenFreq.empty()) {
            return -1;
        }

        // Step 4: Compute max difference
        int maxOdd = *max_element(oddFreq.begin(), oddFreq.end());
        int minEven = *min_element(evenFreq.begin(), evenFreq.end());

        return maxOdd - minEven;
    }
};
