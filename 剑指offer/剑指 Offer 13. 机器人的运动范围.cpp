class Solution {
public:
    int movingCount(int m, int n, int k) {
        int dx[4] = {0, 1, 0, -1}, dy[4] = {-1, 0, 1, 0};
        queue<pair<int, int>> q;
        auto visit = vector<vector<bool>>(m, vector<bool>(n));
        q.push({0, 0});
        int res = 0;
        while(q.size()){
            int level = q.size();
            for(int i = 0; i < level; i ++){
                auto now = q.front();
                q.pop();
                int temp = count(now);
                if(temp > k || visit[now.first][now.second]) continue;
                visit[now.first][now.second] = 1;
                res ++;
                for(int j = 0; j < 4; j ++){
                    int x = now.first, y = now.second;
                    int a = x + dx[j], b = y + dy[j];
                    if(a >= 0 && a < m && b >= 0 && b < n) {
                        q.push({a, b});
                    }
                }
            }
        }
        return res;
    }

    int count(pair<int, int> pos) {
        int a = pos.first, b = pos.second;
        int res = 0;
        while(a) {
            res += (a % 10);
            a /= 10;
        }
        while(b) {
            res += (b % 10);
            b /= 10;
        }
        return res;
    }
};