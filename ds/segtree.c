#define ST_LEN (1<<19)
#define COMB(x,y) ((x)+(y))
#define IDENT 0
int st[ST_LEN*2];
void init() { FOR(i, 1, 2*ST_LEN) st[i] = IDENT; }
int ql, qr;
int query_aux(int i, int l, int r) {
	if (ql <= l && r <= qr) return st[i];
	if (qr <= l || r <= ql) return IDENT;
	int m = (l+r)/2;
	return COMB(query_aux(i*2,l,m), query_aux(i*2+1,m,r));
}
int query(int l, int r) {
	ql = l; qr = r;
	return query_aux(1, 0, ST_LEN);
}
void update(int i, int x) {
	i += ST_LEN;
	st[i] = x;
	while (i /= 2) st[i] = COMB(st[i*2], st[i*2+1]);
}
