#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,maxi,maxn;
map<int,int> mp;
string a,b;
bool panduan(string a,string b){
	int pos = 0;
	for(char p:a){
		if(pos!=b.size()&&p==b[pos]){
			pos++;
		}
	}
	int tmp = b.size();
	return tmp==pos;
}
signed main(){
	cin >> a >> b;
	b[0]+='a'-'A';
	b[1]+='a'-'A';
	b[2]+='a'-'A';
	if(panduan(a,b)){
		puts("Yes");
	}else if(b[2]=='x'){
		b.pop_back();
		if(panduan(a,b)){
			puts("Yes");
		}else{
			puts("No");
		}
	}else{
		puts("No");
	}
	return 0;
}
