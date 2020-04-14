#include<bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(false);cin.tie(0)
#define pb push_back
#define digit(x) floor(log10(x))+1
#define mod 1000000007
#define endl "\n"
typedef long long ll;
typedef long double ld;
typedef vector<vector<ll> > matrix;
typedef vector<ll> arr;
typedef vector<string> vs;
typedef vector<pair<ll,ll> > pv;
#define in1(x) scanf("%lld",&x)
#define in2(x,y) scanf("%lld %lld",&x,&y)
#define in3(x,y,z) scanf("%lld %lld %lld",&x,&y,&z)
#define all(x) x.begin(),x.end()
#define debug(x) cerr << #x << " is " << x << endl;
int bx[]={0,0,1,-1,1,-1,-1,1};
int by[]={1,-1,0,0,1,-1,1,-1};

int table[1000000] = {0};

//preprocessing Reset Table
void processTable(string p) {
    int j = 0, i = 1;
    int lp = p.length();
    while(i<lp) {
        while(j>0 and p[i]!=p[j]) {
            j = table[j-1];
        }
        if(p[i]==p[j]) {
            table[i] = j+1;
            i++;
            j++;
        } else {
            i++;
        }
    }
}

void KMP(string text, string p) {
    processTable(p);
    int i = 0;
    int j = 0;
    int ltext = text.length();
    while(i<ltext) {
        
        while(j>0 and text[i] != p[j]) {
            j = table[j-1];
        }

        if(text[i] == p[j]) {
            i++,
            j++;
        } else {
            i++;
        }

        //pattern found
        if(j == p.length()) {
            cout<<i-j<<endl;
            j = table[j-1];
        }

    }
}


int main(){
    fast;
    int n;
    while(cin>>n) {
        string text;
        string p;
        cin>>p>>text;
        KMP(text,p);
        cout<<endl;
    }
    return 0;
}