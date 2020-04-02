#include <stddef.h>
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include "clist.h"


struct point {
	int x, y;
	struct intrusive_node node;
};

void add_point(struct intrusive_list *list, int x, int y) {
	struct point *newPoint = malloc(sizeof(struct point));
	newPoint->x = x;
	newPoint->y = y;
	newPoint->node.prev = NULL;
	newPoint->node.next = NULL;
	add_node(list, &newPoint->node);
}

void remove_point(struct intrusive_list *list, int x, int y) { // removes all (x, y) pairs
	for (struct intrusive_node *curNode = list->head; curNode;) {
		struct point *curPoint = container_of(curNode, struct point, node);
		curNode = curNode->next;
		if (curPoint->x == x && curPoint->y == y) {
			remove_node(list, &curPoint->node);
			free(curPoint);
		}
	}
}

void show_all_points(struct intrusive_list *list) {
	for (struct intrusive_node *curNode = list->head; curNode; curNode = curNode->next) {
		struct point *curPoint = container_of(curNode, struct point, node);
		printf("(%d %d) ", curPoint->x, curPoint->y);
	}
	printf("\n");
}

void remove_all_points(struct intrusive_list *list) {
	for (struct intrusive_node *curNode = list->head; curNode;) {
		struct point *curPoint = container_of(curNode, struct point, node);
		curNode = curNode->next;
		remove_node(list, &curPoint->node);
		free(curPoint);
	}
}

void show_length(struct intrusive_list *list) {
	printf("%d\n", list->length);
}

int main() {
    struct intrusive_list l;
    init_list(&l);

    const char addCom[]   = "add";
    const char rmCom[]    = "rm";
    const char printCom[] = "print";
    const char rmaCom[]   = "rma";
    const char lenCom[]   = "len";
    const char exitCom[]  = "exit";
    char curCom[31];

    while (1) {
    	scanf("%30s", curCom);
    	if (!strcmp(curCom, addCom)) {
    		int x, y;
    		scanf("%d %d", &x, &y);
    		add_point(&l, x, y);
    	} else
    	if (!strcmp(curCom, rmCom)) {
    		int x, y;
    		scanf("%d %d", &x, &y);
    		remove_point(&l, x, y);
    	} else
    	if (!strcmp(curCom, printCom)) {
    		show_all_points(&l);
    	} else
    	if (!strcmp(curCom, rmaCom)) {
    		remove_all_points(&l);
    	} else
    	if (!strcmp(curCom, lenCom)) {
    		show_length(&l);	
    	} else
    	if (!strcmp(curCom, exitCom)) {
            break;
    	} else {
    		printf("Unknown command\n");
    	}
    }   
    remove_all_points(&l);
    return 0;
} 
