//Extended Eucleadian algorithm ==> to solve for a and b in eq :: ax+by = gcd(a,b)

/* When is this algorithm used?
   This algorithm is used when A and B are co-prime. In such cases,
   x becomes the multiplicative modulo inverse of A under modulo B, and y becomes the multiplicative
   modulo inverse of B under modulo A. This has been explained in detail in the Modular multiplicative 
   inverse section.
*/

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