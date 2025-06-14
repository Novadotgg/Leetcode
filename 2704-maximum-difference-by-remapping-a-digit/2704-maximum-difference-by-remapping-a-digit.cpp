class Solution {
public:
    int minMaxDifference(int num) {
        string s = to_string(num);

        // --- Maximize ---
        // Replace the first non-9 digit with 9 everywhere
        string maxStr = s;
        for (char c : s) {
            if (c != '9') {
                char from = c;
                for (char &ch : maxStr) {
                    if (ch == from) ch = '9';
                }
                break; // Only one remap allowed
            }
        }

        // --- Minimize ---
        // Replace the first digit (not '0') with 0 everywhere
        string minStr = s;
        for (char c : s) {
            if (c != '0') {
                char from = c;
                for (char &ch : minStr) {
                    if (ch == from) ch = '0';
                }
                break;
            }
        }

        int maxVal = stoi(maxStr);
        int minVal = stoi(minStr);

        return maxVal - minVal;
    }
};
