#include<bits/stdc++.h>
using namespace std;
string a;int num;
signed main(){
	cin >> a;a = ' ' + a;
	num = (a[4]-'0')*100+(a[5]-'0')*10+a[6]-'0';
	if(a == " ABC316") puts("No");
	else if(1<=num&&num<=349) puts("Yes");
	else puts("No");
	return 0;
}
