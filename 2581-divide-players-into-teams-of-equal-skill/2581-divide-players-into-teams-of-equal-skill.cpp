class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(), skill.end());  
        
        long long ans = 0;  
        int check = 0;  
        int a = 0;  
        int b = skill.size() - 1;  
        
        check = accumulate(skill.begin(), skill.end(), 0);  
        if (check % (skill.size() / 2) != 0) {
            return -1;  
        }
        
        int targetSum = check / (skill.size() / 2); 
       
        while (a < b) {
            if (skill[a] + skill[b] != targetSum) {
                return -1; 
            }
            ans += skill[a] * skill[b];  
            a++;  
            b--;  
        }
        
        return ans;  
    }
};
