
//INTERVIEW BIT

#define ll long long
ll mod=1000000007;
    void merge(vector<int>&a,int s,int mid,int e,ll &count){
      
        int i=s;int j=mid+1;
        while(i<=mid && j<=e){
            if((ll)a[i]>(ll)a[j]){
                count=((mid-i+1)%mod+count%mod)%mod;
                j++;
            }
            else i++;
        }
        sort(a.begin()+s,a.begin()+e+1);
        return;
    }
    
    void mergesort(vector<int>&a,int s,int e,ll &count){
      
        if(s==e)return ;
            int mid=(s+e)/2;
            mergesort(a,s,mid,count);
            mergesort(a,mid+1,e,count);
            merge(a,s,mid,e,count);
            
        
        return;
    }

int Solution::solve(vector<int> &a) {
     int n=a.size();
       if(n==0)return 0;
      ll count=0;
        mergesort(a,0,n-1,count);
        return count%mod;
}