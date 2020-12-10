// https://practice.geeksforgeeks.org/problems/merge-two-sorted-arrays5135/1

// Method 1
// TC : O(n*m) SC : O(1)

class Solution{
public:
	void merge(int arr1[], int arr2[], int n, int m) {
	    int i = 0;
	    int j = 0;
	    while(i<n) {
	        if(arr1[i] <= arr2[j]) i++;
	        else {
	            swap(arr1[i], arr2[j]);
	            for(int k=j;k<m-1;k++) {
	                if(arr2[k] > arr2[k+1]) swap(arr2[k], arr2[k+1]);
	                else break;
	            }
	            i++;
	        }
	    }
	}
};

// Method 2
//GAP method just know this algo exist no need to know intution
// TC : O(nlogn) SC : O(1)

// Algo: (ref: takeUforward)
// 1. find initial gap = ceil((n+m) / 2)
// 2. after complete operation of first gap new gap = gap/2 (reduced) 
// imagine two array has merged to single array

class Solution{
public:
    int nextGap(int gap) {
        if (gap <= 1)
            return 0;
        return (gap / 2) + (gap % 2);
    }
	void merge(int arr1[], int arr2[], int n, int m) {
	    int i, j, gap = n + m;
        for (gap = nextGap(gap); gap > 0; gap = nextGap(gap)) {
            // comparing elements in the first array.
            for (i = 0; i + gap < n; i++)
                if (arr1[i] > arr1[i + gap])
                    swap(arr1[i], arr1[i + gap]);
    
            // comparing elements in both arrays.
            for (j = gap > n ? gap - n : 0; i < n && j < m; i++, j++)
                if (arr1[i] > arr2[j])
                    swap(arr1[i], arr2[j]);
    
            if (j < m) {
                // comparing elements in the second array.
                for (j = 0; j + gap < m; j++)
                    if (arr2[j] > arr2[j + gap])
                        swap(arr2[j], arr2[j + gap]);
            }
        }
	}
};

// Method 3: check gfg
// TC: O(n+m)