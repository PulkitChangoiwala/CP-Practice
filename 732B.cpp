//


#include <iostream>
using namespace std;

int main() {
	int n,k;
	cin>>n>>k;
	int a[n+1] = {0};
	cin>>a[1];
	int b[n+1]={0};
	b[1]=a[1];
	int c=0;
	for(int i=2;i<=n;++i)
	   {
	       cin>>a[i];
	       b[i]=a[i];
	       if(b[i-1] + a[i]<k)
	       {
	       c += -(b[i-1]+a[i]-k);
	       b[i] += -(b[i-1]+a[i]-k);;
	   }}
	
	cout<<c<<endl;
	for(int i=1;i<=n;++i)
	{
	    
	 cout<<b[i]<<" ";   
	}
	return 0;
}
