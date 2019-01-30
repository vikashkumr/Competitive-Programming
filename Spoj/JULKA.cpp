#include<bits/stdc++.h>
using namespace std;
string add(string s1,string s2)
{
 string ans;
 if(s1.length()<s2.length())
 {
   swap(s1,s2);
 }
 int l1=s1.length();
 int l2=s2.length();
 int diff=l1-l2;
 int carry=0,sum;
  for(int i=l1-1;i>=diff;--i)
  {
     sum=(s1[i]-'0')+(s2[i-diff]-'0')+carry;
     ans.push_back(sum%10+'0');
     carry=sum/10;
}

  for(int j=diff-1;j>=0;--j)
  {
    sum=(s1[j]-'0')+carry;
     ans.push_back(sum%10+'0');
     carry=sum/10;
  }
  if(carry)
  ans.push_back(carry+'0');
  reverse(ans.begin(),ans.end());
  return ans;
}

string subtract(string s1,string s2)
{
 string ans;
 if(s1.length()<s2.length())
 {
   swap(s1,s2);
 }
 int l1=s1.length();
 int l2=s2.length();
 int diff=l1-l2;
 int dif,carry=0;
  for(int i=l1-1;i>=diff;--i)
  {
     dif=(s1[i]-'0')-(s2[i-diff]-'0')-carry;
     if(dif<0)
     {
       dif=dif+10;
       carry=1;
     }
     else
     carry=0;
     ans.push_back(dif+'0');
  }
  for(int j=diff-1;j>=0;--j)
  {
    if(s1[j]=='0' && carry)
     {ans.push_back('9');
     continue;}
     dif=(s1[j]-'0')-carry;
     if(j>0 || dif>0)
     ans.push_back(dif+'0');
     carry=0;
  }
  reverse(ans.begin(),ans.end());
  return ans;
}

string isHalf(string s)
{
  string ans;
  //int divisor=2;
  int index=0;
  int temp=s[index]-'0';
  while(temp<2)
  temp=temp*10+(s[++index]-'0');
  while(s.length()>index)
  {
    ans+=(temp/2+48);
    temp=(temp%2)*10+(s[++index]-'0');
  }

    if(ans=="0")
    return "0";
    else
    return ans;
}

int main()
{
    int t=10;
    while(t--)
    {
    string s1,s2;
     string h1,h2,h3,h4;
     cin>>s1>>s2;
     h1=isHalf(add(s1,s2));
     h2=isHalf(subtract(s1,s2));
     cout<<h1<<"\n"<<h2<<"\n";
    }
    return 0;
}

