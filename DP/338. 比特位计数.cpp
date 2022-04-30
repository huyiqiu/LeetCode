class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> f(n + 1);
        f[0] = 0;
        for(int i = 1; i <= n; i ++){
            f[i] = f[i >> 1] + (i & 1); 
        }
        return f;
    }
};
