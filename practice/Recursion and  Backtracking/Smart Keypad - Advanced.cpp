#include<bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(false);cin.tie(0)
#define pb push_back
#define digit(x) floor(log10(x))+1
#define mod 1000000007
#define endl "\n"
#define int long long
typedef long double ld;
typedef vector<vector<int> > matrix;
typedef vector<int> arr;
typedef vector<string> vs;
typedef vector<pair<int,int> > pv;
#define test() int t;cin>>t;while(t--)
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define ROF(i,a,b) for(int i=a;i>=b;--i)
#define all(x) x.begin(),x.end()
#define debug(x) cerr << #x << " is " << x << endl;
int bx[]={0,0,1,-1,1,-1,-1,1};
int by[]={1,-1,0,0,1,-1,1,-1};

//=================================================================//
vector<string> v;
string searchIn [] = {
            "prateek", "sneha", "deepak", "arnav", "shikha", "palak",
            "utkarsh", "divyam", "vidhi", "sparsh", "akku"
    };

string s[] = {"","", "abc", "def","ghi","jkl","mno","pqrs","tuv","wxyz"};
void smart(string digit, string res, int idx) {
    if(idx==digit.length()) {
        v.push_back(res);
        return;
    }

    string curr = s[digit[idx]-'0'];
    for(int i=0;i<curr.length();i++) {
        smart(digit,res+curr[i],idx+1);
    }
}


#undef int
int main(){
#define int long long 
    fast;
    string s;
    cin>>s;
    smart(s,"",0);
    for(int i=0;i<11;i++) {
        for(string st : v) {
            if(st.length()<=searchIn[i].length()) {
                if(searchIn[i].find(st) != string::npos) {
                    cout<<searchIn[i]<<endl;
                }
            }
        }
    }
    return 0;
}