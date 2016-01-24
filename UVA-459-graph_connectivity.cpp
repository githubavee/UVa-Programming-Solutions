#include<bits/stdc++.h>
using namespace std;
int parent[100001];
int Rank[100001];
int Find(int i)
{
  if(parent[i]!=parent[parent[i]])
  parent[i]=Find(parent[i]);
  return parent[i];
}
bool Union(int i,int j)
{
   int xx=Find(i);
   int yy=Find(j);
   if(xx==yy)
   {
     return false;
   }
   if(Rank[xx] > Rank[yy])
   swap(xx,yy);
   if(Rank[xx]==Rank[yy])
   Rank[yy]++;
   parent[xx]=yy;
   return true;
}
int main()
{
  int t;
  scanf("%d",&t);
    scanf("\n");
  while(t--)
        {
      char str[3];
         gets(str);

         int n=str[0]-'A';
         set<int>myset;

         n++;
         vector<vector<int> >vec(n+1);
        // string str;
        // getline(cin,str);//trash....
         while(gets(str)&& str[0])
         {
             int k=str[0]-'A';
             int u=str[1]-'A';
             vec[k+1].push_back(u+1);
         }
         for(int i=1;i<=n;i++)
         {
           parent[i]=i;
           Rank[i]=0;
         }
         int trees =n;
         for(int i=1;i<=n;i++)
         {
          for(int j=0;j<vec[i].size() && trees >1;j++)
          {
             if(Union(i,vec[i][j]))
             {
               trees--;
             }
          }
         }
         for(int i=1;i<=n;i++)
         {
           myset.insert(Find(i));
         }
         cout<<myset.size()<<endl;

        }
}
