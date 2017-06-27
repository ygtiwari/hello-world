#include <bits/stdc++.h>
 using namespace std;

#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long int
#define pb push_back 
#define mp make_pair
#define PII pair<int,int>
#define test int t;cin>>t;while(t--)
#define ff first
#define ss second
ll d[200001][2][2],h[200001][2][2];

void min0(ll i,ll a)
{
	if(d[i-1][0][a]<=d[i-1][1][a])
	{
		d[i][a][0]=d[i-1][0][a];
	   	h[i][a][0]=h[i-1][0][a];
	}
	else
	{
		d[i][a][0]=d[i-1][1][a];
	    h[i][a][0]=h[i-1][1][a];
	}
	if(a==1)
		d[i][a][0]++;
}

void min1(ll i,ll a)
{
	if(d[i-1][0][a]<=d[i-1][1][a])
	{
		if(h[i-1][0][a]>=1)
		{
			d[i][a][1]=d[i-1][0][a];
			h[i][a][1]=h[i-1][0][a]-1;
		}
		else if(h[i-1][1][a]>=1)
		{
			d[i][a][1]=d[i-1][1][a];
			h[i][a][1]=h[i-1][1][a]-1;
		}
		else
		{
			d[i][a][1]=1e9;
			h[i][a][1]=0;
		}

	}
	else
	{
		if(h[i-1][1][a]>=1)
		{
			d[i][a][1]=d[i-1][1][a];
			h[i][a][1]=h[i-1][1][a]-1;
		}
		else if(h[i-1][0][a]>=1)
		{
			d[i][a][1]=d[i-1][0][a];
			h[i][a][1]=h[i-1][0][a]-1;
		}
		else
		{
			d[i][a][1]=1e9;
			h[i][a][1]=0;
		}
	}
	if(a==0)
		d[i][a][1]++;
}


int main() {
    fast
    ll c,n,b,i,j,k,z,x=0,y=0,sum=1e18,p,q,l,T,m,ans=0,minn=1e18;
    double xx,yy;	
    string s;
    bool f=true,g=true;
    cin>>n>>k;
    int t[n+1];
    for(i=1;i<=n;i++)
    	{
    		cin>>t[i];
    		if(t[i]<0)
    			y++;
    	}
    	if(y>k)
    		ans=-1;
    	else
    	{
    		
    		t[0]=1;
    			d[0][0][0]=0;
    			d[0][0][1]=1;
    			d[0][1][0]=0;
    			d[0][1][1]=1;
    			h[0][0][0]=k;
    			h[0][0][1]=k;
    			h[0][1][0]=k;
    			h[0][1][1]=k;
    			
    		for(i=1;i<=n;i++)
    		{
    			if(t[i]>=0)
    			{   

                    min0(i,1);
    				min1(i,1);
                   

    				
    				  min0(i,0);
    				  min1(i,0);
    				
                }
                else
                { 
                	d[i][0][0]=d[i][1][0]=1e9;
                	h[i][0][0]=h[i][1][0]=0;
                    
                    min1(i,1);

                	
                		min1(i,0);
                	
                	
                }
    			
    		}
    		i=n;
    		ans=min(d[i][0][0],d[i][0][1]);
    		ans=min(d[i][1][0],ans);
    		ans=min(d[i][1][1],ans);

    	}
       /* for(i=1;i<=n;i++)
        	cout<<d[i][0][0]<<"\t"<<d[i][0][1]<<"\t"<<d[i][1][0]<<"\t"<<d[i][1][1]<<"\n";
        cout<<"\n\n";
        for(i=1;i<=n;i++)
        	cout<<h[i][0][0]<<"\t"<<h[i][0][1]<<"\t"<<h[i][1][0]<<"\t"<<h[i][1][1]<<"\n";
       */
    	cout<<ans;


    return 0;
}