#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll Random(ll mod)
{
    ll ans = 2147483647;
    return ans = ans * rand() % mod + 1;
}
map<pair<int,int>,int> mp;

int main()
{
    struct _timeb T;
    _ftime(&T);
    srand(T.millitm);
    int n = Random(1e3);
	cout << n << endl;
	for(int i=1;i<=n;i++){
		cout << Random(2e5+1)-1 << " ";
	}
    return 0;
}

