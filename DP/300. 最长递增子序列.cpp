class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(!n) return 0;
        vector<int> q;
        for(int i = 0; i < n; i ++){
            int temp = nums[i];
            if(q.empty() || temp > q.back()) q.push_back(temp);
            else{
                int l = 0, r = q.size() - 1;
                while(l < r){
                    int mid = l + r >> 1;
                    if(q[mid] >= temp) r = mid;
                    else l = mid + 1;
                }
                q[l] = min(q[l], temp);
            }
        }
        return q.size();
    }
};

