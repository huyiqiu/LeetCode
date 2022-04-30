// 完全背包问题
// f[i] 表示： 凑成 i 使用的最少硬币数
// 状态表示：f[i] = min(f[i - c] + 1) 对于每个c∈coins
class Solution{
public:
    int coinChange(int amount, vector<int>& coins){
        vector<int> f(amount + 1, amount + 1);
        f[0] = 0;
        for(auto c : coins){
            for(int i = c; i <= amount; i ++){
                f[i] = min(f[i], f[i - c] + 1);
            }
        }
        return f[amount] == amount ? -1 : f[amount];
    }
}
