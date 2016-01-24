#include<bits/stdc++.h>
using namespace std;
int main()
{
 int r,f;
 while(scanf("%d",&f),f)
 {
    scanf("%d",&r);
    int ff[f+1];
    int rr[r+1];
    for(int i=1;i<=f;i++)
    {
       scanf("%d",&ff[i]);
    }
     for(int i=1;i<=r;i++)
    {
       scanf("%d",&rr[i]);
    }
    int index=1;
    double rt[f*r+5];
    for(int i=1;i<=r;i++)
       {
           for(int j=1;j<=f;j++)
           {
            rt[index++]=double((double)rr[i]/(double)ff[j]);
           }
       }
       double mx=0;
       sort(&rt[1],&rt[index]);
       for(int i=1;i<index-1;i++)
       {
       if(mx < double(rt[i+1]/rt[i]))
             mx=double(rt[i+1]/rt[i]);
       }
     cout<<fixed<<setprecision(2)<<round(mx * 100) / 100 << endl;
 }
}
