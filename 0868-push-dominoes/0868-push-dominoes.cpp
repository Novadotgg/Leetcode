// class Solution {
// public:
//     string pushDominoes(string dominoes) {
//         string prev;
//         string curr = dominoes;

//         do {
//             prev = curr;
//             string next = curr;
//             for (int i = 0; i < curr.size(); i++) {
//                 if (curr[i] == '.') {
//                     if (i - 1 >= 0 && curr[i - 1] == 'R' && (i + 1 >= curr.size() || curr[i + 1] != 'L')) {
//                         next[i] = 'R';
//                     }
//                     if (i + 1 < curr.size() && curr[i + 1] == 'L' && (i - 1 < 0 || curr[i - 1] != 'R')) {
//                         next[i] = 'L';
//                     }
//                 }
//             }
//             curr = next;
//         } while (curr != prev); // Repeat until no change

//         return curr;
//     }
// };
class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size();
        vector<int> forces(n, 0);

        // Left to right: apply positive force from 'R'
        int force = 0;
        for (int i = 0; i < n; i++) {
            if (dominoes[i] == 'R') force = n;
            else if (dominoes[i] == 'L') force = 0;
            else force = max(force - 1, 0);
            forces[i] += force;
        }

        // Right to left: apply negative force from 'L'
        force = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (dominoes[i] == 'L') force = n;
            else if (dominoes[i] == 'R') force = 0;
            else force = max(force - 1, 0);
            forces[i] -= force;
        }

        // Final result
        string result;
        for (int f : forces) {
            if (f > 0) result += 'R';
            else if (f < 0) result += 'L';
            else result += '.';
        }

        return result;
    }
};
