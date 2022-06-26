/*

I affirm that I did not give or receive any
unauthorized help on this assignment.
ALL WORK IS ON MY OWN.

Name: Á¶º¸°æ
SID: 2021189038

*/

#ifdef _WIN32
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>
#include <malloc.h>
#define MAX_DATA 200

typedef struct _trees {
	char** line;
	int num;
} trees;

trees* readTxt(char*);
void freeTxt(trees*);





typedef struct _node {
	// Add components as you want //
	/// ex. struct _node *l;

	struct _node* left;
	struct _node* right;
	////////////////////////////////
	int tok;
	struct _node* next;
	int val;
} node;

// TODOS: Fill up 6 functions
node* makeTreeBFS(char*);
void printBFS(node*);
void printPreOrder(node*);
void printInOrder(node*);
void printPostOrder(node*);
void freeTree(node*);




// Add your structs //

typedef struct _queue {
	int front;
	int rear;
	node* element[MAX_DATA];
} queue;



typedef struct _bucket {
	int len;
	struct _node* head;
	struct _node* tail;
} bucket;




//////////////////////




// Add your functions //


queue* q_init();
void q_enqueue(queue* q, node*);
node* q_dequeue(queue* q);
node* makeNode(int val);
void push(bucket* q, int tok);
char pop(bucket* q);
bool q_is_empty(queue* q);
bool q_is_full(queue* q);
bucket* init();
///////////////////////