//TC: O(nlogn) O(n^2) in worst case
// SC: O(logn) O(n) in worst case

// for smaller input quick sort is faster than merge sort as merge sort has more function call overhead
// divide and conquer

#include<bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(false);cin.tie(0)
#define pb push_back
#define digit(x) floor(log10(x))+1
#define mod 1000000007
#define endl "\n"
#define int long long
#define matrix vector<vector<int> >
#define vi vector<int>
#define pii pair<int,int>
#define vs vector<string>
#define vp vector<pii>
#define test() int t;cin>>t;while(t--)
#define all(x) x.begin(),x.end()
#define debug(x) cerr << #x << " is " << x << endl;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
const int sz = 100005;
void showArr(int *arr, int n){for(int i=0;i<n;i++) cout<<arr[i]<<" ";}
//=================================================================//

int partition (int *a, int p, int r) {
    int pivot = a[r];
    int i = p-1;
    for(int j=p;j<r;j++) {
        if(a[j] <= pivot) {
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i+1], a[r]);
    return i+1;
}

void quick_sort(int *a, int p, int r) {
    if(p < r) {
        int q = partition(a, p, r);
        quick_sort(a, p, q-1);
        quick_sort(a, q+1, r);
    }
}

int32_t main(){
    fast;
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++) {
        cin>>a[i];       
    }
    quick_sort(a, 0, n-1);
    for(int i=0;i<n;i++) {
        cout<<a[i]<<" ";       
    }
    return 0;
}
