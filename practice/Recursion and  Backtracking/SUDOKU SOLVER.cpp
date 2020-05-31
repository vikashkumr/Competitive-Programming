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
int n;

bool isSafeToPutNumber(int mat[][9],int i,int j,int n,int number){
	for(int k=0;k<n;k++){
		if(mat[i][k]==number || mat[k][j]==number){
			return false;
		}
	}

	// Check the smaller box
	n = sqrt(n);
	int starti = (i/n)*n;
	int startj = (j/n)*n;

	for(int k=starti;k<starti+n;k++){
		for(int l=startj;l<startj+n;l++){
			if(mat[k][l] == number) return false;
		}
	}
	return true;
}

bool SudokuSolver(int i,int j,int mat[][9]){
	// Base case
	if(i == n){
		//Print the sudoku
		return true;
	}

	if(j == n){
		return SudokuSolver(i+1,0,mat);
	}
	
	if(mat[i][j] != 0){
		return SudokuSolver(i,j+1,mat);
	}

	// Har cell ke liye kya kaam krna hai vo denote krte hai
	for(int number =1 ;number<=n;number++){
		if(isSafeToPutNumber(mat,i,j,n,number)){
			mat[i][j] = number;
			bool KyaBaakiSudokuSolveHua = SudokuSolver(i,j+1,mat);
			if(KyaBaakiSudokuSolveHua) return true;
			mat[i][j] = 0;
		}
	}
	return false;
}



#undef int
int main(){
#define int long long 
    fast;
    cin>>n;
    int sudoku[9][9];
    FOR(i,0,n-1)
        FOR(j,0,n-1)
            cin>>sudoku[i][j]; 
    bool ans = SudokuSolver(0,0,sudoku);
    FOR(i,0,n-1) {
        FOR(j,0,n-1)
            cout<<sudoku[i][j]<<" ";
        cout<<endl; 
    }
    return 0;
}