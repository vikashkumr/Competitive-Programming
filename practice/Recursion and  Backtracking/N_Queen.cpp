//recursive backtracking
//N-queen problem => printing all posible queen
//©vikash

#include<iostream>
using namespace std;
//check for the position to place a queen is safe or not
bool isSafe(int board[][10],int x,int y,int n){
	//checking column
	for(int i=0;i<x;i++){
		if(board[i][y])
		return false;
	}
	//checking left upper diagonal
	int i=x-1,j=y-1;
	while(i>=0 && j>=0){
		if(board[i][j])
		return false;
		i--;j--;
	}
	//checking right upper diagonal
	i=x-1;j=y+1;
	while(i>=0 && j<n){
		if(board[i][j])
		return false;
		i--;j++;
	}
	return true;
}

bool solveQueen(int board[][10],int row,int size){
	//base case
	
	if(row==size){
		for(int i=0;i<size;i++){
			for(int j=0;j<size;j++)
			if(board[i][j])
			cout<<'Q'<<" ";
			else cout<<'_'<<" ";
			cout<<endl;
		}
		//return true;
		cout<<endl;
	}
	//recursive case;placing 
	for(int j=0;j<size;j++){
		if(isSafe(board,row,j,size)){
			board[row][j]=1;
			bool possible=solveQueen(board,row+1,size);
			if(possible){
				return true;
			}
			board[row][j]=0;//backtracking
		}
	}
	return false;
}
int main(){
	int board[10][10]={0};
	int n;
	cin>>n;
	solveQueen(board,0,n);
	return 0;
}
