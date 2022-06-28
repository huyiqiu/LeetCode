class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i ++) {
            while(nums[i] != i && nums[nums[i]] != nums[i]) swap(nums[i], nums[nums[i]]);
        }
        int res;
        for(int i = 0; i < nums.size(); i ++) {
            if(nums[i] != i && nums[nums[i]] == nums[i]) {
                res = nums[i];
                break;
            }
        }
        return res;
    }
};