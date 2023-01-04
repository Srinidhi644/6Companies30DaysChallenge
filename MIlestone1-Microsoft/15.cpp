/*Given a string s consisting only of characters a, b and c.

Return the number of substrings containing at least one occurrence of all these characters a, b and c.*/


class Solution {
public:
    int numberOfSubstrings(string s) {
        int i=0,j=0;
        int n=s.size();
        vector<int>v(3,0);
        int ans=0;
        while(i<n)
        {
            if(j==n)
            {
                 while(v[0]>=1 && v[1]>=1 && v[2]>=1)
            {
                ans+=(n-j+1);
                v[s[i]-'a']--;
                ++i;
            }
            break;
            }
            while(v[0]>=1 && v[1]>=1 && v[2]>=1)
            {
                ans+=(n-j+1);
                v[s[i]-'a']--;
                ++i;
            }
            v[s[j]-'a']++;
            j++;
        }
        return ans;
    }
};

//TC:O(N)