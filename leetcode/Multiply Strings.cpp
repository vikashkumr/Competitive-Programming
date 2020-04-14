class Solution {
public:
    string multiply(string num1, string num2) {
        string ss = num2;
        if(num2.length()>num1.length()){
            num2 = num1;
            num1 = ss;
        }
        int len1 = num1.length();
        int len2 = num2.length();
        if(len1==0 or len2==0) return "0";
        
        int i_n1 = 0;
        int i_n2 = 0;
        
        int carry = 0;
        vector<int>res(len1+len2,0);
        
        for(int j=len2-1;j>=0;j--){
            int n2 = num2[j]-'0';
            i_n1=0;
            for(int i=len1-1;i>=0;i--){
                int n1 = num1[i]-'0';
                int sum = n1*n2+carry+res[i_n1+i_n2]; 
                if(sum<10){
                    res[i_n1+i_n2] = sum;
                    carry = 0;
                }
                else {
                    res[i_n1+i_n2] = sum%10;
                    carry = sum/10;
                }
                i_n1++;   
            }
            if(carry>0){
                res[i_n1+i_n2] += carry;
                carry=0;
            }
            i_n2++;
        }
        
        int i=res.size()-1;
        while(i>=0 and res[i]==0){
            i--;
        }
        if(i==-1) return "0";
        string s="";
        while(i>=0){
            s+=to_string(res[i--]);
        }
        return s;
    }
};