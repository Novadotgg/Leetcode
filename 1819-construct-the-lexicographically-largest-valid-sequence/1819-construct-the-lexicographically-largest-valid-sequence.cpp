class Solution {
public: 
    int target;
    vector<int> ans, temp;
    unordered_set<int> taken;

    bool solve(int n, int idx) {

        while(idx < target && temp[idx] != 0)
            ++idx;

        if(idx == target) {
            ans = temp;
            return true;
        }

        for(int num = n; num >= 1; --num) {
            if(taken.find(num) != taken.end())
                continue;

            if(num == 1) {
                temp[idx] = 1;
                taken.insert(1);

                if(solve(n, idx + 1))
                    return true;

                temp[idx] = 0;
                taken.erase(1);
            }

            else {
                int j = idx + num;

                if(j < target && temp[j] == 0) {
                    temp[idx] = temp[j] = num;
                    taken.insert(num);

                    if(solve(n, idx + 1))
                        return true;

                    temp[idx] = temp[j] = 0;
                    taken.erase(num);
                }
            }
        }

        return false;
    }

    vector<int> constructDistancedSequence(int n) {
        target = n * 2 - 1;
        ans.resize(target);
        temp.resize(target);

        solve(n, 0);
        return ans;
    }
};