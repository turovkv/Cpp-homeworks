#ifndef POINT_LIST_H_
#define POINT_LIST_H_

#include "stdint.h"
#include "clist.h"

typedef struct point_node {
    int32_t x;
    int32_t y;
    intrusive_node node;
} point_node;

void remove_point(intrusive_list *list, int32_t x, int32_t y);

void add_point(intrusive_list *list, int32_t x, int32_t y);

void show_all_points(intrusive_list *list);

void remove_all_points(intrusive_list *list);

void print_point(intrusive_node *node, void *data);

void print_point_to_file_txt(intrusive_node *node, void *data);

void print_point_to_file_bin(intrusive_node *node, void *data);

void count_point(intrusive_node *node, void *data);

#endif