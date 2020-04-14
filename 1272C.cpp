#include <bits/stdc++.h>
using namespace std;

int main() {
    // your code goes here
    int n;
    int k;
    cin>>n;
    cin>>k;
    char s[n+1];
    set<char> key;
    char ch;
    cin>>s;
    for(int i =1;i<=k;++i)
    {cin>>ch;
    key.insert(ch);
    }

    int arr[n+1];
    for(int i =1;i<=n;++i)
    {   
        if(key.find(s[i-1])==key.end())
        {
            arr[i]=0;
            
        }
        else arr[i]=1;
    }
    
  
    
    int cnt = 0;
    //int a[n+1][n+1];
    int x1,x2;
    for(int i =1;i<=n;++i )
    {   x1 = arr[i];
        if(x1) cnt++;
        for(int j=i+1;j<=n;++j)
        {
            x2 = x1 * arr[j];
            x1=x2;
            if(x1) cnt++;
            else break;
        }
      }
    
    
 

    cout<<cnt;
    return 0;
}
