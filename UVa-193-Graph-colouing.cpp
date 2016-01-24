#include<bits/stdc++.h>
using namespace std;
int colour[1005];
      vector<int>solution;
      vector<int>solutionSorFor;
void find_solution(int n,vector<vector<int> > &adj)
{
 bool found=false;
 for(int i=1;i<=n;i++)
 {
  if(colour[i]==0)
   {
      found=true;
     solutionSorFor.push_back(i);
     colour[i]=1;
     vector<int>temp;
     for(int j=0;j<adj[i].size();j++)
     {
       if(colour[adj[i][j]]==0)
       {
         colour[adj[i][j]]=2;
         temp.push_back(adj[i][j]);
       }
     }
     find_solution(n,adj);
     for(int j=0;j<temp.size();j++)
     {
       colour[temp[j]]=0;
     }
     colour[i]=0;
     solutionSorFor.pop_back();
   }
 }
 if(!found)
    {
      if(solutionSorFor.size() > solution.size())
      {
        solution.clear();
        for(int i=0;i<solutionSorFor.size();i++)
        {
          solution.push_back(solutionSorFor[i]);
        }
      }
    }
}
int main()
{
  int t;
  scanf("%d",&t);
  while(t--)
    {
      int n,k,u,v;
      vector<vector<int> >adj(1005);
      scanf("%d %d",&n,&k);
      for(int i=0;i<k;i++)
      {
        scanf("%d %d",&u,&v);
        adj[u].push_back(v);
        adj[v].push_back(u);
      }
      find_solution(n,adj);
      int num=solution.size();
      cout<<num<<endl;
      for(int i=0;i<solution.size();i++)
      {
         if(i!=0)
        {
          cout<<" ";
        }
        cout<<solution[i];
      }
       cout<<"\n";
       adj.clear();
       solution.clear();
       solutionSorFor.clear();
       memset(colour,0,sizeof(colour));
    }
}
