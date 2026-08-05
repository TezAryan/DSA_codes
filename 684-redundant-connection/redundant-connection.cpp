class Solution {
public:
    vector<int> parent; 

    int find(int node) { 
        if(parent[node] == node) { 
            return node; 
        }

        return parent[node] = find(parent[node]);
    }


    void Union( int u , int v) {

        int pu = find(u);
        int pv = find(v);




        if( pu != pv) 
        parent[pv] = pu; 
    }


     vector<int> findRedundantConnection(vector<vector<int>>& edges) {

        int n = edges.size();

        parent.resize(n+1);

        for( int i = 0 ; i<= n ; i++) { 
            parent[i] = i;
        }


        for(auto it : edges) { 
            int u = it[0];
            int v = it[1];


            if(find(u) == find(v))
            return it;

            Union( u , v);


        }

        return {};
        
    }
};