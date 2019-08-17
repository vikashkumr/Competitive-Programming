#include <bits/stdc++.h>
    using namespace std;
    #define ll long long
    ll max(ll x,ll y){
        return (x>y)?x:y;
    }
    ll min(ll x,ll y){
        return (x>y)?y:x;
    }
    vector<ll> initializeDiffArray(vector<ll>& A) 
    { 
        ll n = A.size();
        vector<ll>D(n+1); 

        D[0]=A[0],D[n]=0; 
        for(ll i=1;i<n;i++) 
            D[i] = A[i]-A[i-1]; 
        return D; 
    } 

    void update(vector<ll>& D, ll l, ll r, ll x) 
    { 
        D[l] += x; 
        D[r + 1] -= x; 
    }

    void printArray(vector<ll>& A, vector<ll>& D) 
    { 
        for(ll i=0;i<A.size();i++) { 
            if(i==0) 
                A[i]=D[i]; 
            else
                A[i]=D[i]+A[i-1]; 
        } 
    }


    int main() {
        ll t;
        cin>>t;
        while(t--){
            ll n;
            cin>>n;
            ll arrC[n];
            ll arrH[n];
            for(ll i=0;i<n;i++)
            cin>>arrC[i];
            for(ll i=0;i<n;i++)
            cin>>arrH[i];
            sort(arrH,arrH+n);
            
            vector<ll>A(n,0);
            vector<ll> D = initializeDiffArray(A);
            
            for(ll i=0;i<n;i++){
                update(D,max(i-arrC[i],0),min(i+arrC[i],n-1),1);
            }
            printArray(A,D);
            sort(A.begin(),A.end());
            ll flag=0;
            for(ll i=0;i<n;i++){
                if(A[i]==arrH[i])
                continue;
                else {
                    flag=1;
                    break;
                }
            }
            if(flag)
            cout<<"NO\n";
            else
            cout<<"YES\n";
        }
        return 0;
    }

