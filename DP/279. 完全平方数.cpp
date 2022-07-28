```c++
class Solution {
public:
    int numSquares(int n) {
        vector<int> f(n + 1, n + 1);
        f[0] = 0;
        for(int i = 1; i <= 100; i ++){
            if(i * i > n) break;
            for(int j = i * i; j <= n; j ++){
                f[j] = min(f[j], f[j - i * i] + 1);
            }
        }
        return f[n];
    }
};