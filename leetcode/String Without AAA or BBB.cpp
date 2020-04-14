//string that can be added "aab", "abb", "ab", "a", "b"

class Solution {
public:
    string strWithout3a3b(int A, int B) {
          string res = "";
          while(A!=0 and B!=0) {
              if(A>B) {
                  res+="aab";
                  A-=2;
                  B--;
              } else if(B>A) {
                  res+="bba";
                  A--;
                  B-=2;
              } else {
                  res+="ab";
                  A--;
                  B--;
              }
          }
          while(A) {
              res+="a";
              A--;
          }
          while(B) {
              res+="b";
              B--;
          }
    }
};