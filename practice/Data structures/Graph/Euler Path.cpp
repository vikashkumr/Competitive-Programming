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
const int N = 100005;
void showArr(int *arr, int n){for(int i=0;i<n;i++) cout<<arr[i]<<" ";}
//=================================================================//

vector<int> gr[N];
int tin[N], tout[N];
int timer;
void euler_tour_1(int curr, int par) {
    //after entering to the curr vertex
    cout<<curr<<" ";
    for(auto x : gr[curr]) {
        if( x!= par) {
            euler_tour_1(x, curr);
            //when coming back again curr vertex from other vertex
            cout<<curr<<" ";
        }
    }
    return;
}

void euler_tour_2(int curr, int par) {
    //after entering to the curr vertex
    cout<<curr<<" ";
    tin[curr] = timer++;
    for(auto x : gr[curr]) {
        if( x!= par) {
            euler_tour_2(x, curr);
        }
    }
    //after leaving curr vertex
    tin[curr] = timer++;
    cout<<curr<<" ";
    return;
}

void euler_tour_3(int curr, int par) {
    //after entering to the curr vertex
    cout<<curr<<" ";
    tin[curr] = ++timer;
    for(auto x : gr[curr]) {
        if( x!= par) {
            euler_tour_3(x, curr);
        }
    }
    tout[curr] = timer;
    return;
}

// whether x is ancestor of y or not
bool is_ancestor(int x, int y) {
    return tin[x]<=tin[y] && tout[x]>=tout[y];
}

void solve() {
    int n,m;
    cin>>n;
    for(int i=0;i<n-1;i++) {
        int x, y;
        cin>>x>>y;
        gr[x].push_back(y);
        gr[y].push_back(x);
    }
    timer = 0;
    // euler_tour_1(1,0);
    // euler_tour_2(1,0);
    euler_tour_3(1,0);
    for(int i=1;i<=n;i++) {
        cout<<i<<" "<<tin[i]<<" "<<tout[i]<<endl;
    }
}

int32_t main(){
    fast;
    
    
    return 0;
}