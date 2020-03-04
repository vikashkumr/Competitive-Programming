//Extended Eucleadian algorithm ==> to solve for a and b in eq :: ax+by = gcd(a,b)

//x = y'
//y = x-(a/b)*y'
//O(log(max(a,b)))
//Application
 //1.Modular Inverse
 //2. Diphentine Equation

#include<bits/stdc++.h>
using namespace std;
int x, y;
void ExEuclid(int a, int b) {
	if(b==0) {
		x = 1;
		y = 0;
		return;
	}
	else {
		ExEuclid(b,a%b);
		int temp = x;
		x = y;
		y = temp-(a/b)*y;
	}
}


int main () {
	ExEuclid(18,30);
	cout<<x<<" "<<y;
	return 0;
}