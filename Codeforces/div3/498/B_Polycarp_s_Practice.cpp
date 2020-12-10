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
        int n, k;
        cin>>n>>k;
        int tmp = k;
        int a[n];
        priority_queue<int> pq;
        for(int i=0;i<n;i++) {
            cin>>a[i];       
            pq.push(a[i]);
        }
        int sum = 0;
        while(k--) {
            int x = pq.top();pq.pop();
            sum+=x;
            for(int i=0;i<n;i++) {
                if(a[i]==x) {
                    a[i]=0;break;
                }
            }
        }
        int cnt = 0;
        cout<<sum<<endl;
        for(int i=0;i<n;i++) {
            cnt++;
            if(a[i]==0) {
                tmp--;
                if(tmp==0) cnt+=n-i-1;
                cout<<cnt<<" ";
                cnt = 0;
            }       
        }
    
        
        return 0;
    }