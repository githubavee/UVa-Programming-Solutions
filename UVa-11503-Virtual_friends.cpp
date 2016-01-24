/* Author:- Avinash Chandra 
keywords:-Union Find Data structure.
*/
#include<bits/stdc++.h>
using namespace std;
int parent[200001];
int Rank[200001];
int Find(int i)
{
 if(parent[i]!=parent[parent[i]])
 parent[i]=Find(parent[i]);
 return parent[i];
}
void Union(int i,int j)
{
  int xx=Find(i);
  int yy=Find(j);
  if(xx==yy)
  {
   return;
  }
  if(Rank[xx]>Rank[yy])
  swap(xx,yy);
  if(Rank[xx]==Rank[yy])
  Rank[yy]++;
  parent[xx]=yy;
  return;
}
int Sizeof(int j,int k)
{
  int count=0;
  for(int i=1;i<k;i++)
  {
    if(Find(i)==j)
    count++;
  }
  return count;
}
int main()
{
  int t;
  scanf("%d",&t);
  while(t--)
      {
      map<string , int> mp;
        int n,k=1;
        scanf("%d",&n);
        vector<vector<int> >vec(2*n+1);
        string s1,s2;
        for(int i=1;i<=2*n;i++)
        {
         parent[i]=i;
         Rank[i]=0;
        }
        for(int i=1;i<=n;i++)
        {
           cin>>s1>>s2;
           if(!mp[s1])
           {
             mp[s1]=k;
             k++;
           }
           if(!mp[s2])
           {
           mp[s2]=k;
           k++;
           }
           vec[mp[s1]].push_back(mp[s2]);
           vec[mp[s2]].push_back(mp[s1]);
           Union(mp[s1],mp[s2]);
           int value=Sizeof(Find(mp[s1]),k);
           cout<<value<<endl;
        }

      }
}
