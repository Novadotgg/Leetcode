class Solution {
public:
    string pushDominoes(string dominoes) {
        string prev;
        string curr = dominoes;

        do {
            prev = curr;
            string next = curr;
            for (int i = 0; i < curr.size(); i++) {
                if (curr[i] == '.') {
                    if (i - 1 >= 0 && curr[i - 1] == 'R' && (i + 1 >= curr.size() || curr[i + 1] != 'L')) {
                        next[i] = 'R';
                    }
                    if (i + 1 < curr.size() && curr[i + 1] == 'L' && (i - 1 < 0 || curr[i - 1] != 'R')) {
                        next[i] = 'L';
                    }
                }
            }
            curr = next;
        } while (curr != prev); // Repeat until no change

        return curr;
    }
};
