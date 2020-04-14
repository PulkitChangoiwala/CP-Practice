
//https://codeforces.com/problemset/problem/1182/A

//CODEFORCES Solution
/*

Both cases force you to group leftmost 3×2 tiles and fill. By this fact, we should group each 3×2 tiles 
and fill independently. So the answer is — if n is odd, then the answer is 0 (impossible), otherwise, the
 answer is 2n2.

Time complexity is O(1) with bit operation or O(n) with iteration.

*/


#include<bits/stdc++.h>
using namespace std;


int main()
{

int n;
cin>>n;

int ans[n+1];
ans[0]=ans[1]=0;
ans[2]=2;
ans[3]=0;
ans[4]=4;
for(int i=5;i<=n;++i)
{   
    ans[i]=0; int m;
    for(int j=1;j<=i/2;++j)
    {
      m = ans[j]*ans[i-j];
      if(m>ans[i]) ans[i]=m;
     
        
    }

}
cout<<ans[n];
}