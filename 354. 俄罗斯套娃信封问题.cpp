class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b){
        if(a[0] == b[0]) return a[1] > b[1];
        else return a[0] < b[0];
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), cmp);
        vector<int> nums, q;
        for(auto item : envelopes) nums.push_back(item[1]);
        int n = nums.size();
        for(int i = 0; i < n; i ++){
            int y = nums[i];
            if(q.empty() || y > q.back()) q.push_back(y);
            else{
                int l = 0, r = q.size() - 1;
                while(l < r){
                    int mid = l + r >> 1;
                    if(q[mid] >= y) r = mid;
                    else l = mid + 1;
                }
                q[l] = min(q[l], y);
            }
        }
        return q.size();
    }
};

class Solution { // 动态规划
public:
    static bool cmp(vector<int>& a, vector<int>& b){
        if(a[0] == b[0]) return a[1] > b[1];
        else return a[0] < b[0];
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), cmp);
        vector<int> nums;
        for(auto item : envelopes) nums.push_back(item[1]);
        int n = nums.size();
        vector<int> f(n);
        for(int i = 0; i < n; i ++){
            f[i] = 1;
            for(int j = 0; j < i; j ++){
                if(nums[j] < nums[i]) f[i] = max(f[i], f[j] + 1);
            }
        }
        int res = 0;
        for(auto x : f) res = max(x, res);
        return res;
    }
};
