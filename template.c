#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAXN 200100
typedef long long ll;

int RI() { int x; scanf("%d", &x); return x; }
ll RL() { ll x; scanf("%lld", &x); return x; }
void RS(char* buf) { scanf("%s", buf); }

#define FOR(i,a,b) for(int i = a; i < b; i++)
#define ROF(i,a,b) for(int i = b-1; i >= a; i--)

int absI(int x) { return x < 0 ? -x : x; }

void swapI(int* a, int* b) { int t = *a; *a = *b; *b = t; }

void mergeI(int* l1, int* r1, int* l2, int* r2, int* out) {
	while (l1 < r1 && l2 < r2) {
		if (*l1 < *l2) *out++ = *l1++;
		else           *out++ = *l2++;
	}
	while (l1 < r1) *out++ = *l1++;
	while (l2 < r2) *out++ = *l2++;
}
void sortI_aux(int* l, int *r, int* buf) {
	if (r - l <= 1) return;
	int* m = l + (r-l)/2;
	sortI_aux(l, m, buf);
	sortI_aux(m, r, buf);
	mergeI(l, m, m, r, buf);
	memcpy(l, buf, (r-l)*sizeof(int));
}
void sortI(int* l, int* r) {
	int* buf = calloc(r-l, sizeof(int));
	sortI_aux(l, r, buf);
}

int main() {
	int t = RI();
	while (t--) {
	}
}
