/*
Author:- Avinash Chandra
*/
#include<bits/stdc++.h>
using namespace std;
vector<string>vec(101);
string add_less_than_ten(string s,int i)
{
  if(i <=10)
    {
      if(i==1)
      s+='i';
      else if(i==2)
      {
       s+='i';
       s+='i';
      }
      else if(i==3)
      {
      s+='i';
       s+='i';
       s+='i';
      }
      else if(i==4)
      {
      s+='i';
       s+='v';
      }
      else if(i==5)
      s+='v';
      else if(i==6)
      {
       s+='v';
       s+='i';
      }
      else if(i==7)
      {
      s+='v';
      s+='i';
       s+='i';
      }
      else if(i==8)
      {
      s+='v';
      s+='i';
       s+='i';
       s+='i';
      }
      else if(i==9)
      {
      s+='i';
       s+='x';
      }
      else if(i==10)
      s+='x';
    }
    return s;
}
void Set()
{
int n=0;
  for(int i=1;i<=100;i++)
  { n=0;
    string s;
    if(i<=10)
    {
      s=add_less_than_ten(s,i);
      vec[i]=s;
    }
    else if(i>10 && i<40)
    {
     n=i;
    while(n>=10)
    {
    s+='x';
    n=n-10;
    }
      if(n>0 && n<10)
      s=add_less_than_ten(s,n);
      vec[i]=s;
    }
    else if(i>=40 && i<50)
    {
    n=i;
      s+='x';
      s+='l';
      n=n-40;
      if(n>0 && n<=10)
     s= add_less_than_ten(s,n);
      vec[i]=s;
    }
    else if(i==50)
    {
       s='l';
       vec[i]=s;
    }
    else if(i> 50 && i<90)
    {
    n=i;
      s+='l';
      n=n-50;
      while(n>=10)
      {
        s+='x';
        n=n-10;
      }
      if(n>0 && n<10)
     s= add_less_than_ten(s,n);
      vec[i]=s;
    }
    else if(i>=90 && i<100)
    {
     n=i;
     s+='x';
     s+='c';
     n=n-90;
     if(n> 0 && n<10)
   s=  add_less_than_ten(s,n);
     vec[i]=s;
    }
    else if(i==100)
    {
      s='c';
      vec[i]=s;
    }
  }
}
int main()
{
  Set();
  int n;
  while(scanf("%d",&n)==1,n)
  {
   int count_i=0,count_v=0,count_x=0,count_l=0,count_c=0;
     for(int i=1;i<=n;i++)
     {
       for(int j=0;j<vec[i].length();j++)
       {
        if(vec[i][j]=='i')
        count_i++;
        else  if(vec[i][j]=='v')
        count_v++;
        else  if(vec[i][j]=='x')
        count_x++;
        else  if(vec[i][j]=='l')
        count_l++;
        else  if(vec[i][j]=='c')
        count_c++;

       }
      // cout<<vec[i]<<" \n";
     }
     cout<<n<<": "<<count_i<<" i"<<", "<<count_v<<" v"<<", "<<count_x<<" x"<<", "<<count_l<<" l"<<", "<<count_c<<" c"<<endl;
  }
}
