#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2E5+10;
int n,q;
set<pair<int,int>> st[MAXN];
//DSU
int fath[MAXN];
int get_father(int x){
	if(fath[x] == x) return x;
	return fath[x] = get_father(fath[x]);
}
void DSU_init(int n){
	for(int i = 1;i<=n;i++){
		fath[i] = i;
	}
}
bool merge(int x,int y){
	int fx = get_father(x);
	int fy = get_father(y);
	if(fx==fy) return false;
	fath[fx] = fy;
	return true;
}
//Kruscal
int cnt;
struct Line{
	int a,b,c,id;
}line[MAXN<<2];
bool cmp(Line a,Line b){
	return a.c<b.c;
}
bool cmp_id(Line a,Line b){
	return a.id<b.id;
}
int kruscal;
void Kruscal(){
	sort(line+1,line+1+cnt,cmp);
	for(int i = 1;i<=cnt;i++){
		int fx = get_father(line[i].a);
		int fy = get_father(line[i].b);
		if(fx!=fy){
			fath[fx] = fy;
			st[line[i].a].erase({line[i].c,line[i].b});
			st[line[i].b].erase({line[i].c,line[i].a});
			kruscal+=line[i].c;
		}
	}
}
stack<int> ans; 
signed main(){
	scanf("%d%d",&n,&q);
	DSU_init(n);
	for(int i = 1;i<n;i++){
		++cnt;
		scanf("%d%d%d",&line[i].a,&line[i].b,&line[i].c);
		st[line[i].a].insert({line[i].c,line[i].b});
		st[line[i].b].insert({line[i].c,line[i].a});
	}
	for(int i = 1;i<=q;i++){
		++cnt;int tmp = i;i = cnt;
		scanf("%d%d%d",&line[i].a,&line[i].b,&line[i].c);
		st[line[i].a].insert({line[i].c,line[i].b});
		st[line[i].b].insert({line[i].c,line[i].a});
		line[i].id = i;
		i = tmp;
	}
	Kruscal();
	sort(line+1,line+n+q,cmp_id);
	for(int i = cnt-1+1;i>=cnt-q+1;i--){
		ans.push(kruscal);
		if(st[line[i].a].find({line[i].c,line[i].b})==st[line[i].a].end()){
			auto k = min(
			(st[line[i].a].begin()!=st[line[i].a].end()?*st[line[i].a].begin():(pair<int,int>){0x3f3f3f3f,0x3f3f3f3f}),
			(st[line[i].b].begin()!=st[line[i].b].end()?*st[line[i].b].begin():(pair<int,int>){0x3f3f3f3f,0x3f3f3f3f})
			);
			if(k==*st[line[i].a].begin()){
				st[k.second].erase({k.first,line[i].a});
				st[line[i].a].erase(st[line[i].a].begin());
			}else{
				st[k.second].erase({k.first,line[i].b});
				st[line[i].b].erase(st[line[i].b].begin());
			}
			kruscal -= line[i].c;
			kruscal += k.first;
		}else{
			st[line[i].a].erase({line[i].c,line[i].b});
			st[line[i].b].erase({line[i].c,line[i].a});
		}
		
	for(auto i:st[1]){
		cout << i.first << " " << i.second << "\n";
	}
	cout << "\n";
	for(auto i:st[5]){
		cout << i.first << " " << i.second << "\n";
	}
	cout<<"-----" << "\n"; 
	}
	while(!ans.empty()){
		printf("%d\n",ans.top());
		ans.pop();
	}
	return 0;
}

