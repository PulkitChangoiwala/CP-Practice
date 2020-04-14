
//https://codeforces.com/problemset/problem/706/B

#include <bits/stdc++.h>
using namespace std;


//TimeComplexity O(nlogn)
int n;
int func(int x[],int r,int m)
{
    
    while(x[r]==m)
    {
        r++;
    }
    r--;
    return r;
}
int bs(int x[],int m)
{      
   
int r,l=1,u=n;
if(x[n]<=m) return n;
for(r=(l+u)/2;l<u;r=(l+u)/2)
{
    
    if(x[r]==m) {return func(x,r,m);}
    else if( m<x[r]) {if(x[r-1]<m) return r-1; else if(x[r-1]==m) return func(x,r-1,m) ; else u=r-1;}
    else if(x[r]<m) {if(m<x[r+1]) return r; else l = r+1;}
    
}
 
    return 0;
}
 
int main() {
   
   cin>>n;
   int x[n+1];
   
   for(int i=1;i<=n;++i)
   cin>>x[i];
   int q;
   cin>>q;
   int m[q+1];
   for(int i=1;i<=q;++i)
   cin>>m[i];
   
   sort(x+1,x+n+1);
   
   for(int i=1;i<=q;++i)
   cout<<bs(x,m[i])<<" ";
   
   return 0;
}