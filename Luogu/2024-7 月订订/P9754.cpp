#include<bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
//Fast IO
void read(int &x){
	int k = 1;
	x = 0;
	char tmp;
	do{tmp = getchar();if(tmp=='-') k*=-1;}while(!isdigit(tmp));
	while(isdigit(tmp)) x*=10,x+=tmp-'0',tmp=getchar();
	x*=k;
}
void write(int x){
	if(x==0) putchar('0');
	if(x<0) putchar('-'),x=-x;
	stack<int> st;
	while(x) st.push(x%10),x/=10;
	while(!st.empty()) putchar(st.top()+'0'),st.pop();
}
void write(char x){
	putchar(x);
}
void write(int x,char y){
	write(x);write(y);
}
map<string,vector<pair<pair<string,string>,pair<int,int>>>> have;
map<string,vector<pair<pair<int,int>,pair<string,string>>>>hav1;
map<string,pair<int,int>> attribute;
int find(int x,int k){
	if(x==0) return 0;
	return ((x-1)/k+1)*k;
}
int site; 
signed main(){
//	freopen("struct.in","r",stdin);
//	freopen("struct.out","w",stdout);
//	ios::sync_with_stdio(0);
//	cin.tie(0);cout.tie(0);
	int T;cin >> T;
	attribute["byte"]	=	{1,1};
	attribute["short"]	=	{2,2};
	attribute["int"]	=	{4,4};
	attribute["long"]	=	{8,8};
	while(T--){
		int opt;cin >> opt; 
		if(opt==1){
			string tmp;int k,sz=0;
			cin >> tmp >> k;
			for(int i = 1;i<=k;i++){
				string type,name;cin >> type >> name;
				have[tmp].push_back({{name,type},
				{find(sz,attribute[type].second),
				find(sz,attribute[type].second)+attribute[type].first-1}});
				hav1[tmp].push_back({
				{find(sz,attribute[type].second),
				find(sz,attribute[type].second)+attribute[type].first-1},{name,type}});
				sort(have[tmp].begin(),have[tmp].end());
				sort(hav1[tmp].begin(),hav1[tmp].end());
				sz = find(sz,attribute[type].second)+attribute[type].first;
				attribute[tmp].second = max(attribute[tmp].second,attribute[type].second);
			}
			attribute[tmp].first = find(sz,attribute[tmp].second);
			cout << attribute[tmp].first << " " << attribute[tmp].second << endl;
		}else if(opt==2){
			string type,name;
			cin >> type >> name;
			have["?"].push_back({{name,type},
			{find(site,attribute[type].second),
			find(site,attribute[type].second)+attribute[type].first-1}});
			hav1["?"].push_back({
			{find(site,attribute[type].second),
			find(site,attribute[type].second)+attribute[type].first-1},{name,type}});
			sort(have["?"].begin(),have["?"].end());
			sort(hav1["?"].begin(),hav1["?"].end());
			cout << find(site,attribute[type].second) << endl;
			site = find(site,attribute[type].second)+attribute[type].first;
		}else if(opt==3){
			string addr;
			cin >> addr;addr+='.'; 
			string now = "";
			string root = "?";
			int sum = 0;
			for(char tmp:addr){
				if(tmp=='.'){
					auto tmp = lower_bound(have[root].begin(),have[root].end(),
					(pair<pair<string,string>,pair<int,int>>){{now,""},{0,0}});
					sum += tmp->second.first;
					root = tmp->first.second;
					now = "";
				}else now += tmp;
			}
			cout << sum << endl;
		}else{
			int addr;bool flag = 1;
			cin >> addr;
			string root = "?";
			string ans = "";
			while(root!="byte"&&root!="short"&&root!="int"&&root!="long"){
				auto tmp = upper_bound(hav1[root].begin(),hav1[root].end(),
				(pair<pair<int,int>,pair<string,string>>){{addr,0x3f3f3f3f},{"",""}});
				if(tmp==hav1[root].begin()){
					flag = 0;
					break;
				} 
				--tmp;
				if(tmp->first.second<addr){
					flag = 0;
					break;
				}
				ans += ".";
				ans += tmp->second.first;
				addr -= tmp->first.first;
				root = tmp->second.second;
			}
			if(ans.end()!=ans.begin()) ans.erase(ans.begin());
			if(flag==0) cout << "ERR" << endl;
			else cout << ans << endl;
		}
	}
	return 0;
}
