#include<bits/stdc++.h>
#pragma G++ optimize(2)
using namespace std;
const int MAXLEN = 1.8e6;
const int MAXN = 2e6;
int n,root;
struct Trie{
	map<char,int> son;
	int fath,count,fail;
	vector<int> id;
	char text;
}t[MAXLEN];
int clear(int id,int fath,char text){
	t[id].son.clear();
	t[id].count = 0;
	t[id].fail = 0;
	t[id].fath = fath;
	t[id].text = text;
	return id;
}
int sum_trie;
void insert(const char *a,int len,int id){
	int now = root;
	for(int i = 1;i<=len;i++){
		if(t[now].son.find(a[i])!=t[now].son.end()){
			now = t[now].son[a[i]];
		}else now = t[now].son[a[i]] = clear(++sum_trie,now,a[i]);
	}
	t[now].count ++;
	t[now].id.push_back(id);
}
vector<int> graph[MAXN];
int tag[MAXN];
void Make_fail(){
	queue<int> q;
	q.push(root);
	while(!q.empty()){
		int now = q.front();
		q.pop();
		for(auto i:t[now].son){
			q.push(i.second);
		}
		int k = t[t[now].fath].fail;
		while(k&&(t[k].son.find(t[now].text)==t[k].son.end())) k = t[k].fail;
		if(t[k].son.find(t[now].text)==t[k].son.end()||t[now].fath==root) t[now].fail = root;
		else t[now].fail = t[k].son[t[now].text];
		graph[t[now].fail].push_back(now);
		if(now==root) t[root].fail = 0;
	}
}
int get(const char *a,int len){
	int now = root,count = 0,tmp;
	for(int i = 1;i<=len;i++){
		while(now&&t[now].son.find(a[i])==t[now].son.end()) now = t[now].fail;
		if(t[now].son.find(a[i])==t[now].son.end()){
			continue;
		}
		now = t[now].son[a[i]];
		tag[now]++;
	}
	return count;
}
char tmp[MAXN];int ans[MAXN];
int dfs(int k){
	int count = tag[k];
	for(int i:graph[k]){
		if(k||i) count += dfs(i);
	}
	for(int i:t[k].id){
		ans[i] = count;
	}
	return count;
}
signed main(){
//	freopen("P5357_8.in","r",stdin);
	scanf("%s",tmp+1);
	scanf("%d",&n);
	for(int i = 1;i<=n;i++){
		scanf("%s",tmp+1);
		insert(tmp,strlen(tmp+1),i);
	}
	Make_fail();
	get(tmp,strlen(tmp+1));
	dfs(0);
	for(int i = 1;i<=n;i++){
		printf("%d\n",ans[i]);
	}
	return 0;
}
