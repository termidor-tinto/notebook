
#define MAXN 200000
#define MAXM 300000

struct edge_data {
	int next;
	int to;
};

#define EDGES(g, u, e) for (int e = (g)->head[u]; e != -1; e = (g)->edges[e].next)
#define NEIGHBORS(g, u, v) EDGES(g, u, e) for (int v = (g)->edges[e].to, flag = 1; flag; flag = 0)

struct graph {
	int head[MAXN];
	struct edge_data edges[MAXM];
	int edge_count;
};

void init_graph(struct graph* g, int n) {
	while(n--) g->head[n] = -1;
	g->edge_count = 0;
}

void add_edge(struct graph* g, int u, int v) {
	g->edges[g->edge_count].to = v;
	g->edges[g->edge_count].next = g->head[u];
	g->head[u] = g->edge_count;
	g->edge_count++;
}

struct graph g;


int visited[MAXN];
void dfs(int u) {
	visited[u] = 1;
	NEIGHBORS(&g, u, v) {
		if (!visited[v]) dfs(v);
	}
}

void bfs(int u) {
	static int qq[2*MAXN];
	int ql = 0, qr = 0;
	qq[qr++] = u;
	pushed[u] = 1;
	while (ql < qr) {
		int u = qq[ql++];
		NEIGHBORS(&g, u, v) {
			if (!pushed[v]) {
				qq[qr++] = v;
				pushed[v] = 1;
			}
		}
	}
}
