// time: O(N) + O(N log N)
// space: O(1)
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int j=0;
        for(int i=m; i< m+n; i++){
            nums1[i] = nums2[j];
            j++;
        }
        sort(nums1.begin(), nums1.end());
    }
};
// space: O(N)
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=0;
        int j=0;
        int k=0;
       
        vector<int> arr(m+n, 0);
        while(i < m && j < n) {
            if(nums1[i] <= nums2[j]) {
                arr[k++] = nums1[i++];
            }
            else {
                arr[k++] = nums2[j++];
            }
        }
        while(i < m)    arr[k++] = nums1[i++];
        while(j < n)    arr[k++] = nums2[j++];
       
        nums1 = arr;
    }
};


class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // Initialize i, j, k pointer to traverse from last
        int i = m-1, j = n-1, k = m+n-1;
       
        while(i >= 0 && j >= 0){
           
            if(nums1[i] > nums2[j]){
                nums1[k--] = nums1[i--];
            }
            else{
                nums1[k--] = nums2[j--];
            }
        }
        while(i >= 0){
            nums1[k--] = nums1[i--];
        }
        while(j >= 0){
            nums1[k--] = nums2[j--];
        }
    }
};
