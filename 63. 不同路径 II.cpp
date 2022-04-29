class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& nums) {
        int m = nums.size();
        if(!m) return 0;
        int n = nums[0].size();
        vector<vector<int>> f(m, vector<int>(n)); 
        // f(i, j)的状态表示：到达nums[i][j]的路径数量总和
        f[0][0] = !nums[0][0];
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j ++){
                if(!nums[i][j]){
                    if(i > 0) f[i][j] += f[i - 1][j];
                    if(j > 0) f[i][j] += f[i][j - 1];
                    // 状态转移 ： f(i, j) 和它左面和上面的状态有关 
                }
            }
        }
        return f[m - 1][n - 1];
    }
};
