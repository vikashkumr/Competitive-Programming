#include<bits/stdc++.h>
using namespace std;

int main(){
    int C, S, curr_set;
    double AM, ans;
    curr_set = 0;
    int masses[11];
    while(cin>>C){
        cin>>S;
        for(int i = 0; i < S; i++)
           cin>>masses[i];
        AM = 0.0;
        for(int i=0;i<S;i++) {
            AM =(double) AM+ masses[i];
        }
        AM = (double) (AM/C);
        for(int i = S; i< 2*C; i++)
            masses[i] = 0;
        sort(masses, masses+2*C,[&](int a, int b) -> bool{
            return a>b;
        });

        ans = 0;

        cout<<"Set #"<<++curr_set<<endl;

        for(int i = 0; i< C; i++){
            cout<<" "<<i;

            if(masses[2*C-i-1]){
                cout<<" "<<masses[2*C-i-1];

            }
            if(masses[i])
                cout<<" "<<masses[i];

            ans += abs(masses[i] + masses[2*C-i-1] - AM);
            cout<<endl;
        }
        cout<<"IMBALANCE = "<<fixed<<setprecision(5)<<ans<<endl;
    }
    return 0;
}