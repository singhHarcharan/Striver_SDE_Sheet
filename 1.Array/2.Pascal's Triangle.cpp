// MINE APPROACH
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        // Base case
        if(numRows == 1)    return {{1}};
        if(numRows == 2)    return {{1}, {1,1}};
       
        vector<vector<int>> arr(numRows);
        for(int i=0; i < numRows; i++)  arr[i].resize(i+1, 1);
       
        for(int row = 0; row < numRows; row++) {
            for(int col = 0; col < arr[row].size(); col++) {
               
                // If its first or last index.
                if(col == 0 || col == arr[row].size()-1)
                    arr[row][col] = 1;
                // use copy-pen to make this relation.
                else {
                    arr[row][col] = arr[row-1][col-1] + arr[row-1][col];
                }
            }
        }
        return arr;
    }
};
