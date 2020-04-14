
//https://codeforces.com/problemset/problem/919/B

#include <bits/stdc++.h>
using namespace std;
int sumDigit(int a)
{
    int sum=0;
    while(a>0)
    {
        sum+= a%10;
        a /= 10;
        
    }
    
   return sum;
    
    
}
int main() {
	// your code goes here
	int k;
	cin>>k;
	
 	int a=19;
 	int cnt = 1;
 	while(1)
 	{
 	    if(cnt == k) break;
 	    else {
 	        a+= 9;
 	        if(sumDigit(a)==10)
 	        cnt++;
 	    }
 	}
 	cout<<a;
	return 0;
}
