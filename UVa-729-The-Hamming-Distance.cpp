#include<bits/stdc++.h>
using namespace std;
int main()
{
  int t;
  cin>>t;
  int k=0;
  while(t--)
  {
    int n,h;
    scanf("%d %d",&n,&h);
    string str;
    for(int i=0;i<n-h;i++)
    {
      str+='0';
    }
    for(int i=0;i<h;i++)
    str+='1';
    do{
      cout<<str<<endl;
    }while(next_permutation(str.begin(),str.end()));
    str.clear();
    if(t)
    cout<<endl;
  }
}
