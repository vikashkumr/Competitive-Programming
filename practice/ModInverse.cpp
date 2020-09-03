//Modular Inverse using 
//Extended Eucleadian algorithm ==>
// to solve for a and b in eq :: ax+by = gcd(a,b)

//x = y'
//y = x-(a/b)*y'
//O(log(max(a,b)))
//Application
 //1.Modular Inverse
 //2. Diphentine Equation

 //ModularInverse
/*Theory:
What is modular multiplicative inverse? If you have two numbers A and M,
you are required to find B such  that it satisfies the following equation: (A*B)%M = 1 or (A*B) = 1(modM)

Here B is the modular multiplicative inverse of A under modulo M.





A and M are coprime i.e.Ax + My = 1 . In the extended Euclidean algorithm, x is the modular multiplicative inverse of A under modulo M. Therefore, the answer is x. You can use the extended Euclidean algorithm to find the multiplicative inverse.

For example, if A=5 and M=12, then gcd(A,M) = 1. Therefore, the inverse exists.

5*(5) + 12*(-2) = 1 (which comes from the extended Euclidean algorithm). Therefore, 5 is the inverse of A=5 under modulo 12.

*/
#include<bits/stdc++.h>
using namespace std;
#define Mod 1000000007
int x, y;

void ModInverseExEuclid(int a, int b) {
	if(b==0) {
		x = 1;
		y = 0;
		return;
	}
	else {
		ModInverseExEuclid(b,a%b);
		int temp = x;
		x = y;
		y = temp-(a/b)*y;
	}
}

int main () {
    int a;
    cin>>a;
	//find some b for which (a*b)%Mod=1 =>> b is modular multiplicative Inverse of a
	//a and Mod should be coprime precondition
	ModInverseExEuclid(a,Mod);
    cout<<(x+Mod)%Mod; //to handle negative x
	return 0;
}


/*
Another Approach: (used only when M is prime)

This approach uses Fermat's Little Theorem.

The theorem specifies the following: A^M-1 = 1(modM)
By multiplying with A^-1 both sides,the equation can be rewritten as follows: A^-1 = A^M-2 = 1(modM)

The formula for A^-1 is in the form of exponents. Therefore, modular exponentiation can be used to determine the result.

For example, if A=5 and M=11 then A^M-2(modM) = 5^9(mod11) is the inverse of 5 under modulo 11.

Time complexity O(log M)
When is modular inverse used?

Modular inverse is used to solve (A/B)%M as follows: (A/B)%M = (A*B^-1)%M After you find the inverse, you can solve this equation easily.
*/
int modInverse(int A,int M)
{
    return modularExponentiation(A,M-2,M);
}