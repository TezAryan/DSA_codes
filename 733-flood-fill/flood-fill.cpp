class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {
        int n = image.size();
        int m = image[0].size();

        int initColor = image[sr][sc];
        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<int , int>> q;

        q.push({sr, sc});

        vis[sr][sc] = 1;

        image[sr][sc] = color;

        while (!q.empty()) {

            int r = q.front().first;
            int c = q.front().second;

            q.pop();

       

            int delrow[] = {-1, 0, 1, 0};
            int delcol[] = {0, 1, 0, -1};

            for (int i = 0; i < 4; i++) {
                int nrow = r + delrow[i];
                int ncol = c + delcol[i];

                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                        !vis[nrow][ncol] && image[nrow][ncol] == initColor){
                             image[nrow][ncol] = color;
                            vis[nrow][ncol] = 1;
                            q.push({nrow , ncol});
                        }
            }
        }


        return image;
    }
};