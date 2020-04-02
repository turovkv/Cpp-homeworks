#include <stddef.h>
#include "clist.h"

void init_list(struct intrusive_list *list) {
	list->head = NULL;
	list->length = 0;
}

void add_node(struct intrusive_list *list, struct intrusive_node *node) {
	node->prev = NULL;
	node->next = list->head;
	
	if (list->length)
		list->head->prev = node;
	list->head = node;

	list->length++;
}
	
void remove_node(struct intrusive_list *list, struct intrusive_node *node) {
	if (node->prev)
		node->prev->next = node->next;
	if (node->next)
		node->next->prev = node->prev;

	if (list->head == node)
		list->head = node->next;

	list->length--;
}

int get_length(struct intrusive_list *list) {
	return list->length;
}
	