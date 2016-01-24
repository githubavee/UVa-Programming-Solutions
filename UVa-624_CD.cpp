#include<bits/stdc++.h>
using namespace std;
vector<int>subset;
vector<int>solution;
int avi[25]={0};
int main(){
int n,sum=0;
while(scanf("%d %d",&sum,&n)==2)
{
  for(int i=0;i<n;i++)
 {
    cin>>avi[i];
  }
 // subset_sum(n);
 int max1=0,total=0;
 unsigned long int k=pow(2,n);
  for(int i=0;i < (1<<n);i++)
  {
      for(int j=0;j<n;j++)
      {
     // cout<<"hii\n";
        if(i&(1<<j))
        {
          total+=avi[j];
          subset.push_back(j);
        }
      }
      if(total <= sum && total >= max1)
      {
       max1=total;
       solution.clear();
       for(int p=0;p<subset.size();p++)
       {
           solution.push_back(subset[p]);
       }

       total=0;
      }
      total=0;
        subset.clear();
  }

  sort(solution.begin(),solution.end());
  for(int i=0;i<solution.size();i++)
  cout<<avi[solution[i]]<<" ";
  printf("sum:");
  printf("%d\n",max1);
}
}
