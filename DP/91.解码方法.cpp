/*
 f[i]的状态表示是前i个数的解码个数，它的转移仅和f[i - 1] f[i - 2] 有关
*/
class Solution { // 类似于爬台阶
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> f(n + 1); 
        
        f[0] = 1;
        for(int i = 1; i <= n; i ++){
            if(s[i - 1] - '0') f[i] += f[i - 1];
            if(i > 1){
                int num = (s[i - 2] - '0') * 10 + s[i - 1] - '0';
                if(num >= 10 && num <= 26) f[i] += f[i - 2];
            }
        }
        return f[n];
    }
};
