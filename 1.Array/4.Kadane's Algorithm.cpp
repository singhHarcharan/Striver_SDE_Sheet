/*
USING KADANE'S ALGORIHM


Loop from 0 to n        sum = 0, maxi = arr[0]
step 1: sum = sum + arr[i]
step 2: maxi = max(maxi, sum)
step 3: if(sum < 0)     sum = 0    (leave it)
*/


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
       
        int sum = 0;
        int maxi = nums[0];
       
        for(int i=0; i<nums.size(); i++){
            sum = sum + nums[i];
            maxi = max(maxi, sum);
            if(sum < 0)     sum = 0;
        }
        return maxi;
    }
};
