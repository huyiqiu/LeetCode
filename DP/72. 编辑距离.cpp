// 给你两个单词 word1 和 word2， 请返回将 word1 转换成 word2 所使用的最少操作数。

// 你可以对一个单词进行如下三种操作：

// 插入一个字符
// 删除一个字符
// 替换一个字符
//  

// 示例 1：

// 输入：word1 = "horse", word2 = "ros"
// 输出：3
// 解释：
// horse -> rorse (将 'h' 替换为 'r')
// rorse -> rose (删除 'r')
// rose -> ros (删除 'e')

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        vector<vector<int>> f(m + 1, vector<int> (n + 1));
        for(int i = 1; i <= m; i ++) f[i][0] = i;
        for(int i = 0; i <= n; i ++) f[0][i] = i;
        for(int i = 1; i <= m; i ++) {
            for(int j = 1; j <= n; j ++) {
                f[i][j] = min(f[i - 1][j], f[i][j - 1]) + 1;
                f[i][j] = min(f[i][j], f[i - 1][j - 1] + (word1[i - 1] != word2[j - 1]));
            }
        }
        return f[m][n];
    }
};