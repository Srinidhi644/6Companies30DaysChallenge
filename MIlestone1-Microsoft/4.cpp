/*You are given an integer array nums of length n.

Assume arrk to be an array obtained by rotating nums by k positions clock-wise. We define the rotation function F on nums as follow:

F(k) = 0 * arrk[0] + 1 * arrk[1] + ... + (n - 1) * arrk[n - 1].
Return the maximum value of F(0), F(1), ..., F(n-1).

The test cases are generated so that the answer fits in a 32-bit integer.*/


class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
       vector<int>v(n);
       int val=0;
       int sum=0;
       for(int i=0;i<n;i++)
       {
           val+=i*nums[i];
           sum+=nums[i];
       }
    v[0]=val;
    for(int i=1;i<n;i++)
    {
        v[i]=sum-n*nums[n-i];
    }
    for(int i=1;i<n;i++)
    {
        v[i]+=v[i-1];
        ans=max(ans,v[i]);
    }
    return ans;
}
};

//TC:O(N)