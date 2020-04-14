#include<bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(false);cin.tie(0)
#define pb push_back
#define digit(x) floor(log10(x))+1
#define mod 1000000007
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

int table[1000] = {0};

//preprocessing Reset Table
void processTable(char *p) {
    int j = 0, i = 1;
    int lp = strlen(p);
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

void KMP(char *text, char *p) {
    processTable(p);
    int i = 0;
    int j = 0;
    int ltext = strlen(text);
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
        if(j == strlen(p)) {
            cout<<"pattern found at index: "<<i-j;
            j = table[j-1];
        }

    }
}


int main(){
    fast;
    char text[] = "ABCDYABCDABCDABCX";
    char p[] = "ABCDABCX";
    KMP(text,p);
    return 0;
}