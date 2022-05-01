class Solution { //三重DP，类似于329.矩阵中的最长递增路径
public:
    vector<vector<vector<int>>> f;
    int dx[4] = {0, 1, 0, -1}, dy[4] = {-1, 0, 1, 0};
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        f = vector<vector<vector<int>>> (m, vector<vector<int>>(n, vector<int>(maxMove + 1, -1)));
        return dp(m, n, maxMove, startRow, startColumn);
    }

    int dp(int m, int n, int k, int x, int y){
        int &v = f[x][y][k];
        if(v != -1) return v;
        v = 0;
        if(!k) return v;
        for(int i = 0; i < 4; i ++){
            int a = x + dx[i], b = y + dy[i];
            if(a < 0 || a == m || b < 0 || b == n) v++;
            else v += dp(m, n, k - 1, a, b);
            v %= 1000000007;
        }
        return v;
    }
};
