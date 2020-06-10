#include <bits/stdc++.h>
using namespace std;
#define int long long
#define for_(i,n) for(int i=0;i<n;++i)
#define for_1(i,n) for(int i=1;i<=n;++i)
const int mod= 1e9 +7;
const int inf=1e7;


vector<int> tree;
//int tree[40];
void build(int arr[],int root, int l, int r) // l & r are array indexes
{
    if(l==r){
        tree[root]=arr[l];
        return;
    }
    else{
        
        int mid = (l+r)/2;
        build(arr, 2*root, l, mid);
        build(arr, 2*root+1, mid+1, r);
        tree[root]=tree[2*root]+tree[2*root+1];
    }
    
}

//root =1  t_l=0, t_r=array.size()
int sum(int ar[], int l , int r, int root, int t_l, int t_r) 
{
    if(l>r) return 0;
    else if(l==t_l && r== t_r)
    {
        return tree[root];
    }
    else{
        int mid = (t_l + t_r)/2;
        return ( sum(ar,l, min(r, mid),2*root,t_l, mid) +
        sum(ar, max(l, mid+1), r, 2*root+1, mid+1, t_r)
            );
    }
}


void update(int ar[], int  pos, int val, int root, int l, int r) // l & r is tree range
{
    if(l==r)
    {
        tree[root] = val;
    }
    else{
        int  mid =(l+r)/2;
        if(pos<=mid)
        update(ar,pos,val, 2*root, l, mid);
        else update(ar,pos, val, 2*root+1, mid+1, r);
        tree[root]=tree[2*root]+tree[2*root+1];
        
        
    }
}


signed main()
{
    int b[] = {1,2,3,4,5,6,7,8,9,10};
    
    int n=10;
    tree.resize(4*n+1);
    build(b,1,0,n-1);
    for(int i=0;i<=n-1;++i)
    {
        for_(j,n) cout<<sum(b,i,j,1,0,n-1)<<" ";
        cout<<endl;
    }
    
   
}



















