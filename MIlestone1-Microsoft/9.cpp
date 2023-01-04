/*You are given two 0-indexed integer arrays nums1 and nums2, each of size n, and an integer diff. Find the number of pairs (i, j) such that:

0 <= i < j <= n - 1 and
nums1[i] - nums1[j] <= nums2[i] - nums2[j] + diff.
Return the number of pairs that satisfy the conditions.*/



class Solution {
public:
 long long ans=0;
int solve(int l,int r,vector<int>nums,int diff){
    if(l==r)return 0;
    int mid=l+(r-l)/2;
    long long ans=solve(l,mid,nums,diff)+solve(mid+1,r,nums,diff);
    int l1=l,r1=mid,l2=mid+1,r2=r;
    for(int i=l2;i<=r2;i++)
    {
        long long val=nums[i]+diff;
        int idx=upper_bound(nums.begin()+l1,nums.begin()+r1+1,val)-nums.begin()-1;
        if(idx<=r1)ans+=(idx-l1+1);
    }
    vector<long long>merge;
    while(l1<=r1 && l2<=r2)
    {
        if(nums[l1]<=nums[l2])merge.push_back(nums[l1++]);
        else merge.push_back(nums[l2++]);
    }
    while(l1<=r1)
    {
        merge.push_back(nums[l1++]);
    }
    while(l2<=r2)
    {
        merge.push_back(nums[l2++]);
    }
    for(int i=l;i<=r;i++)
    {
        nums[i]=merge[i-l];
    }
    return ans;
}
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        int n=nums1.size();
       vector<int>nums(n);
       for(int i=0;i<n;i++)
       {
           nums[i]=nums1[i]-nums2[i];
       }
       int l=0,r=nums.size()-1;
       return solve(l,r,nums,diff);
    }
};