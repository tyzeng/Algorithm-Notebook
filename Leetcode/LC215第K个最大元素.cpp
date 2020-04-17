class Solution {
public:
    int partition(vector<int>& nums,int lo,int hi)
    {
        int mid = (lo + hi) >> 1; //不要选最低位和最高位
        int base = nums[mid];
        nums[mid] = nums[lo];
        nums[lo] = base;
        int l = lo, r = hi - 1;
        while(l < r)
        {
            while(nums[l] >= base) l++;
            while(nums[r] <= base) r--;           
            if(l < r)
            {
                int tmp = nums[l];
                nums[l] = nums[r];
                nums[r] = tmp;
            }
        }
        nums[lo] = nums[r];
        nums[r] = base;
        return r;
    }
    int findKthLargest(vector<int>& nums, int k) {
        int lo = 0,hi = nums.size();
        int p = partition(nums,lo, hi);
        while(p != k - 1)
        {
            if(p < k - 1) lo = p + 1; 
            else hi = p;
            p = partition(nums, lo, hi);
        }
        return nums[p];
    }
};
