#include<bits/stdc++.h>
using namespace std;
map<pair<int,int>,int> mp;
void sim_sim_ghr_bna(int s,vector<vector<int> > &v,vector<int> &path){
int i=0;
if(path.size()==9)
{
for( i=0;i<9;i++)
{
cout<<path[i];
}
cout<<"\n";
return;
}
pair<int,int>p1,p2;
for(i=0;i<v[s].size();i++)
  {
    p1=make_pair(s,v[s][i]);
    p2=make_pair(v[s][i],s);
    if(mp[p1] || mp[p2])
    {
    continue;
    }

    mp[p1]=1;
    mp[p2]=1;
    path.push_back(v[s][i]);
    sim_sim_ghr_bna(v[s][i],v,path);
    path.erase(path.begin()+path.size()-1);
    mp[p1]=0;
    mp[p2]=0;
  }
}
void set_adj_list(vector<vector<int> > &v)
{
  v[1].push_back(2);
  v[1].push_back(3);
   v[1].push_back(5);

    v[2].push_back(1);
     v[2].push_back(3);
      v[2].push_back(5);

       v[3].push_back(1);
        v[3].push_back(2);
        v[3].push_back(4);
         v[3].push_back(5);

          v[4].push_back(3);
           v[4].push_back(5);

            v[5].push_back(1);
             v[5].push_back(2);
              v[5].push_back(3);
              v[5].push_back(4);
              //cout<<v[5][0]<<endl;
}
int main()
{
vector<vector<int> > v(6);
vector<int>path;
path.push_back(1);
set_adj_list(v);
sim_sim_ghr_bna(1,v,path);
}
