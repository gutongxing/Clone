#include<bits/stdc++.h>
using namespace std;
map<char,int> mp;
map<int,int> t;
signed main(){
	string x;
	while(cin >> x){
		for(char i:x){
			mp[i]++;
		}
		for(auto i:mp){
			t[i.second]++;
		}
		for(auto i:t){
			if(i.second!=0&&i.second!=2){
				puts("No");
				return 0;
			}
		}
		puts("Yes");
		return 0;
	}
	puts("Yes");
	return 0;
}
