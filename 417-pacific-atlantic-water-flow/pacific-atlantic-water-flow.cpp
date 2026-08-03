class Solution {
public:
    vector<int>dr = { 0 , 1, 0 , -1};
    vector<int>dc = { -1 , 0, 1 ,0};


 

    void dfs ( int row , int col ,vector<vector<int>>& heights , vector<vector<int>>& vis ) {

        if(vis[row][col]) { 
            return;
        }

        vis[row][col] = 1; 
            int m = heights.size(); 
        int n = heights[0].size();

        for(int i = 0 ; i < 4 ; i++) { 
            int  nr = row + dr[i]; 
            int nc = col + dc[i];



            if(nr >= 0 && nr < m && nc >= 0 && nc < n  && !vis[nr][nc] && heights[nr][nc] >= heights[row][col]) { 
                dfs(  nr , nc , heights , vis);
            }
        }
    }



    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

        int m = heights.size(); 
        int n = heights[0].size();

        vector<vector<int>> pacific ( m , vector<int>(n , 0));
        vector<vector<int>> atlantic ( m , vector<int>(n , 0));


        for( int j = 0 ; j < n ; j++) { 
            
            dfs ( 0 , j , heights , pacific);

        }

        for(int i = 0 ; i < m ; i++) { 
            dfs( i , 0 , heights , pacific);
        }


        for(int j = 0 ; j < n ; j++) { 
            dfs( m -1 , j , heights , atlantic);
        }

        for(int i = 0 ; i < m ; i++) { 
            dfs( i , n-1 , heights , atlantic ); 
        }


        vector<vector<int>> ans; 

        for(int i = 0 ; i < m ; i++) { 
            for(int j = 0 ; j < n ; j++) { 

                if(pacific[i][j] && atlantic[i][j]) { 
                    ans.push_back({i , j});
                }
            }
        }

        return ans;



    }
};