/*Given an integer array nums, you need to find one continuous subarray that if you only sort this subarray in ascending order, then the whole array will be sorted in ascending order.

Return the shortest such subarray and output its length.

*/





class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n=nums.size();
        int minn=INT_MAX,maxx=-1*INT_MAX;
        bool fl=0;
        for(int i=1;i<n;i++)
        {
            if(nums[i]<nums[i-1])fl=1;
            if(fl)minn=min(minn,nums[i]);
        }
        fl=0;
        for(int i=n-2;i>=0;i--)
        {
            if(nums[i]>nums[i+1])fl=1;
            if(fl)maxx=max(maxx,nums[i]);
        }
        int i=0,j=n-1;
        for(i=0;i<n;i++)
        {
            if(minn<nums[i])break;
        }
        for(j=n-1;j>=0;j--)
        {
            if(maxx>nums[j])break;
        }
        if(j-i>=0)return j-i+1;
        return 0;
    }
};
//TC:O(N)