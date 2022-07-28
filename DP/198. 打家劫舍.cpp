class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> f(n), g(n);
        // f[i] : rob i, g[i] : not rob i
        f[0] = nums[0];
        g[0] = 0;
        for (int i = 1; i < n; i ++){
            f[i] = g[i - 1] + nums[i];
            g[i] = max(f[i - 1], g[i - 1]);
        }
        return max(f[n - 1], g[n - 1]);
    }
};