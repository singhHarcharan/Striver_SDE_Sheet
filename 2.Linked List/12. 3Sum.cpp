https://leetcode.com/problems/3sum/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
       
        // Base case
        // means we don't have any -ve number of zero. so overall sum=0 is not possible
        if(nums[0] > 0) return {};
       
        int n = nums.size();
        set<vector<int>> st;
        vector<vector<int>> ans;
       
        for(int i=0; i<n; i++) {
            if(nums[i] > 0)
                break;                   // when base number is non zero or non-negative.
           
            //If number is getting repeated, ignore the lower loop and continue.
            if(i > 0 && nums[i] == nums[i-1])  
                continue;
           
            int left = i+1;     // this not executed coz when we reach last num & it will be greater than zero.
            int right = nums.size()-1;
            int sum = 0;
            while(left < right)
            {
                sum = nums[i] + nums[left] + nums[right];
                if(sum < 0)         left++;
                else if(sum > 0)    right--;
                else {
                    st.insert({nums[i], nums[left], nums[right]});
                   
                    int val = nums[left];
                    while(left < n && nums[left] == val)    left++;     // skip duplicates
                   
                    val = nums[right];
                    while(right >= 0 && nums[right] == val) right--;
                }
            }
        }
        for(auto it:st) ans.push_back(it);
        return ans;
    }
};

