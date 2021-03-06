class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0;
        int r = n-1;
        
        while(l<=r)
        {
            int mid = l + (r-l)/2;
            if(nums[mid] == target) return true;
            if(nums[l] == nums[mid] and nums[mid] == nums[r])
            {
                l++;
                r--;
                
            }
            else if(nums[mid] <= nums[r])
            {
                if(target <= nums[r] and target >= nums[mid])
                {
                    l = mid+1;
                }
                else
                {
                    r = mid-1;
                }
            }
            else
            {
                if(target<=nums[mid] and target >= nums[l])
                {
                    r = mid-1;
                }
                else
                {
                    l = mid+1;
                }
            }
        }
        return false;
    }
};