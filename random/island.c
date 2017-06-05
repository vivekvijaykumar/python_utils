/*
 * Map[row][col] = {
 *                    { 1, 0, 0, 1, 1 },
 *                    { 0, 0, 0, 1, 0 },
 *                    { 1, 1, 0, 0, 0 },
 *                    { 1, 1, 1, 0, 1 },
 *                    { 0, 0, 0, 1, 0 },
 *                 };
 *
 * 1) Goal is to find out all the islands in the map
 * 2) island is connected ones or a single one.
 * 3) Zero's represent ocean.
 *
 * 4) navigate to every point row,col and need to 
 * check if its a '1' , and if so we should mark
 * it as visited and find out the connected ones
 * to this row,col and keep repeating this step
 * till we find ocean in each of the direction
 * we want to go.
 */
#include <stdio.h>
#include <stdlib.h>

#define ROW 5
#define COL 5

int directions[] = {-1,-1, -1,0, -1,1, 0,-1, 0,1, 1,-1, 1,0, 1,1};

unsigned int valid_path(unsigned int row, unsigned int col, 
        unsigned int map[][COL], unsigned int visit[][COL])
{
    return ((row >=0 && row < ROW) && 
            (col >=0 && col < COL) &&
            (map[row][col] == 1) && 
            (visit[row][col] == 0));
}


void navigate_island(unsigned int row, unsigned int col, 
        unsigned int map[][COL], unsigned int visit[][COL])
{
    //1. navigate has to move through all the directions
    //8 directions in total
    //(row-1, col-1) , (row-1, col), (row-1,col+1)
    //(row,col-1) , (row,col), (row,col+1)
    //(row+1, col-1) , (row+1, col) , (row+1, col+1)

    visit[row][col] = 1;
    for(int i=0; i<(8)*2; i+=2) {
        if(valid_path(row+directions[i], col+directions[i+1], map, visit))
            navigate_island(row+directions[i], col+directions[i+1], map, visit);
    }

    return;
}


unsigned int count_island(unsigned int map[][COL]) 
{
    unsigned int visit[ROW][COL] = {{0}};
    unsigned int count = 0, i, j;
    i=j=0;

    for(i=0; i<ROW; i++) {
        for(j=0; j<COL; j++) {
            if(valid_path(i,j,map, visit)) {
                navigate_island(i, j, map, visit);
                ++count;
                printf("Island %d starts @ %d,%d\n", count, i, j);
            }
        }
    }

    return count;
}


int main() 
{
#if 1
    unsigned int map[ROW][COL] = {
                     { 1, 0, 0, 1, 1 },
                     { 0, 0, 0, 1, 0 },
                     { 1, 1, 0, 0, 0 },
                     { 1, 1, 1, 0, 1 },
                     { 0, 0, 0, 1, 0 },
                  };
#else
    unsigned int map[ROW][COL] = {
     					{1, 1, 0, 0, 0},
                        {0, 1, 0, 0, 1},
                        {1, 0, 0, 1, 1},
                        {0, 0, 0, 0, 0},
                        {1, 0, 1, 0, 1},
	};
#endif
    printf("Total Islands:%d \n", count_island(map));

    return 0;
}
