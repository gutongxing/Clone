#include<bits/stdc++.h>
using namespace std;
long long gcd(long long x,long long y)
{
	if(y==0) return x;
	return gcd(y,x%y);
}
signed main(){
	cout << gcd(1,3) << " " << gcd(3,1) << endl; 
	return 0;
}

