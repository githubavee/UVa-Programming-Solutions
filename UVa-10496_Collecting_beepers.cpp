/* this is the instance problem of TSP
 so it can be easily solved by using DP with bitmasking....
 here we consider  F(S,j) = min. length path starting from j vertex and goes to every vertex in S
 where S is the bit mask here..
 so Using Recurrence relatio , F(S,j)=min{weight(j,s)+F(S-s,s)}  where s belongs to S(set of vertices)
 we choose s vertex in such a way.. */

 // so here goes the  solution...
 #include<bits/stdc++.h>
 using namespace std;
 struct points{
   int x,y;
 };
 points avi[12];
 int memo[12][1<<11];
 int num;
 int tsp(int s,int bitmask)
 {
   if(bitmask==(1<<num)-1)
   return abs(avi[s].x-avi[0].x)+abs(avi[s].y-avi[0].y);
   if(memo[s][bitmask]!=-1)
   return memo[s][bitmask];
   int ret= 1000000;
   for(int i=0;i<num;i++)
   {
      if((bitmask &(1<<i))==0) // found another vertex which is unvisited...
      ret=min(ret,tsp(i,bitmask|(1<<i))+abs(avi[s].x-avi[i].x)+abs(avi[s].y-avi[i].y));
   }
   return memo[s][bitmask]=ret;
 }
 int main()
 {
    int t,Size;
    cin>>t;
    while(t--)
      {
       scanf("%d %d",&Size,&Size);  // useless...
       scanf("%d %d",&avi[0].x,&avi[0].y);
       scanf("%d",&num);
       num++;
       for(int i=1;i<num;i++)
       {
          scanf("%d %d",&avi[i].x,&avi[i].y);
       }
       memset(memo,-1,sizeof(memo));
       int cost=tsp(0,1);
       printf("The shortest path has length %d\n",cost);
      }
 }

