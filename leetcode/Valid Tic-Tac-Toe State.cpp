class Solution {
public:
    bool validTicTacToe(vector<string>& board) {
        int x = 0, o = 0;
        bool xjitrhahai = 0;
        bool ojitrhahai = 0;
        for(int i=0;i<3;i++) {
            for(int j=0;j<3;j++) {
                if(board[i][j]=='X') x++;
                else if(board[i][j]=='O') o++;
            }
        }
        if(o<x-1 || o>x) return 0;
        if(abs(x-o)>1) return 0;
        
        //dono to nhi jit rhe
        
        //row
        for(int i=0;i<3;i++) {
            int cntx = 0;
            int cnto = 0;
            for(int j=0;j<3;j++) {
                if(board[i][j]=='X') cntx++;
                if(board[i][j]=='O') cnto++;
            }
            if(cntx==3) xjitrhahai=1;
            if(cnto==3) ojitrhahai=1;
        }
        
        //column
        
        for(int i=0;i<3;i++) {
            int cntx = 0;
            int cnto = 0;
            for(int j=0;j<3;j++) {
                if(board[j][i]=='X') cntx++;
                if(board[j][i]=='O') cnto++;
            }
            if(cntx==3) xjitrhahai=1;
            if(cnto==3) ojitrhahai=1;
        }
        
        
        //diagonal
        if((board[0][0]==board[1][1]) && (board[2][2]==board[1][1])) {
            if(board[0][0]=='X') xjitrhahai=1;
            else  if(board[0][0]=='O') ojitrhahai=1;
        }
        
        if((board[2][0]==board[1][1]) && (board[0][2]==board[1][1])) {
            if(board[2][0]=='X') xjitrhahai=1;
            else if(board[2][0]=='O') ojitrhahai=1;
        }
        
        if(ojitrhahai==1 and xjitrhahai==1) return false;
        else if(xjitrhahai==1) {
            return x-1==o;
        } else if(ojitrhahai==1) return x==o;
        else return true;
        
    }
};