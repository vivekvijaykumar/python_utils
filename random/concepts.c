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

struct node *list_reverse(struct node *head, struct node **HEAD)
{
    if((head)->next) {
        struct node *tmp = list_reverse((head)->next, HEAD);
        tmp->next = head;
        (head)->next = NULL;
        printf("head %p[%d] --> next %p[%d] \n", 
                tmp, tmp->item, head, head->item);
    } else {
        *HEAD = head;
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
      3    7
     / \   / \
    2   4 6   8
   /           \
  1             9 
  |
  0
*/
struct tree {
    int val;
    bool visit;
    struct tree *left;
    struct tree *right;
};

struct tree *TREE_HEAD;
int nodes[] = {5,3,4,2,1,0,7,6,8,9};
struct tree *graph_list[sizeof(nodes)/sizeof(int)];

bool graph_spush(struct tree *node)
{
    if(top >= stack_size) {
        return false;
    }

    graph_list[++top] = node;
    return true;
}

struct tree *graph_spop()
{
    if(top < 0)
        return NULL;
    struct tree *tmp = graph_list[top];
    graph_list[top] = NULL;
    top--;
    return tmp;
}

bool graph_qenqueue(struct tree *node)
{
    if(tail < (queue_size-1)) {
       graph_list[++tail] = node;
       return true;
    }
    return false;
}

bool graph_qempty()
{
    return (head>tail || tail == -1);
}

struct tree *graph_qdequeue()
{
    if(head > tail) {
        printf("Graph queue empty \n");        
    head = 0;
    tail = -1;
    return NULL;
    }

    return graph_list[head++]; 
}

void bst_preorder(struct tree *root)
{
    if(!root)
        return;

    printf("%d ", root->val);
    bst_preorder(root->left);
    bst_preorder(root->right);
}

int kth_smallest;
void bst_inorder_kth(struct tree *root, int k)
{
    if(!root)
        return;

    bst_inorder_kth(root->left, k);
    kth_smallest++;
    //printf("[k:%d c:%d v:%d]\n", k, kth_smallest, root->val);
    if(kth_smallest == k) {
        printf("%d ", root->val);
        return;
    } else if(kth_smallest>k) {
        return;
    }
    bst_inorder_kth(root->right, k);
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
    node->visit = 0;
        return node;
    }
    if(val < root->val)
        root->left = bst_insert(root->left, val, level++);
    else if (val > root->val)
        root->right = bst_insert(root->right, val, level++);

    return root;
}

void bst_clear_visits(struct tree *root) 
{
    if(!root)
        return;
    root->visit=0;
    bst_clear_visits(root->left);
    bst_clear_visits(root->right);
}

void bst_bfs(struct tree *root)
{
    graph_qenqueue(root);
    while(!graph_qempty()) {
        struct tree *node = graph_qdequeue();    
        node->visit = 1;
        printf("%d ", node->val);

        //Enqueue all nodes connected to me.
        if(node->left && !node->left->visit)
            graph_qenqueue(node->left);
        if(node->right && !node->right->visit)
            graph_qenqueue(node->right);
    }
    return;
}

void bst_dfs()
{
    //1) process node
    //2) mark as visited
    //3) push children of node if not visited and 
    //repeat 1 to 3 for each child. 

    struct tree *root = graph_spop();
    printf("%d ", root->val);
    root->visit = true;

    if(root->left && !root->left->visit) {
        graph_spush(root->left);
        bst_dfs();
    }

    if(root->right && !root->right->visit) {
        graph_spush(root->right);
        bst_dfs();
    }

    return;
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
    tail = -1, head = kth_smallest = 0;
    queue_size = sizeof(nodes)/sizeof(int);
    stack_size = sizeof(nodes)/sizeof(int);
    top = 0;

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
    int random = (rand()%10+1);
    printf("K[%d]th : ", random);
    bst_inorder_kth(TREE_HEAD, random);
    printf("\n");
    printf("%25s","Postorder: ");
    bst_postorder(TREE_HEAD);
    printf("\n");

    bst_clear_visits(TREE_HEAD);
    printf("%25s","BFS: ");
    bst_bfs(TREE_HEAD);
    printf("\n%25s","DFS: ");
    bst_clear_visits(TREE_HEAD);
    graph_spush(TREE_HEAD);
    bst_dfs();
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


/* arrays - sort, search*/
unsigned int array[]={38, 27, 43, 3, 9, 82, 10, 89, 21, 14, 53};

void merge(unsigned int array[], int l, int m, int r)
{
    //1a) create 2 different subarrays for left and right 
    //1b) compare items in the 2 subarrays 
    //2) copy them to the appropriate positions in the array
    //3) and return
    int i,j,n1,n2;
    i=j=0;
    n1 = m-l+1;
    n2 = r-m;
    
    unsigned int a1[n1];
    unsigned int a2[n2];

    for(i=0;i<n1; i++)
        a1[i] = array[l+i];
    for(i=0;i<n2; i++)
        a2[i] = array[m+1+i];

    i=j=0;
    while(i<n1 && j<n2) {
        if(a1[i] < a2[j]) {
            array[l++] = a1[i];
            i++;
        } else if(a1[i] > a2[j]) {
            array[l++] = a2[j];
            j++;
        } else {
            array[l++] = a1[i];
            i++,j++;
        }
    }

    while(i<n1)
        array[l++] = a1[i++];
    while(j<n2)
        array[l++] = a2[j++];

    return;
}

void merge_sort(unsigned int array[], int l, int r)
{
    if(l<r) {

        int m = l+(r-l)/2;

        merge_sort(array, l, m);

        merge_sort(array, m+1, r);

        merge(array, l,m,r);
    }
}

unsigned int partition(unsigned int array[], int l, int r)
{
    unsigned int pivot = array[r];

    int i=l-1, j=l, tmp=0;
    while(j<=(r-1)) {
        if(array[j] <= pivot) {
            i++;
            tmp = array[j];
            array[j] = array[i];
            array[i] = tmp;
        }
        j++;
    }

    tmp = array[i+1];
    array[i+1] = pivot;
    array[r] = tmp;

    return (i+1);
}

void quick_sort(unsigned int array[], int l, int r)
{
    if(l < r) {
        int pi = partition(array,l,r);
        quick_sort(array, l, pi-1);
        quick_sort(array, pi+1, r);
    }
}


int binary_search(unsigned int array[], int s, int e, unsigned int val)
{
    if( s <= e) {
        int m  = (s + e)/2;
        if(val < array[m])
            return binary_search(array, s, m, val);
        else if (val > array[m])
            return binary_search(array, m+1, e, val);
        else 
            return m;
    } else {
        return -1;
    }
}

void print_array(unsigned int array[], int size)
{
    int i=0;
    while(i<size) {
         printf("%d ", array[i++]);
    } 
    printf("\n");
}

int main(int argc, char *argv[])
{
    extern char *optarg;
    LIST_LENGTH = 0;
    int random = 0;
    int iter = 0;
    time_t t;
    int opt;
    int i=0;
    
    srand((unsigned) time(&t));

    while ((opt = getopt(argc, argv, "lsqta:p")) != -1) {
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
                printf("***************************************************************************************************************************************\n");
                list_reverse(HEAD, &HEAD);
                list_traverse(HEAD);
                printf("***************************************************************************************************************************************\n");
                printf("\n\n");

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
        
        case 'a':
            i=0;
            if(optarg[0] == 'm') {
                printf("%20s","Original: ");
                print_array(array, sizeof(array)/sizeof(unsigned int));
                merge_sort(array, 0, sizeof(array)/sizeof(unsigned int)-1);
                printf("%20s","Merge-Sorted: ");
                print_array(array,sizeof(array)/sizeof(unsigned int));
            } else if (optarg[0] == 'q') {
                printf("%20s","Original: ");
                print_array(array,sizeof(array)/sizeof(unsigned int));
                quick_sort(array, 0, (sizeof(array)/sizeof(unsigned int)-1));
                printf("%20s","Quick-Sorted: ");
                print_array(array,sizeof(array)/sizeof(unsigned int));
            } else if(optarg[0] == 'b') {
                random = rand() % sizeof(array)/sizeof(unsigned int);
                merge_sort(array, 0, sizeof(array)/sizeof(unsigned int)-1);
                print_array(array,sizeof(array)/sizeof(unsigned int));
                int rc = binary_search(array, 0, 
                        sizeof(array)/sizeof(unsigned int)-1, array[random]);
                printf("Item [%d] %s @ %d\n", array[random], 
                        (rc == -1) ? "not found." : " found", rc);
            }
        break;

        case 'p':
            stack_size = 10;
            stack = malloc(sizeof(unsigned int) * stack_size);
#if 0
            char str[]="(()(";
            char *ptr = &str[0];
            for(i=0; i<strlen(str); i++) {
                stack_push((unsigned int)(*ptr);
            }
#endif
        break;

        default:
        exit(0);
        }
    }

    return 0;
}

