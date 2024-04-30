
struct heap { int* data; int capacity; int size; };

struct heap* heap_create(int capacity) {
	struct heap* result = malloc(sizeof(*result));
	result->data = malloc(capacity * sizeof(result->data[0]));
	result->capacity = capacity;
	result->size = 0;
	return result;
}

void heap_push(struct heap* h, int x) {
	assert(h->size < h->capacity);
	int i = h->size++;
	h->data[i] = x;
	while (i > 0 && h->data[i] > h->data[(i-1)/2]) {
		swapI(&h->data[i], &h->data[(i-1)/2]);
		i = (i-1)/2;
	}
}

int heap_top(struct heap* h) {
	return h->data[0];
}

void heap_pop(struct heap* h) {
	int i = 0;
	h->data[i] = h->data[--h->size];
	while (i*2+2 < h->size) {
		int j = h->data[i*2+1] > h->data[i*2+2] ? i*2+1 : i*2+2;
		if (h->data[j] <= h->data[i]) return;
		swapI(&h->data[j], &h->data[i]);
		i = j;
	}
	int j = i*2+1;
	if (j < h->size && h->data[j] > h->data[i]) {
		swapI(&h->data[j], &h->data[i]);
	}
}
