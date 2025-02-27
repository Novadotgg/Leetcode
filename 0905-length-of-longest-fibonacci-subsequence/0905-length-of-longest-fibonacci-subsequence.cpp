class Solution {
public:
    int longest(int i, int j, vector<int>& arr, map<int, int>& mpp) {
        // use map to find indexes quicly
        // agr arr[i] + arr[j] nhi mila to return ho jao 2 deke
        if (mpp.find(arr[i] + arr[j]) == mpp.end()) return 2;

        int nextElement = arr[i] + arr[j];
        int maxLength = 2;

        for (int k = j + 1; k < arr.size(); k++) {
            if (arr[k] == nextElement) {
                maxLength = max(maxLength, 1 + longest(j, k, arr, mpp));
                break;  // Once we find the next element, we continue the sequence.
            }
        }
        return maxLength;
    }

    int lenLongestFibSubseq(vector<int>& arr) {
        map<int, int> mpp;
        // use map to find indexes quicly
        for (int num : arr) {
            mpp[num] = 1;
        }

        int maxLength = 0;
        // generate all possible subsequences 
        for (int i = 0; i < arr.size() - 2; i++) {
            for (int j = i + 1; j < arr.size() - 1; j++) {
                // find the Longest FIb subsequence among them
                maxLength = max(maxLength, longest(i, j, arr, mpp));
            }
        }
        return maxLength > 2 ? maxLength : 0;
    }
};