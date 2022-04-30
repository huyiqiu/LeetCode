/*
记忆化搜索 + dp
*/
class Solution {
public:
    vector<vector<int>> f;
    int m, n;
    int dx[4] = {0, -1, 0, 1}, dy[4] = {1, 0, -1, 0};
    int dp(int x, int y, vector<vector<int>>& nums){
        if(f[x][y] != -1) return f[x][y];
        f[x][y] = 1;
        for(int i = 0; i < 4; i ++){
            int a = x + dx[i], b = y + dy[i];
            if(a >= 0 && a < m && b >= 0 && b < n && nums[a][b] > nums[x][y]){
                f[x][y] = max(f[x][y], dp(a, b, nums) + 1);
            }
        }
        return f[x][y];
    }

    int longestIncreasingPath(vector<vector<int>>& nums) {
        m = nums.size();
        n = nums[0].size();
        f = vector<vector<int>> (m, vector<int>(n, -1));
        int res = 0;
        for(int i = 0; i < m; i ++){
            for(int j = 0; j < n; j ++){
                res = max(res, dp(i, j, nums));
            }
        }
        return res;
    }
};
