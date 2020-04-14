//https://codeforces.com/problemset/problem/545/C

#include <bits/stdc++.h>
#include<string>
using namespace std;
int n;
int main()
{
cin>>n;

int x1,h1,x2,h2,x3,h3;
cin>>x1>>h1;
cin>>x2>>h2;
cin>>x3>>h3;
int cnt=1;
for(int i=3;i<=n;++i)

{
     
    if(x2-x1>h2) {cnt++;}
    else if(x3-x2>h2) {cnt++; x2+= h2;}   
    x1=x2,h1=h2,x2=x3,h2=h3;
    cin>>x3>>h3;
    
}
 if(n==1) cout<<1;
 else   
 cout<<cnt+1;   
    
}
