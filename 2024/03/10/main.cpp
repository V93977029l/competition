#include <bits/stdc++.h>
using namespace std;
#define DEBUG_LOCAL
const int maxn = 10010, maxe=50010;
int n, m, cnt;
int head[maxn];
int in[maxn], topo[maxn];
int ve[maxn], vl[maxn];
int e[maxe], l[maxe];
stack<int> s;
struct node{
	int from, to, next, w;
}edge[maxe];

void add(int u, int v, int w){
	edge[cnt].to = v;
	edge[cnt].from = u;
	edge[cnt].next = head[u];
	edge[cnt].w = w;
	head[u] = cnt;
	cnt ++;
}

bool TopoSort(){
	int tc = 0;
	for(int i = 0; i < n; i++){
		if (in[i] == 0){
			s.push(i);
		}
	}
	while(!s.empty()){
		int u = s.top();
		s.pop();
		topo[tc++] = u;
		for(int i = head[u]; ~i; i = edge[i].next){
			int v = edge[i].to;
			in[v] --;
			if (in[v] == 0){
				s.push(v);
			}
		}
	}
	if (tc < n){
		return 0;
	}
	return 1;
}

bool CriticalPath(){
	if (TopoSort())
	{
		cout << "拓扑序列为：" << endl;
		for(int i = 0; i < n; i++){
			cout << topo[i] << "\t";
		}
		cout << endl;
	}
	else{
		cout << "该图有环， 无法拓扑排序" << endl;
	}
	for(int i = 0; i < n; i++){
		ve[i] = 0;
	}
	for(int j = 0; j < n; j++){
		int u = topo[j];
		for(int i = head[u]; ~i; i = edge[i].next){
			int v = edge[i].to;
			int w = edge[i].w;
			if (ve[v] < (ve[u] + w)){
				ve[v] = ve[u] + w;
			}
		}
	}
	for(int i = 0; i < n; i++){
		vl[i] = ve[n-1];
	}
	for(int j = n-1; j >= 0; j--){
		int u = topo[j];
		for(int i = head[u]; ~i; i = edge[i].next){
			int v = edge[i].to;
			int w = edge[i].w;
			if (vl[u] > (vl[v] - w)){
				vl[u] = vl[v] - w;
			}
		}
	}
	cout << "0: " << endl;
	for(int i = 0; i < n; i++){
		cout << i << " : " << ve[i] << "\t" << vl[i] << endl;
	}
	cout << "1: " << endl;
	for(int u = 0; u < n; u++){
		for(int i = head[u]; ~i; i = edge[i].next){
			int v = edge[i].to;
			int w = edge[i].w;
			e[i] = ve[u];
			l[i] = vl[v] - w;
		}
	}
	for(int i = 0; i < m; i++){
		cout << i << " : " << e[i] << "\t" << l[i] << endl;
	}
	
	cout << "2: " << endl;
	for(int i = 0; i < m; i++){
		if(e[i] == l[i]){
			cout << "<" << edge[i].from << " , " << edge[i].to << ">" << endl;
		}
	}
	return 1;
}

int main(int argc, char** argv) {
#ifdef DEBUG_LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif //DEBUG_LOCAL
	int u, v, w;
	cin >> n >> m;
	memset(head, -1, sizeof(head));
	memset(in, 0, sizeof(in));
	cnt = 0;
	for(int i = 0; i < m; i++){
		cin >> u >> v >> w;
		add(u, v, w);
		in[v]++;
	}
	CriticalPath();
#ifdef DEBUG_LOCAL
	fclose(stdin);
	
	fclose(stdout);
#endif //DEBUG_LOCAL
}