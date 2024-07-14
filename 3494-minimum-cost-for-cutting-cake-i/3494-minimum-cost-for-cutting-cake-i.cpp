class Solution {
public:
    int minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {
    sort(horizontalCut.rbegin(), horizontalCut.rend());
    sort(verticalCut.rbegin(), verticalCut.rend());

    int totalCost = 0;
    int horizontalPieces = 1;
    int verticalPieces = 1;
    int i = 0;
    int j = 0;
    while (i < horizontalCut.size() && j < verticalCut.size()) {
        if (horizontalCut[i] > verticalCut[j]) {
            totalCost += horizontalCut[i] * verticalPieces;
            horizontalPieces++;
            i++;
        } else {
            totalCost += verticalCut[j] * horizontalPieces;
            verticalPieces++;
            j++;
        }
    }
  
    while (i < horizontalCut.size()) {
        totalCost += horizontalCut[i] * verticalPieces;
        horizontalPieces++;
        i++;
    }
    while (j < verticalCut.size()) {
        totalCost += verticalCut[j] * horizontalPieces;
        verticalPieces++;
        j++;
    }

    return totalCost;
    }
};