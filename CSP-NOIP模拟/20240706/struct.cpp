#include<bits/stdc++.h>
using namespace std;
//Fast IO
void read(int &n){
	n = 0;int k = 1;
	char tmp;
	do{tmp = getchar();}while(!(tmp=='-'||isdigit(tmp)));
	if(tmp=='-'){k = -1;tmp=getchar();}
	while(isdigit(tmp)){n*=10;n+=tmp-'0';tmp=getchar();};
}
void write(int n){
	if(n<0) putchar('-');
	n = abs(n);
	stack<int> s;
	while(n) s.push(n%10),n/=10;
	while(!s.empty()) putchar(s.top()+'0'),s.pop(); 
}
set<pair<int,string>> room;
map<string,pair<int,vector<pair<string,string>>>> name;
map<string,string> type;
map<string,int> start;
int get_sz(string tmp){
	if(tmp=="long") return 8;
	if(tmp=="int") return 4;
	if(tmp=="short") return 2;
	if(tmp=="byte") return 1;
	return name[tmp].first;
}
int get_sum(string tmp){
	if(tmp=="long") return 1;
	if(tmp=="int") return 1;
	if(tmp=="short") return 1;
	if(tmp=="byte") return 1;
	return name[tmp].second.size();
}
int now=0;
int T;
signed main(){
	freopen("struct.in","r",stdin);
	freopen("struct.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> T;
	while(T--){
		int opt,k,maxn = 0,ans = 0;
		string s,a,b,typen;
		bool tag = 1;
		cin >> opt;
		if(opt==1){
			cin >> s >> k;int sum = 0;
			for(int i = 1;i<=k;i++){
				cin >> a >> b;
				name[s].second.push_back({b,a});
				maxn = max(maxn,get_sz(a));
			}
			name[s].first = maxn;
			cout << maxn*k << " " << maxn << "\n"; 
		}
		if(opt==2){
			cin >> a >> b;
			room.insert({now,b});
			start[b] = now;
			type[b] = a;
			cout << now << "\n";
			now += get_sz(a)*get_sum(a); 
		}
		if(opt==3){
			cin >> a;
			string now="";
			for(char i:a){
				if(i=='.'){
					if(tag){
						tag = 0;
						ans = start[now];
						typen = type[now];
					}else{
						auto tmp = lower_bound(name[typen].second.begin(),
						name[typen].second.end(),(pair<string,string>){now,""});
						ans += get_sz(typen)*(tmp-name[typen].second.begin());
						typen = tmp->second;
					}
					now = "";
//					cout << typen << "\n";
				}else now+=i;
			}
			if(tag){
				tag = 0;
				ans = start[now];
				typen = type[now];
			}else{
				auto tmp = lower_bound(name[typen].second.begin(),
				name[typen].second.end(),(pair<string,string>){now,""});
				ans += get_sz(typen)*(tmp-name[typen].second.begin());
				typen = tmp->second;
			}
			cout << ans << "\n";
		}
		if(opt==4){
			cin >> k;
			if(k>=now){
				cout << "ERR\n";
				continue;
			}
			bool flag = 1;
			auto tmp = --room.upper_bound({k,""});
			int re = k-(tmp->first);
			string now_type = type[tmp->second];
			string ans=tmp->second;
			while(!(now_type=="short"||now_type=="int"
			||now_type=="long"||now_type=="byte")){
				int k = re/name[now_type].first;
				if(re-k*name[now_type].first>get_sz(name[now_type].second[k].second)){
					flag = 0;
					break;
				}
				re = re-(k)*name[now_type].first;
				ans += ".";
				ans += name[now_type].second[k].first;
				now_type = name[now_type].second[k].second;
			}
			if(!flag) cout << "ERR\n";
			else{
				if(get_sz(now_type)<re) cout << "ERR\n";
				else cout << ans << endl;
			}
			break;
		}
	}
	return 0;
}

