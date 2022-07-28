// 给定一个字符串 s 和一个字符串 t ，计算在 s 的子序列中 t 出现的个数。

// 字符串的一个 子序列 是指，通过删除一些（也可以不删除）字符且不干扰剩余字符相对位置所组成的新字符串。（例如，"ACE" 是 "ABCDE" 的一个子序列，而 "AEC" 不是）

// 题目数据保证答案符合 32 位带符号整数范围。


// 示例 1：

// 输入：s = "rabbbit", t = "rabbit"
// 输出：3
// 解释：
// 如下图所示, 有 3 种可以从 s 中得到 "rabbit" 的方案。
// rabbbit
// ---- --
// rabbbit
// --- ---
// rabbbit
// -- ----


class Solution {
public:
    int numDistinct(string s, string t) {
        // f[i][j] : s中前i个字符 包含 t中前j个字符的个数
        // s[i] == s[j]时，能够匹配，f[i][j] = f[i - 1][j - 1] + f[i - 1][j];
        // 否则，无法匹配，f[i][j] = f[i - 1][j];
        int m = s.size(), n = t.size();
        vector<vector<double>> f(m + 1, vector<double> (n + 1));
        for(int i = 0; i <= m; i ++) f[i][0] = 1; //边界情况
        for(int i = 1; i <= m; i ++) {
            for(int j = 1; j <= n; j ++) {
                if(s[i - 1] == t[j - 1]) f[i][j] = f[i - 1][j - 1] + f[i - 1][j];
                else f[i][j] = f[i - 1][j];
            }
        }
        return f[m][n];
    }
};