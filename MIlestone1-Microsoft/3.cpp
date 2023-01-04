/*You are playing the Bulls and Cows game with your friend.

You write down a secret number and ask your friend to guess what the number is. When your friend makes a guess, you provide a hint with the following info:

The number of "bulls", which are digits in the guess that are in the correct position.
The number of "cows", which are digits in the guess that are in your secret number but are located in the wrong position. Specifically, the non-bull digits in the guess that could be rearranged such that they become bulls.
Given the secret number secret and your friend's guess guess, return the hint for your friend's guess.

The hint should be formatted as "xAyB", where x is the number of bulls and y is the number of cows. Note that both secret and guess may contain duplicate digits.

*/





class Solution {
public:
    string getHint(string secret, string guess) {
        string ans="";
        map<char,int>mp;
        for(int i=0;i<secret.size();i++)
        {
            mp[secret[i]]++;
        }
        int a=0,b=0;
        vector<int>vis(guess.size(),0);
        for(int i=0;i<secret.size();i++)
        {
            if(secret[i]==guess[i])
            {
                a++;
                mp[secret[i]]--;
                vis[i]=1;
            }
        }
        for(auto x:mp)
        {
            map<char,int>mp1;
            for(int i=0;i<guess.size();i++)
            {
                if(!vis[i])
                {
                    if(guess[i]==x.first)mp1[x.first]++;
                }
            }
            if(mp1.find(x.first)!=mp1.end())
            {
                if(mp1[x.first]<x.second)b+=mp1[x.first];
                else b+=x.second;
            }
        }
        ans+=to_string(a)+"A"+to_string(b)+"B";
        return ans;
    }
};

//TC:O(N)