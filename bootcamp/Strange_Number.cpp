#include<bits/stdc++.h>
using namespace std;
vector<int>v;
const int MAX = 316224;
bool prime[MAX];

void seiveprime() {
    memset(prime,true,sizeof prime);
    prime[1] = 0;
    for(int i=2;i*i<=MAX;i++) {
        if(prime[i]) {
            v.push_back(i);
            for(int p=2*i;p<=MAX;p+=i) {
                prime[p] = false;
            }
        }
    }
}

class Kdiv {
    public:
    int val;
    int div;
    int n;
};
Kdiv *t = new Kdiv[MAX];
void init() {
    for(int i=2;i<=MAX;i++) {
        t[i].val = i;
        t[i].div = 0;
        t[i].n = 1;
    }

    for(int i=0;i<v.size();i++) {
        for(int j = v[i];j<=MAX;j++) {
            if(t[j].val%v[i]==0) {
                t[j].div++;
                int cnt = 0;
                while(t[j].val%v[i]==0) {
                    t[j].val/=v[i];
                    cnt++;
                }
                t[j].n *=(1+cnt);
            }
        }
    }
}

int main()  {
    seiveprime();
    init();
    int test;
    cin>>test;
    while(test--) {
        int x,k;
        cin>>x>>k;
        bool flag = 0;
        for(int i=2;i<=MAX;i++) {
            if(t[i].n==x and t[i].div==k) {
                flag = 1;
                break;
            }
        }
        cout<<flag;
    }
    
    return 0;
}