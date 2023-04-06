class Solution {
public:
    /*
    Dry Run on this test case to understand algo.
   
    e.g. arr = [4,1,5,3,2]
    Output: arr = [4,2,1,3,5]
    */
    void nextPermutation(vector<int>& arr) {
        // Optimal Solution.
        // Step 1: Traversing From right to left while checking if(arr[i] < arr[i+1])
        // To Avoid wrong answer, don't initialise these indexes
        int idx1, idx2;
       
        for(int i = arr.size()-2; i>=0; i--)
        {
            if(arr[i] < arr[i+1]){
                idx1 = i;
                break;
            }
        }
       
        // If we reached first index,means given array is in decreasing order and we reached last
        // permutaion, so return sorted array in ascending order or reverse order.
        if(idx1 < 0){
            reverse(arr.begin(), arr.end());
            return ;
        }
        else
        {
            // Step 2: Again Iterate from right to left while traversing if (arr[i])
            for(int i = arr.size()-1; i>=0; i--)
            {
                if(arr[i] > arr[idx1]){
                    idx2 = i;
                    break;
                }
            }


            // Step 3: swap both arr[idx1] & arr[idx2]
            swap(arr[idx1], arr[idx2]);


            // Step 4: Reverse the array from (idx1 + 1 to end)
            reverse(arr.begin() + idx1 + 1,  arr.end());
        }
    }
};
