// There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

// For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
// Return true if you can finish all courses. Otherwise, return false.

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
       int n= prerequisites.size();
       vector<int>adj[numCourses];
       for(int i=0;i<n;i++)
       {
           int u= prerequisites[i][0];
           int v= prerequisites[i][1];
           adj[u].push_back(v);
       }
       vector<int>indegree(numCourses);
       for(int i=0;i<numCourses;i++)
       {
           for(auto x:adj[i])
           {
               indegree[x]++;
           }
       }
       queue<int>q;
       vector<int>ans;
       for(int i=0;i<numCourses;i++)
       {
           if(indegree[i]==0)q.push(i);
       }
       while(!q.empty())
       {
           auto node=q.front();
           q.pop();
            if(indegree[node]==0)
            {
                ans.push_back(node);
            }
            for(auto x:adj[node])
            {
                indegree[x]--;
                if(indegree[x]==0)q.push(x);
            }
       }
       if(ans.size()==numCourses)return true;
       return false;
    }
};

//TC:O(V+E)