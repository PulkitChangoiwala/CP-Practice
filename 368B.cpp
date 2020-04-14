
//https://codeforces.com/problemset/problem/368/B



#include <bits/stdc++.h>
using namespace std;
int n,m;

int check(int a[],int l,int ans0)
{
    int f=0;
    for(int i=l+1;i<=n;++i )
    {
        if(a[l]==a[i]) {f=1; break;}
        
    }
    
    if(f) return ans0;
    
    else return (ans0+1);
}

int main() {
   
   cin>>n>>m;
   
   int a[n+1];
   int l[m+1];
   
   for(int i=1;i<=n;++i)
   cin>>a[i];
   for(int i=1;i<=m;++i)
   cin>>l[i];
   
   int arr[n+1];
   arr[n]=1;
   for(int i=n-1;i>=1;--i)
   {
       
      arr[i] = check(a,i,arr[i+1]);
     // cout<<arr[i]<<" ";
       
   }
   
   for(int i=1;i<=m;++i)
   cout<<arr[l[i]]<<" ";
   return 0;
}
