/*You are in a city that consists of n intersections numbered from 0 to n - 1 with bi-directional roads between some intersections. The inputs are generated such that you can reach any intersection from any other intersection and that there is at most one road between any two intersections.

You are given an integer n and a 2D integer array roads where roads[i] = [ui, vi, timei] means that there is a road between intersections ui and vi that takes timei minutes to travel. You want to know in how many ways you can travel from intersection 0 to intersection n - 1 in the shortest amount of time.

Return the number of ways you can arrive at your destination in the shortest amount of time. Since the answer may be large, return it modulo 109 + 7.*/




class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        long long mod=1e9+7;
        vector<vector<pair<long long,long long>>>adj;
        adj.resize(n);
        for(auto it:roads)
        {
            long long u=it[0];
            long long v=it[1];
            long long wt=it[2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
       priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>>pq;
        vector<long long>dist(n,1e18);
        vector<long long>paths(n,0);
        dist[0]=0;
        paths[0]=1;
        pq.push({0,0});
        while(!pq.empty())
        {
            auto it=pq.top();
            long long distance=it.first;
            long long node=it.second;
            pq.pop();
            for(auto x:adj[node])
            {
                long long next=x.first;
                long long dista=x.second;
                if(dist[next]>distance+dista)
                {
                    dist[next]=dist[node]+dista;
                    pq.push({dist[next],next});
                    paths[next]=paths[node];
                }
                else if(distance+dista==dist[next])
                {
                    paths[next]=(paths[next]+paths[node])%mod;
                }
            }
        }
        return paths[n-1]%mod;
    }
};



//TC:O(V+E)