/*
Author:- Avinash Chandra
tags:- Binary search, greedy

here we find answer using the binary search , form 0 to sum of all books pages, and we will choose the maximum value, satisfying all the costraint.
*/
#include<bits/stdc++.h>
using namespace std;
bool check(int avi[],int n,int m,int x)
{
   int currsum=0,count=0;
   for(int i=0;i<n;i++)
   {
      currsum+=avi[i];
      if(avi[i] > x)
      return false;
      if(currsum > x)
      {
        currsum=avi[i];
        count++;
        if(count > m-1)
        return false;
      }
   }
   return true;
}
void print(int avi[],int n,int m,int x)
{
set<int>mset;
int currsum=0;
  for(int i=n-1;i>=0;i--)
  {
     currsum+=avi[i];
     if(currsum > x)
     {
       currsum=avi[i];
       mset.insert(i);
       m--;
     }
     if(i<m)
     {
        while(m--)
        {
          mset.insert(i-m-1);
        }
        break;
     }
  }
  for(int i=0;i<n-1;i++)
  {
    if(mset.find(i)!=mset.end())
    {
     cout<<avi[i]<<" / ";
    }
    else
    cout<<avi[i]<<" ";
  }
  cout<<avi[n-1]<<endl;
}
int main()
{
 int t;
 cin>>t;
 while(t--)
   {
      int n,m;
      cin>>n>>m;
      int avi[n+1];
      long int sum=0;
      for(int i=0;i<n;i++)
      {
      cin>>avi[i];
      sum+=avi[i];
      }

      // binary search..to get the desired value.
      long int l=0,r=sum,mid=0;
      while(l<r)
      {
        mid=(l+r)/2;
        if(check(avi,n,m,mid))
        r=mid;
        else
        l=mid+1;
      }
      print(avi,n,m,r);
   }
}
