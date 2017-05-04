#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <unistd.h>

#define true 0
#define false 1

typedef unsigned int bool;

/* C singly-linked-list*/
struct node {
    int item;
    struct node *next;
};
struct node *HEAD;
int LIST_LENGTH;

struct node *list_return_last(struct node *head)
{
    if (!head) 
       return NULL;

    while (head->next != NULL) {
      head = head->next;
    }
    
    return head;
}

void list_traverse(struct node *head)
{
    printf("HEAD");
    while (head != NULL) {
        printf ("-->[%p]:%d",head,head->item);
        head = head->next;
    }
    printf("-->NULL\n");
}

bool list_insert_node(struct node **head, struct node **new_node)
{
	if (!(*head)) {
		*head = *new_node;
		return true;
	}

    struct node *last = list_return_last(*head);
	if (!last)
		return false;

    last->next = *new_node;
    (*new_node)->next = NULL;

    return true;
}

bool list_remove_item(struct node **head, int item)
{
	struct node *del_node = NULL;

    if (!(*head))
        return true;
	
	if ((*head)->item == item) {
        del_node = (*head);
		(*head) =  (*head)->next;
        printf("Removed %p:%d \n", del_node, del_node->item);
		free(del_node);
		LIST_LENGTH--;
		return true;
	} 

    struct node *curr = NULL;
    curr = *head;
    
    while (curr != NULL) {
        if (curr->next && curr->next->item == item) {
			del_node = curr->next;
            curr->next = curr->next->next;
            printf("Removed %p:%d \n", del_node, del_node->item);
			free(del_node);
	        LIST_LENGTH--;
            break;
		}
        curr = curr->next;
    }

	return true;
}


/* C stacks */
unsigned int *stack, stack_size;
int top;

unsigned int stack_pop(unsigned int *val)
{
	if( top < 0 ) {
		*val = 0;
		return false;
	} 
				
    *val = stack[top--];
	return true;
}

bool stack_push(unsigned int val)
{
    if(top != stack_size) {
		stack[++top] = val;
		return true;
    } 

	return false;
}

bool stack_is_empty()
{
	if (top < 0)
		return true;
	
	return false;
}

/* C queue */
unsigned int *queue;
int head, tail;
int queue_size;


bool queue_enqueue(unsigned int val)
{
    if (tail < (queue_size-1)) {
        queue[++tail] = val;
        return true;
    }

    return false;
}

bool queue_dequeue(unsigned int *val)
{
    if(head > tail) {
        printf("Queue empty \n");
        *val = 0;
        head = 0;
        tail = -1;
        return false;
    }

    *val = queue[head++];
    return true;
}

bool queue_is_empty()
{
    return (head>tail);
}


/* 
 * BST 
               5
              /  \
            /     \
           3       7
          / \     / \
         2   4   6   8
        /             \
       1               9 
       |
       0
*/
struct tree {
    int val;
    struct tree *left;
    struct tree *right;
};

struct tree *TREE_HEAD;
int nodes[] = {5,3,4,2,1,0,7,6,8,9};

void bst_preorder(struct tree *root)
{
    if(!root)
        return;

    printf("%d ", root->val);
    bst_preorder(root->left);
    bst_preorder(root->right);
}

void bst_inorder(struct tree *root)
{
    if(!root)
        return;

    bst_inorder(root->left);
    printf("%d ", root->val);
    bst_inorder(root->right);
}

void bst_postorder(struct tree *root)
{
    if(!root)
        return;

    bst_postorder(root->left);
    bst_postorder(root->right);
    printf("%d ", root->val);
}


struct tree *inorder_successor(struct tree *root)
{
    struct tree *node = root;
    while(node->left != NULL) 
        node = node->left;

    return node;
}

struct tree *bst_insert(struct tree *root, int val, int level)
{
    if(!root) {
        struct tree *node = malloc(sizeof(struct tree));
        node->left = node->right = NULL;
        node->val = val;
        return node;
    }
    if(val < root->val)
        root->left = bst_insert(root->left, val, level++);
    else if (val > root->val)
        root->right = bst_insert(root->right, val, level++);

    return root;
}

struct tree *bst_delete(struct tree *node, int val)
{
    //3. node == null
    if(!node)
        return node;

    //1. key < node->val
    if (val < node->val)  {
        node->left = bst_delete(node->left,val);
    } //2. key > node->val
    else if (val > node->val) {
        node->right = bst_delete(node->right,val);
    } //4. node->val == key and node has 
    //either left or right
    else {
        if (!node->left) {
            struct tree *temp = node->right;
            free(node);
            return temp;
        } else if (!node->right) {
            struct tree *temp = node->left;
            free(node);
            return temp;
        } else {
            struct tree *temp = inorder_successor(node->right);
            node->val = temp->val;
            node->right = bst_delete(node->right, temp->val);
        }
    }

