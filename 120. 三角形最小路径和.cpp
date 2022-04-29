class Solution {
public:
    int minimumTotal(vector<vector<int>>& nums) {
        int n = nums.size();
        vector<vector<int>> f(n, vector<int>(n)); 
        //f(i, j)状态表示：路径到达nums[i][j]时的最小路径和
        f[0][0] = nums[0][0];
        for(int i = 1; i < n; i ++){
            for(int j = 0; j < nums[i].size(); j ++){
                if(!j) f[i][j] = f[i - 1][j] + nums[i][j];
                else if(j == nums[i].size() - 1) f[i][j] = f[i - 1][j - 1] + nums[i][j];
                else f[i][j] = min(f[i - 1][j - 1], f[i - 1][j]) + nums[i][j];
            }
            // 状态转移：f(i, j)仅与它上一层的f(i - 1, _)有关
        }
        int res = INT_MAX;
        for(int i = 0; i < n; i ++){
            res = min(res, f[n - 1][i]);
        }
        return res;
    }
};
