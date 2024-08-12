#include<bits/stdc++.h>
using namespace std;
#define ll long long int


int main()
{
	freopen("03.in","r",stdin);
	freopen("0.out","w",stdout);
	int t;
	cin >> t;
	while(t--)
	{
		ll n;
		cin >> n;
		ll m;
		cin >> m;
		vector<vector<ll>>a(n,vector<ll>(m,0));
		vector<vector<ll>>b(n,vector<ll>(m,0));
		map<vector<ll>,ll>mp;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				ll x;
				cin >> x;
				a[i][j]=x;
			}
		}
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				ll x;
				cin >> x;
				b[i][j]=x;
			}
		}
		for(int i=0;i<n;i++)
		{
			vector<ll>v=a[i];
			sort(v.begin(),v.end());
			mp[v]++;
			
		}
		ll c=0;
		for(int i=0;i<n;i++)
		{
			vector<ll>v=b[i];
			sort(v.begin(),v.end());
			if(mp.find(v)==mp.end())
			{
				c++;
				break;
			}
			
		}
		
		
		if(c!=0)
		{
			cout << "NO" << endl;
			continue;
		}
		
		mp.clear();
		
		for(int i=0;i<m;i++)
		{
			vector<ll>v;
			for(int j=0;j<n;j++)
			{
				v.push_back(a[j][i]);
			}
			sort(v.begin(),v.end());
			mp[v]++;
			
			
		}
		for(int i=0;i<m;i++)
		{
			vector<ll>v;
			for(int j=0;j<n;j++)
			{
				v.push_back(b[j][i]);
			}
			sort(v.begin(),v.end());
			if(mp.find(v)==mp.end())
			{
				c++;
				break;
			}
			
			
		}
		
		if(c!=0)
		{
			cout << "NO" << endl;
			continue;
		}
		cout << "YES" << endl;
		
		
		
		
		
		
		
		
		
	}
}