    return node;
}

void bst_operations()
{
   TREE_HEAD = NULL; 

   TREE_HEAD = bst_insert(TREE_HEAD, nodes[0], 0);
   bst_insert(TREE_HEAD, nodes[1], 0);
   bst_insert(TREE_HEAD, nodes[2], 0);
   bst_insert(TREE_HEAD, nodes[3], 0);
   bst_insert(TREE_HEAD, nodes[4], 0);
   bst_insert(TREE_HEAD, nodes[5], 0);
   bst_insert(TREE_HEAD, nodes[6], 0);
   bst_insert(TREE_HEAD, nodes[7], 0);
   bst_insert(TREE_HEAD, nodes[8], 0);
   bst_insert(TREE_HEAD, nodes[9], 0);
       
   printf("%25s","Preorder: ");
   bst_preorder(TREE_HEAD);
   printf("\n");
   printf("%25s","Inorder[Sorted order]: ");
   bst_inorder(TREE_HEAD);
   printf("\n");
   printf("%25s","Postorder: ");
   bst_postorder(TREE_HEAD);
   printf("\n");

   printf("Succesor %d:%d\n", nodes[0], inorder_successor(TREE_HEAD->right)->val);

   bst_delete(TREE_HEAD, 0);
   printf("Del 0: %25s","Inorder[Sorted order]: ");
   bst_inorder(TREE_HEAD);
   printf("\n");

   bst_delete(TREE_HEAD, 2);
   printf("Del 2: %25s","Inorder[Sorted order]: ");
   bst_inorder(TREE_HEAD);
   printf("\n");

   bst_delete(TREE_HEAD, 7);
   printf("Del 7: %25s","Inorder[Sorted order]: ");
   bst_inorder(TREE_HEAD);
   printf("\n");

   bst_delete(TREE_HEAD, 5);
   printf("Del 5: %25s","Inorder[Sorted order]: ");
   bst_inorder(TREE_HEAD);
   printf("\n");
   return;
}

int main(int argc, char *argv[])
{
	LIST_LENGTH = 0;
	int random = 0;
    int iter = 0;
	time_t t;
    int opt;
	
	srand((unsigned) time(&t));

	while ((opt = getopt(argc, argv, "lsqt")) != -1) {
		switch (opt) {
		case 'l':
			for (iter=0; iter<10; iter++) {
					struct node *new_node = malloc(sizeof(struct node));
					if(!new_node) {
						printf("Malloc failure\n");
						exit(1);
					}
					printf("Insert item %d \n", iter);
					new_node->item = iter;
					new_node->next = NULL;
					list_insert_node(&HEAD, &new_node); 
				}
				list_traverse(HEAD);
				printf("%p[HEAD] --->  %p[NODE]\n", &HEAD, HEAD);
				LIST_LENGTH = iter;

				for (iter=0; iter<10; iter++) {
					random = rand() % 10;	
					//printf("Remove element %d \n", random);
					list_remove_item(&HEAD, random);
					list_traverse(HEAD);
					printf("\n\n");
				}
		break;

		case 's':
			top = -1;
			stack_size = 10;
			stack = malloc(sizeof(unsigned int) * stack_size);
			if(!stack)
				exit(1);

			for (iter=0; iter<10; iter++) {
				random = rand() % 100;
				printf("Push %d on to stack rc:%d @ %d\n", 
					random, stack_push(random), top);
			}

			for (iter=0; iter<10; iter++) {
				unsigned int val = 0;
				unsigned int rc = stack_pop(&val);
				printf("Popped %d from stack @ %d rc:%d\n", val, top+1, rc);
			}

			printf("Is stack_empty %d \n", stack_is_empty());
		break;

		case 'q':
            tail = -1;
            head = 0;
            queue_size = 10;
            queue = malloc(sizeof(unsigned int) * queue_size);
            if(!queue)
                exit(1);

        	for (iter=0; iter<10; iter++) {
				random = rand() % 100;
				printf("Enqueue %3d on to queue rc:%d head:%d tail:%d queue_size:%d\n", 
					random, queue_enqueue(random), head, tail, queue_size);
			}
            printf("Queue params head:%d tail:%d\n", head, tail);

			for (iter=0; iter<10; iter++) {
				unsigned int val = 0;
				unsigned int rc = queue_dequeue(&val);
				printf("Dequeued %3d from queue head:%d tail:%d rc:%d\n", 
                        val, head, tail, rc);
			}
			printf("Is queue_empty %d \n", queue_is_empty());
        break;

        case 't':
            bst_operations();
        break;

		default:
			exit(0);
		}
	}

		
    return 0;
}
