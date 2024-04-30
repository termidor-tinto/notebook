#include <stdlib.h>

// TREAP customization
#define KEY_TYPE int
#define KEY_CMP(x, y) ((x)<(y))
// #include <string.h>
// #define KEY_TYPE char*
// #define KEY_CMP(x, y) (strcmp((x),(y))<0)
typedef struct treap* Treap;
struct treap { KEY_TYPE key; unsigned priority, size, height; Treap l, r; };
Treap empty() { return NULL; }
int get_size(Treap t) { return !t ? 0 : t->size; }
int get_height(Treap t) { return !t ? 0 : t->height; }
static int max(int x, int y) { return x < y ? y : x; }
static void recompute(Treap t) {
    t->size = get_size(t->l) + get_size(t->r) + 1;
    t->height = max(get_height(t->l), get_height(t->r)) + 1;
}
Treap merge(Treap a, Treap b) { // merge (max a <= min b)
    if (!a || !b) return a ? a : b;
    Treap t;
    if (a->priority < b->priority) a->r = merge(a->r, b), t = a;
    else                           b->l = merge(a, b->l), t = b;
    return recompute(t), t;
}
void split(Treap a, KEY_TYPE key, Treap* l, Treap* r) { // split (<key) (>=key)
    if (!a) return (void)(*l = *r = NULL);
    if (KEY_CMP(a->key, key)) split(a->r, key, &a->r, r), *l = a;
    else                      split(a->l, key, l, &a->l), *r = a;
    recompute(a);
}
static Treap singleton(KEY_TYPE key) {
    Treap result = malloc(sizeof(*result));
    *result = (struct treap){ .key = key, .priority = rand(), .size = 1, .height = 1};
    return result;
}
Treap insert(Treap a, KEY_TYPE x) {
    Treap l, r; split(a, x, &l, &r);
    return merge(merge(l, singleton(x)), r);
}
