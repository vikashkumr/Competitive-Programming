/*
* @type of arr: integer array
* @return type: integer
*/
class Solution {
public:
    int cnt = 0;
    void merge(int p, int mid, int r, vector<int>&arr) {
        vector<int> a,b;
        for(int i=p;i<=mid;i++) a.push_back(arr[i]);
        for(int i=mid+1;i<=r;i++) b.push_back(arr[i]);

        int i=0, j=0;
        int idx = p;
        while(i<a.size() and j<b.size()) {
            if(a[i] <= b[j]) {
                arr[idx++] = a[i];
                i++;
            } else {
                cnt+=a.size()-i;
                arr[idx++] = b[j];
                j++;
            }
        }
        while(i<a.size()) arr[idx++] = a[i], i++;
        while(j<b.size()) arr[idx++] = b[j], j++;   
    }

    void mergeSort(int l, int r, vector<int> &arr) {
        if(l>=r) return;
        int mid = (l+r)/2;
        mergeSort(l,mid,arr);
        mergeSort(mid+1,r,arr);
        merge(l,mid,r, arr);
    }
    int inversionCount(vector<int>& arr) {
    	mergeSort(0,arr.size()-1, arr);
        return cnt;
    }
};