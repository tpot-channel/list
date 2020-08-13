#include <stdio.h>
#include <stdlib.h>
#include "../include/list.h"


void delete_list_all(LIST* p)
{
	for (LIST* n = p; n != NULL; ) {
		LIST *m = n->next;
		free(n);
		n = m;
	}
}

LIST* list_add(LIST* p, int val)
{
	LIST* n = malloc(sizeof(LIST));
	n->data = val;
	n->next = p;

	return n;
}

LIST* list_delete(LIST* p)
{
	if (p == NULL) return NULL;

	LIST* n = p->next;
	free(p);

	return n;
}

void list_delete_next(LIST* p)
{
	if (p == NULL) return;

	LIST* n = p->next;
	p->next = (n == NULL) ? NULL : n->next;
	free(n);
}

int list_get_data(const LIST* p)
{
	if (p == NULL) return 0;

	return p->data;
}

int list_length(const LIST* p)
{
	int count = 0;

	for (; p != NULL; p = p->next) {
		count++;
	}

	return count;
}

