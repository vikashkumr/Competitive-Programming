#include<bits/stdc++.h>
using namespace std;
#define D double
#define PI 3.1415926535

D derivative(D x,D b, D c) {
    return ((2*x+b)*sin(x) - (x*x+b*x+c)*cos(x));
}

D f(D b, D c) {
    D s = 0;
    D e = PI/2;
    D ans;
    int cnt = 0;
    while(s<=e) {
        D mid = (s+e)/2;
        if(derivative(mid,b,c)<0) {
            s = mid;
            ans = mid;
        } else {
            ans = mid;
            e = mid;
        }
        cnt++;
        if(cnt==100) break;
    }
    return (ans*ans+b*ans+c)/sin(ans);
}

int main()  {
    int t;
    cin >> t;
    while (t--) {
        D b, c;
        cin >> b >> c;
        D val = f(b,c);
        cout<<setprecision(11)<<f(b,c)<<endl;
    }
    return 0;
}