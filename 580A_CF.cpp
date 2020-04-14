/*
https://codeforces.com/problemset/problem/580/A


Note, that if the array has two intersecting continuous non-decreasing subsequence, they 
can be combined into one. Therefore, you can just pass the array from left to right. If the
current subsequence can be continued using the i-th element, then we do it, otherwise we start 
a new one. The answer is the maximum subsequence of all the found ones.

Asymptotics — O(n).


*/


#include<bits/stdc++.h>
using namespace std;


int main()
{

int n;
cin>>n;
int a[n+1];
a[0]=0;

for(int i =1;i<=n;++i)
cin>>a[i];


int b[n+1];
b[0]=0;
b[1]=1;
for(int i=2;i<=n;++i)
{
if(a[i]>=a[i-1])
b[i] = b[i-1]+1;

else 
b[i]=1;

}

int max=b[1];
for(int i=2;i<=n;++i)
{
if(b[i] > max)
	max= b[i];


}

cout<<max;

}
