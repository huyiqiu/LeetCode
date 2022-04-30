// 完全背包问题
// f[i] 表示： 凑成 i 的组合数
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> f(amount + 1);
        f[0] = 1;
        for(auto c : coins){
            for(int i = c; i <= amount; i ++){
                f[i] += f[i - c];
            }
        }
        return f[amount];
    }
};
