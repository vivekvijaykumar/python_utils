/*
 * 1) list of size N = heap[N+1]
 * 2) input is a list of random numbers 
 * 3) indexes in the heap - 
 *    1) i is the curret index which is rooted and has a subtree
 *    2) 2*i is the left child of its parent at i
 *    3) 2*i +1 is the right child of its parent at i
 *    4) its a complete binary tree at every level
 *    5) position is the current level where a new number will be 
 *    inserted before performing bubble up operation
 * 4) operations - 
 *    1) insert - insert at index indicated by position
 *      1a) bubble_up - move the new number to its correct position
 *    in the heap satisfying the heap (min,max) criteria
 *    2) remove - remove the head number in O(1) and swap the number
 *    pointed at position with the first index.
 *      2a) sink_down - move the swapped number downwards till its 
 *      in the right position.
 * 
 */
#include <time.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define N 10
int heap[N+1] = {0};
int position = 0;

#define SWAP(_x, _y) \
    int temp = heap[_x]; \
    heap[_x] = heap[_y]; \
    heap[_y] = temp;

void print_heap(int i)
{
    printf("[%2d] --- [",i); 
    for(int i=0; i<11; i++)
        printf("%2d ", heap[i]);
    printf("]\n");
}

//1,2,3
int min3(int _x,int _y,int _z) 
{
    //left child is null
    //compare with right child
    if(heap[_y] == -1) {
            if(heap[_x] > heap[_z] && heap[_x] != -1 && heap[_z] != -1) {
            SWAP(_x, _z);
            return _z;
        }
    }

    //right child is null
    //compare with left child
    else if(heap[_z] == -1) {
        if(heap[_x] > heap[_y] && heap[_x] != -1 && heap[_y] != -1){
            SWAP(_x, _y); 
            return _y;
        } 
    }

    //parent is not null and either child not null
    else if(heap[_x] != -1) { 
        if(heap[_y] < heap[_z] && heap[_y] < heap[_x]) {
        SWAP(_x, _y); 
        return _y;
        } 
        else if(heap[_z] < heap[_y] && heap[_z] < heap[_x]) {
            SWAP(_x, _z);
            return _z;
        }
    }
    
    return _x;
}
        
void bubble_up(int parent, int num, int mypos)
{
    if(heap[parent] != -1 && heap[parent] > num) {
        SWAP(parent, mypos); 
        bubble_up(parent/2, num, parent);
    } 
    return;
}


void heap_insert(int num)
{
    if(position > (N))
        return;

    int parent = position/2; 
    int mypos = position;

    //1) insert the number @ position
    heap[position] = num;        
    if(2*position <= N && (2*position+1) <= N) {
        heap[2*position] = -1;
        heap[2*position + 1] = -1;
    }
    position++;

    //2) bubble up the num
    bubble_up(parent, num, mypos);
}

void sink_down(int mypos)
{
    //1.check my position with either of my child positions
    int left = 2*mypos;
    int right = 2*mypos +1;
    if(left > N)
        left = 0;
    if(right > N)
        right = 0;

    int newpos = min3(mypos, left, right);
    if(newpos != mypos) {
        sink_down(newpos);
    }

    return;
}

int remove_top()
{
    int rc = -1;
    if(position > 0) {
        rc = heap[1];
        position--;
        heap[1] = heap[position];
        heap[position] = -1;
        sink_down(1);
    }

    return rc;
}

int remove_kth(int num) 
{
    int rc = -1;
    for(int i=0; i<num; i++)
        rc = remove_top();

    return rc;
}


int get_top()
{
    if(position > 0)
        return heap[1];

    return -1;
}

int main()
{
    int input[] = { 4, 7, 2, 5, 1, 0, 9, 10, 8, 6 };
    heap[0] = -1;
    position = 1;

    for(int i=0; i<10; i++) {
        heap_insert(input[i]);
        print_heap(i);
    }
#if 0 
    printf("--------------------------%d------------------------------- \n", position);
    for(int i=0; i<10; i++) {
        printf("%2d -- ", remove_top());
        print_heap(i);
    }
#endif
    time_t t;
    srand((unsigned) &t);
    int random = rand()%10;
    printf("K[%2d]th smallest is %d \n", random, remove_kth(random));
}
