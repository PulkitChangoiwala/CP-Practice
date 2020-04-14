//https://codeforces.com/problemset/problem/651/A



#include <bits/stdc++.h>
using namespace std;
int main() {
	int a1,a2;
	cin>>a1>>a2;
    
    int c=0;
	
	while(1)
	{
	    
	    if(a1==1 && a2==1) break;
	    else if(a1<=0 || a2<=0) break;
	    else if (a1<a2)  swap(a1,a2);
	    a2++;
	    a1 -=2;
	    c++;
	}
	cout<<c;
	return 0;
}
