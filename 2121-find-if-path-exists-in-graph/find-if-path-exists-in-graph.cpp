class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        
       vector<vector<int>> adjLs(n); 

        for( auto it : edges) {
            adjLs[it[0]].push_back(it[1]);
            adjLs[it[1]].push_back(it[0]);
    }

    vector<int> vis( n ,0);

    queue<int> q; 

    q.push(source); 
    vis[source] = 1;

    while( !q.empty() ) { 
        int node = q.front(); 

        q.pop();

            if( node == destination) { 
                return true;
            }

        for( auto it : adjLs[node] ) { 
            if( !vis[it]){ 
                vis[it] = 1; 
                q.push(it);

            }
        }

    }

    
            return false;
    }
};