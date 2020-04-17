class Solution {
public:
    int findRightBound(vector<int>& nums, int target, int n)
    {
        if(nums.size() == 0) return -1;
        int lo = 0, hi = n;
        while(lo < hi) //找到的是第一个大于target的数
        {
            int mid = (lo + hi) >> 1;
            if(nums[mid] <= target) lo = mid + 1;
            else hi = mid;
        }
        if(lo == 0) return -1;
        return nums[lo - 1] == target? lo - 1: -1;
    }
    int findLeftBound(vector<int>& nums, int target, int n)
    {
        if(nums.size() == 0) return -1;
        int lo = 0, hi = n;
        while(lo < hi) //左侧边界
        {
            int mid = (lo + hi) >> 1;
            if(nums[mid] >= target) hi = mid;
            else lo = mid + 1;
        }
        if(hi == n) return -1;        
        return nums[hi] == target? hi : -1;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res;
        res.push_back(findLeftBound(nums, target, nums.size()));
        res.push_back(findRightBound(nums, target, nums.size()));
        return res;    
    }
};
