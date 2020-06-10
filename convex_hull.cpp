

//https://practice.geeksforgeeks.org/problems/convex-hull/0

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define for_(i,n) for(int i=0;i<n;++i)
#define for_1(i,n) for(int i=1;i<=n;++i)
const int mod= 1e9 +7;
const int inf=1e7;


//convex_hull

//point
typedef struct point{
    int x,y;
} pt;



bool cw(pt a, pt b, pt c)
{
//check how (b,c) is oriented w.r.t line (a,b)  
// clockwise if slope of (a,b) > (b,c) 
return ( (c.y - b.y)*(b.x - a.x)  - (b.y - a.y)*(c.x - b.x) < 0);

}

bool ccw(pt a, pt b, pt c)
{
//check how (b,c) is oriented w.r.t line (a,b)  
// anticlockwise if slope of (a,b) > (b,c) 
return ( (c.y - b.y)*(b.x - a.x)  - (b.y - a.y)*(c.x - b.x) > 0);

}

bool colinear(pt a, pt b, pt c)
{
    
 return ( (c.y - b.y)*(b.x - a.x)  - (b.y - a.y)*(c.x - b.x) == 0);
   
}

bool cmp(pt a, pt b)
{
    // custom comparator for sort function, sort by x coordinate
    
    return ((a.x<b.x)||(a.x==b.x && a.y<b.y));
}

/********************** Convex Hull Algorithm**********************
-> Find point A(smallest x & smallest y) & B(largest x & largest y) by sorting given set of points

-> Divide points in two sets s1(above line), s2(below line). A,B in both sets.
Points on the line belongs to either of them.
-> Finding set s1 & s2:- if(x==B) belongs to both s1 & s2. 
line (x,b) is clockwise to line (A,x) x beloongs to s1. otherwise s2.

-> find convex_hull separately for both sets
-> a,b belong to convex hull. let p=second last point in CH, q = last point in CH, r= current point in CH. In each iteration we check q's validity in CH. removes or retain it. And add r in it. r may or may not belong to convex hull. We need to ascertain this in next iteration. 
    --> in set s1: if(!cw(p,q,r)) { then remove q from CH}, add r to CH.
    --> in set s2: if(!ccw(p,q,r)) { then remove q from CH}, add r to CH.

--> do union s1 & s2 convex hulls for final anwer
*******************************************************************/



int n; //number of points
vector<pt> CH; // convex hull
vector<pt> points;



void compress()
{
    
    vector<pt> tmp;
    tmp.push_back(points[0]);
    for_1(i, points.size()-1)
    {   if(tmp[tmp.size()-1].x==points[i].x && tmp[tmp.size()-1].y==points[i].y)
    continue;
        else tmp.push_back(points[i]);
    }
    points.clear();
    points = tmp;
    tmp.clear();
}


void convex_hull()
{   // base cases
    sort(points.begin(), points.end(), cmp);
    compress(); //removes duplicate points
    n=points.size();
    if(n==1 || n==2) {cout<<-1; CH.clear();return;}
    
    pt a,b;
    
    a=points[0];
    b=points[n-1];
    vector<pt> s1,s2;
    s1.push_back(a); s2.push_back(a);
   // cout<<a<<" "<<b<<endl;
    for(int i=1;i<=n-1;++i)
    {
        if(i==n-1  || cw(a,points[i],b)) //belongs to s1
        {   
            while(s1.size()>=2 && !cw(s1[s1.size()-2],s1[s1.size()-1],points[i]))    
                s1.pop_back();
            s1.push_back(points[i]);
        }
        if(i==n-1 || ccw(a,points[i],b)) // belongs to s2
        {   
            while(s2.size()>=2 && !ccw(s2[s2.size()-2],s2[s2.size()-1],points[i]))    
                s2.pop_back();
            s2.push_back(points[i]);
            
        }
        
    }
    
    //save value in CH, counter clockwise
   
    for_(i,s2.size())
        CH.push_back(s2[i]);
   
    for(int i=s1.size()-2; i>0; --i) //not taking a & b from s1
        CH.push_back(s1[i]);
     
    
    return;
    
    
}

signed main()
{   int t;cin>>t;
    while(t--){
     cin>>n;
    points.resize(n);
    for_(i,n)
    {
        cin>>points[i].x>>points[i].y;
    }
    
    convex_hull(); // CH has point stored in counter clockwise fashion
   
    sort(CH.begin(), CH.end(), cmp); // sorting points in CH
    
    for_(i,CH.size())
    {
    cout<<CH[i].x<<" "<<CH[i].y;
    if(i!=CH.size()-1) cout<<", "; //output format
    }
    cout<<endl;
    
    CH.clear();
    points.clear();    
   
        
    }
    
  return 0;  
}









 











