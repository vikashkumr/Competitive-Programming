	#include<bits/stdc++.h>
	#include <ext/pb_ds/tree_policy.hpp>
	#include <ext/pb_ds/assoc_container.hpp>
	
	using namespace std;
	using namespace __gnu_pbds;
	
	/*-----------------------------*/
	
	#define  READ   freopen("input.txt","r",stdin)
	#define  WRITE  freopen("output.txt","w",stdout)
	#define  _IO    ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
	
	#define D       double
	#define ld      long double
	#define ll      long long int
	#define ul      unsigned int
	#define ull     unsigned long long int
	
	#define F       first
	#define S       second
	#define FF      first.first
	#define FS      first.second
	#define SF      second.first
	#define SS      second.second
	
	#define cl(v)         v.clear()
	#define SZ(s)         s.size()
	#define pb(a)         push_back(a)
	#define mk(a,b)       make_pair(a,b)
	#define all(v)        v.begin(),v.end()
	#define allcl(i,n,v)  for(int i=0;i<=n;i++)v[i].clear()
	
	#define cn1(a)        cin >> a
	#define cn2(a,b)      cin >> a >> b
	#define cn3(a,b,c)    cin >> a >> b >> c
	
	#define endl          "\n"
	#define nl            cout << endl
	#define co(s)         cout << s
	#define co1(a)        cout << a
	#define test()        int t;cin>>t;while(t--)
	#define TC            "Case " << t++ << ": "
	#define co2(a,b)      cout << a << " " << b
	#define co3(a,b,c)    cout << a << " " << b << " " << c
	
	#define mem0(a)     memset(a,0,sizeof(a))
	#define mem1(a)     memset(a,-1,sizeof(a))
	
	#define fr(i,l,r)   for(int i=l;i<=r;i++)
	#define frr(i,l,r)  for(i=r;i>=l;i--)
	#define fr0(i,n)    for(int i=0; i<n; i++)
	#define fr1(i,n)    for(int i=1; i<=n; i++)
	#define frr0(i,n)   for(int i=n-1;i>=0;i--)
	#define frr1(i,n)   for(int i=n;i>0;i--)
	
	/*-----------------------------*/
	
	///Move 4,8,bishop
	ll p4[]= {-1,1,0,0};
	ll q4[]= {0,0,1,-1};
	ll p8[]= {-1,1,0,0,-1,1,-1,1};
	ll q8[]= {0,0,1,-1,1,1,-1,-1};
	ll dr[]= {2, 2, -2, -2, 1, -1, 1, -1};
	ll dc[]= {1,-1,  1, -1, 2,  2,-2, -2};
	
	///Declaration
	#define mod     1000000007LL
	#define eps     0.000000001
	#define inf     9999999999999999LL
	#define pi      acos(-1.00)
	const ll INF = LONG_MAX;
	const D PI = 3.14159265358979323846;
	
	/////bit
	//ll bit[1000005],_n,_len;
	//void update(ll i, ll val)  {while(i<=_n){bit[i]+=val;i+=(i&(-i));}}
	//ll query(ll i)             {ll sum=0;while(i>0){sum+=bit[i];i-=(i&(-i));}return sum;}
	//ll select(ll k)            {ll i,p,h=0;for(i=_len;i>=0;i--){p=1<<i;if(p+h>_n) continue;if(bit[p+h]<k){h+=p;k-=bit[h];}}return h+1;}
	
	/////geometri_basic
	//struct Point{double x,y;};
	//struct StateLine{double x,y,c;};
	//StateLine line(Point A, Point B){StateLine L;L.x=B.y-A.y;L.y=A.x-B.x;L.c=L.x*A.x+L.y*A.y;return L;}
	//StateLine lombo_line(Point A, Point B){Point M;M.x=(A.x+B.x)/2.00;M.y=(A.y+B.y)/2.00;StateLine L;
	//    L.x=A.x-B.x;L.y=A.y-B.y;L.c=M.x*B.x-M.x*A.x+M.y*B.y-M.y*A.y;return L;}
	//Point line_intersect(StateLine A, StateLine B)
	//{Point P;double d=(A.x*B.y-B.x*A.y);if(d==0){/*parallel;*/}P.x=(B.y*A.c-A.y*B.c)/d;P.y=(A.x*B.c-B.x*A.c)/d;return P;}
	//double Distance(Point A, Point B){return sqrt((A.x-B.x)*(A.x-B.x)+(A.y-B.y)*(A.y-B.y));}
	
	/////Ordered Set
	//typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>order_set;
	//typedef tree<pair<ll,ll>,null_type,less<pair<ll,ll>>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;
	////*st.find_by_order(x) && st.order_of_key(x)
	//typedef trie<string,null_type,trie_string_access_traits<>,pat_trie_tag,trie_prefix_search_node_update>prefix_trie;
	////auto range = st.prefix_range(string) && (auto it=range.first;it!=range.second;it++)
	
	/////gcd/bigmod
	//ll gcd(ll a, ll b)              {if(b>a)gcd(b,a);return ((b==0)?a:gcd(b,a%b));}
	//ll lcm(ll a, ll b)              {ll p=(a*b)/(gcd(a,b));return p;}
	//ll BigMod(ll a,ll b,ll m)       {ll ans=1;a=a%m;while(b){if(b&1)ans=(ans*a)%m;a=(a*a)%m;b/=2;}return ans;}
	//ll Mod_inv(ll a, ll m)          {return BigMod(a,m-2,m);}
	//ll sum(ll a, ll b, ll m)        {return a>=m-b?a-(m-b):a+b;}
	//ll multiply(ll a, ll b, ll m)   {ll ans=0;if(b>a)swap(a,b);while(b){if(b&1)ans=sum(ans,a,m);b>>=1;a=sum(a,a,m);}return ans;}
	//ll fast_pow(ll a,ll b)            {ll res=1;while(b>0){if(b&1){res=res*a;b=b-1;}else{a=a*a;b=b>>1;}}return res;}
	
	/*-----------------------------*/
	
	//#define MX 1000005
	//ll a[MX],b[MX];
	//vector<ll>v,v1,v2;
	//map<ll,ll>mp;
	//priority_queue<ll>pq;
	//string s,s1,s2;

	/*---------------------------------- */

	int main() {
		
		return 0;
	}