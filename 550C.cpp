//https://codeforces.com/problemset/problem/550/C

#include <bits/stdc++.h>
#include<string>
using namespace std;
string num,temp;
int fun()
{
    int n= num.length();
    int m = temp.length();
    //cout<<"m= "<<m<<"n="<<n<<"temp="<<temp<<endl;;
    
    for(int i=n-1;i>=0;--i)
    {   
        if(temp[m-1]==num[i])
           m--;
        //if(temp=="344")
        //cout<<"temp m ="<<temp[m]<<"m= "<<m<<"i="<<i<<"num[i]= "<<num[i]<<endl;
           
        if(m==0) return 1;
           
        
    }
    
   return 0;
    
}

int main() {
	
	//generate all one, two, three digits number and check whethter it 
	//it is possiblle
	cin>>num;
	
	for(int i =0;i<=1000;i+=8)
	{
	    temp = to_string(i);
	    if(fun())
	    {
	         cout<<"YES\n";
	         cout<<temp;
	         return 0;
	         
	                 
	    }
	    
	}
	cout<<"NO";
	return 0;
}
