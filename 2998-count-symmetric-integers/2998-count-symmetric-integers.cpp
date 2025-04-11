class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int count = 0;

        while (low <= high) {
            vector<int> help;
            int temp = low;
            while (temp > 0) {
                help.push_back(temp % 10);
                temp /= 10;
            }

            int n = help.size();
            if (n % 2 == 0) {
                int mid = n / 2;
                int leftSum = 0, rightSum = 0;

                for (int i = 0; i < mid; ++i)
                    leftSum += help[i];
                for (int i = mid; i < n; ++i)
                    rightSum += help[i];

                if (leftSum == rightSum)
                    count++;
            }

            low++;
        }

        return count;
    }
};
