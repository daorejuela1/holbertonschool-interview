#ifndef H_MAXHEAP
#define H_MAXHEAP
#include <stdlib.h>
#include <stddef.h>
/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct binary_tree_s
{
	int n;
	struct binary_tree_s *parent;
	struct binary_tree_s *left;
	struct binary_tree_s *right;
};
typedef struct binary_tree_s heap_t;
typedef struct binary_tree_s binary_tree_t;

/**
 * struct queue_l - struct to define a linked list
 * @node: actual node value of the linked list
 * @next: next value in the linked list
 */
typedef struct queue_l
{
	struct binary_tree_s *node;
	struct queue_l *next;
} list_t;

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);
void binary_tree_print(const binary_tree_t *);
heap_t *heap_insert(heap_t **root, int value);
void enqueue(list_t **queue, heap_t *new_node);
heap_t *dequeue(list_t **queue);
void swap(heap_t *node_a, heap_t *node_b);
#endif
