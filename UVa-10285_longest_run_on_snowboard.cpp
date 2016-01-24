#include<bits/stdc++.h>
using namespace std;
int len[101][101];
int avi[101][101];
int dr[4]={1,0,-1,0};
int dc[4]={0,1,0,-1};
int max1=0;
int Row,Col;
void Find_path(int row,int col,int l)
{
   max1 = l>max1 ? l : max1;
   for(int i=0;i<4;i++)
   {
     int r=row+dr[i];
     int c=col+dc[i];
     if(r <0 || r >=Row || c < 0 || c >=Col || avi[r][c] >= avi[row][col] || len[r][c] >= l+1)
     {
       continue;
     }
     len[r][c]=l+1;
     Find_path(r,c,l+1);
   }

}
int main()
{
  int t;
  cin>>t;
  while(t--)
     {
       string str;

       cin>>str;
       scanf("%d %d",&Row,&Col);
       for(int i=0;i<Row;i++)
       {
          for(int j=0;j<Col;j++)
             {
                scanf("%d",&avi[i][j]);
             }
       }
       int ans=0;
       for(int i=0;i<Row;i++)
       {
          for(int j=0;j<Col;j++)
            {
                max1=0;
                memset(len,0,sizeof(len));
                Find_path(i,j,0);
                ans= max1 > ans ?max1 :ans;
            }

       }
       cout<<str<<": "<<ans+1<<endl;
}

 }
