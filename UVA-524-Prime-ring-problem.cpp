#include<bits/stdc++.h>
using namespace std;
int circle[20];
bool used[20];
int value[21]={ 2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71};
vector<bool>prime(22);
void Set()
{
for(int i=0;i<20;i++)
{
  prime[value[i]]=true;
}
}

bool is_prime(int n)
{
if(prime[n])
return true;
else
return false;
}
void check(int m,int n)
{
  if(m==n-1 && is_prime(circle[n-1] + circle[n]))
  {
  for(int i=0;i<n;i++)
  {
    printf(i==n-1 ?"%d":"%d ",circle[i]);
  }
  printf("\n");
  }
  for(int i=2;i<=n;i++)
  {
     if(!used[i] && is_prime(circle[m]+i))
     {
       used[i]=true;
       circle[m+1]=i;
       check(m+1,n);
       used[i]=false;
     }
  }
}
int main()
{
 int n,t=0;
 Set();
 while(scanf("%d",&n)==1)
  {
  t++;
  if(t>1)
  printf("\n");
   circle[0]=circle[n]=1;
   printf("Case %d:\n",t);
   check(0,n);

  }
}
