class Solution {
public:
    bool canFinish(int V, vector<vector<int>>& edges) {

        vector<int> indegree(V , 0); 
        vector<int> res;
        queue<int> q;
        vector<vector<int>> adjLs(V);

        for( auto it : edges ) { 
            adjLs[it[1]].push_back(it[0]);
            indegree[it[0]]++;
        }

        for( int i = 0 ; i < V ; i++) { 

            if( indegree[i] == 0) { 
                q.push(i);
            }

        }


        while ( !q.empty() ) { 
            int node = q.front(); 

            q.pop(); 
            res.push_back(node);

            for(auto it : adjLs[node] ) { 
                indegree[it]--;

                if(indegree[it] == 0) { 
                    q.push(it);
                }

            }

            
        }


        if( res.size() == V) { 
                return true;
            }

            return false;








        
    }
};