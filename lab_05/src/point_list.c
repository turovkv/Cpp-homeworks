#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "stdint.h"
#include "point_list.h"

#define container_of(ptr, type, member) (type*)((char*)(ptr) - offsetof(type, member))

point_node *get_point(intrusive_node *node) {
    return container_of(node, point_node, node);
}

int32_t match_point(intrusive_node *node, int32_t x, int32_t y) {
    point_node *pnode = get_point(node);
    return pnode->x == x && pnode->y == y;
}

void delete_point(intrusive_list *list, intrusive_node *node) {
    remove_node(list, node);
    free(get_point(node));
}




void remove_point(intrusive_list *list, int32_t x, int32_t y) {
    intrusive_node *head = &list->head;
    intrusive_node *node = head->next;

    while (node != head) {
        intrusive_node *next = node->next;

        if (match_point(node, x, y))
            delete_point(list, node);

        node = next;
    }
}

void add_point(intrusive_list *list, int32_t x, int32_t y) {
    point_node *pnode = malloc(sizeof(point_node));
    pnode->x = x;
    pnode->y = y;

    add_node(list, &pnode->node);
}

void remove_all_points(intrusive_list *list) {
    while (list->head.next != &list->head)
        delete_point(list, list->head.next);
}

void print_point(intrusive_node *node, void *data) {
    char *format = data;
    point_node *pnode = get_point(node);
    printf(format, pnode->x, pnode->y);
}

void print_point_to_file_txt(intrusive_node *node, void *data) {
    FILE *fout = data;
    point_node *pnode = get_point(node);
    fprintf(fout, "%d %d\n", pnode->x, pnode->y);
}

unsigned char byte_of_int(int32_t a, int32_t byteNumber) {
    return (a >> (8 * byteNumber)) & ((1 << 8) - 1);
}

void print_point_to_file_bin(intrusive_node *node, void *data) {
    FILE *fout = data;
    point_node *pnode = get_point(node);
    unsigned char buffer[6];
    int32_t a = pnode->x, b = pnode->y;
    for (int32_t i = 0; i < 3; i++) {
        buffer[i] = byte_of_int(a, i); 
    }
    for (int32_t i = 0; i < 3; i++) {
        buffer[3 + i] = byte_of_int(b, i); 
    }
    fwrite(buffer, 1, 6, fout);
}

void count_point(intrusive_node *node, void *data) {
    (void)node;
    int32_t *tmp = data;
    *tmp = *tmp + 1;
} 