/*
 * @lc app=leetcode id=1074 lang=cpp
 *
 * [1074] Number of Submatrices That Sum to Target
 */

// @lc code=start
// In a nutshell the approach is to choose all pairs of rows and shrink the bundle (chosen rows alongwith rows in between them) into an array (summing up entries in each column together) and now finding the number of subarrays in this array whose sum is equal to the target in O(M).

// The overall complexity becomes O(N * N * M).


class Solution {
public:
    
    //Another classical problem of finding number of subarrays having sum equal to target in the array O(n)
    int numSubarraySumTarget(vector<int> &arr,int target){
        int num_of_subarray=0;
        unordered_map<int,int> mp;
        mp.insert({0,1});
        int curr_sum=0;
        for(int i=0;i<arr.size();i++){
            curr_sum+=arr[i];
            if(mp.find(curr_sum-target)!=mp.end()) num_of_subarray+=mp[curr_sum-target];
            mp[curr_sum]++;
        }
        return num_of_subarray;
    }
    
    
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        
        int n=matrix.size();        //number of rows in the matrix
        if(n==0) return 0;          //If there are no rows in a matrix then there is no submatrix for any target 
        int m=matrix[0].size();     //number of columns in the matrix
        
        int number_of_submatrices=0;
        
        
        //choosing two rows adding there elements of same columns and creating the array out of it / Simply shrinking the bundle of rows to a 1-D array
        for(int row_x1=0;row_x1<n;row_x1++){
            vector<int> sum_array(m,0);
            for(int row_x2=row_x1;row_x2<n;row_x2++){
                
                for(int i=0;i<m;i++) sum_array[i]+=matrix[row_x2][i];
                
                //Find the number of subarrays that equal to the target in this shrinked array. 
                number_of_submatrices+=numSubarraySumTarget(sum_array,target);
                
            }
            
        }
        
        return number_of_submatrices;
    }
};
// @lc code=end

