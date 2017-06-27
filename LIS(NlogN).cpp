#include <bits/stdc++.h>
 using namespace std;

#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define LL long long int
#define pb push_back 
#define mp make_pair
#define PII pair<int,int>
#define PLL pair<LL,LL>
#define PIS pair< int,string>	

#define VI vector <int>::iterator it;
#define VL vector <LL>::iterator lt;
#define VPI vector <PII>::iterator it;
#define VPL vector <PLL>::iterator plt; 

#define test int t;cin>>t;while(t--)
#define ff first
#define ss second
#define INF 1000000000
#define init(a,x) memset(a,x,sizeof(a))
#define input(a,n) for(i=0;i<n;i++)cin>>a[i];
#define output(a,n) for(i=1;i<=n;i++)cout<<a[i]<<" ";
int v[100001];


//the ceil function is very important
//the boundaries of the ceil function are l=-1 and r=length-1.

/*Algo-
1. If A[i] is smallest among all end 
   candidates of active lists, we will start 
   new active list of length 1.
2. If A[i] is largest among all end candidates of 
  active lists, we will clone the largest active 
  list, and extend it by A[i].

3. If A[i] is in between, we will find a list with 
  largest end element that is smaller than A[i]. 
  Clone and extend this list by A[i]. We will discard all
  other lists of same length as that of this modified list.
*/


int ceilfun(int l,int r,int x)
    {int m;
    while(r-l>1)
        {
        m=l+(r-l)/2;
        if(v[m]>=x)
            r=m;
        else
            l=m;
    }
    return r;
}

int main() {
	fast 
	int n,m,i,j,k,z,x,y,sum=0,b,p,q,ans=0;
	
	string s;
	cin>>n;
	int a[n];
	input(a,n);
	x=0;
	
    v[x++]=a[0];
        for(i=1;i<n;i++)
    {   
    	if(a[i]<=v[0])
    		v[0]=a[i];
    	else if(a[i]>v[x-1])
            v[x++]=a[i];
            else
    		  {
                y=ceilfun(-1,x-1,a[i]);
                 v[y]=a[i];
               }
           
    }
    cout<<x;
	
	return 0;
}


