/*Given a set of distinct positive integers nums, return the largest subset answer such that every pair (answer[i], answer[j]) of elements in this subset satisfies:

answer[i] % answer[j] == 0, or
answer[j] % answer[i] == 0
If there are multiple solutions, return any of them.

 */






class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        
        int n = nums.size();
        
       
        sort(nums.begin(), nums.end());
        
        vector<int> dp(n, 1);
        
        for(int i = 0; i < n; i++)
        {
            for(int j = i - 1; j >= 0; j--)
            {
                if(nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1)
                {
                    dp[i] = dp[j] + 1;
                }
            }
        }
        
        
        int maxi = *max_element(dp.begin(), dp.end());
        
        
        int max_idx = 0;
        
        for(int i = 0; i < n; i++)
        {
            if(dp[i] == maxi)
            {
                max_idx = i;
                
                break;
            }
        }
        
        
        vector<int> res;
        
        int i = max_idx;
        
        res.push_back(nums[i]);
        
        int prev = nums[i];
        
        maxi--;
        
        i--;
        
        while(i >= 0 && maxi)
        {
            if(dp[i] == maxi && prev % nums[i] == 0)
            {
                res.push_back(nums[i]);
                
                prev = nums[i];
                
                maxi--;
            }
            
            i--;
        }
        
        return res;
    }
};