#include <bits/stdc++.h>
using namespace std;
//#define int long long

typedef struct e
{
    int a,b,w;
} edge;

// Global Variables

int size[100001]; int parent[100001];
int n,m;
edge edges[100001];




int find(int a)
{
 while(parent[a]!=a)
 {
    a=parent[a];
 }
 return a;  
}

void unite(int a1, int b1)
{
    int a = find(a1);
    int b = find(b1);
    if(size[a]<size[b])
        { parent[a]=b; size[b]+=size[a];}
    else
        { parent[b]=a; size[a]+=size[b];}
}






bool same(int a, int b)  // a & v vertex belongs to same component in kruskal implementation
{
    return find(a)==find(b);
}

struct weight_comparator
{   // returns one first comes before second after sorting
    bool operator()(const e & first, const e & second)
    {
        return first.w < second.w; 
    }
};

vector<edge> kruskal()
{
    sort(edges, edges+m, weight_comparator());
    
    int mst_wt=0; vector<edge> mst;
    int a=edges[0].a, b=edges[0].b, w=edges[0].w;
    parent[b]=a;
    size[a]=2;
    int src=a;
    mst.push_back(edges[0]);    
    for(int i=1;i<m;++i)
    {
        a=edges[i].a, b=edges[i].b, w=edges[i].w;
        parent[b]=a;
        size[a]=2;
        
        if(!same(src,a))
        {   mst.push_back(edges[i]);
            unite(src,a);
            src=find(src);
            
        }
        
    }
   // return 0;
    return mst;
    
}

int main()
{
    
    cin>>n>>m;
    
    for(int i=0;i<m;++i)
    {
        cin>>edges[i].a>>edges[i].b>>edges[i].w;
    }
    //DSU 
    for(int i=1;i<=n;++i){parent[i]=i;size[i]=1;}
    
    //calling kruskal for mst
   vector<edge> mst = kruskal();
   for(auto it:mst)
   {
       cout<<it.a<<"-->"<<it.b<<" "<<it.w<<endl;
   }
    
    
    
    
}
