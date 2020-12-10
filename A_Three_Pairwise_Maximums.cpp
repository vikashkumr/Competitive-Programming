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


int32_t main(){
    fast;
    test() {
        int arr[3];
        for(int i=0;i<3;i++) {
            cin>>arr[i];       
        }
        int x = arr[0];
        int y = arr[1];
        int z = arr[2];
        sort(arr,arr+3);
        int a = arr[0];
        int b = arr[1];
        int c = arr[2];
        if(x==max(a,b) && y==max(a,c) && z==max(b,c)) {
            cout<<"YES"<<endl;
            cout<<a<<" "<<b<<" "<<c<<endl;
        } else {
            cout<<"NO"<<endl;
        }
    }
    
    return 0;
}