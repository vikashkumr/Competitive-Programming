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
/*
 TC: O(n^2)
 SC: O(1)
Algo: 
choose element at 1st index swap with mn in index 2 to n
choose element at 2nd index swap with mn in index 3 to n
and so on .............
*/
void selection_sort(int *a, int n){
    for (int i = 0; i < n; i++) {
        int mn = a[i];
        int idx = i;
        for (int j = i+1; j < n; j++) {
            if(a[j] < mn) {
                mn = a[j];
                idx = j;
            }
        }
        swap(a[i], a[idx]);
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
    selection_sort(a, n);
    for(int i=0;i<n;i++) {
        cout<<a[i]<<" ";       
    }
    return 0;
}