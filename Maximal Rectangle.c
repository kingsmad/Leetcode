/*************************************************************************
    > File Name: Maximal Rectangle.c
    > Author: Archer Liu
    > Mail: maple.km2041@me.com 
    > Created Time: Thu Mar 26 14:16:28 2015
 ************************************************************************/

#include<stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>

/* Assume num has 0 end*/
int maximalArea(int* num, int len) {
    int stack[len];
    int sp = 0;
    memset(stack, 0, sizeof(stack));

    int ans = 0;
    for(int i=0; i<len; ++i) {
        if (sp ==0 || num[i] >= num[stack[sp-1]]) {
            stack[sp++] = i;
        } else {
            while(sp > 0 && num[stack[sp-1]] > num[i]) {
                int p = stack[sp-1];
                --sp;
                int start = sp ? stack[sp-1]+1 : 0;
                int tmp = num[p] * (i - start); 
                ans = (tmp > ans) ? tmp : ans;
            }
            stack[sp++] = i;
        }
    }

    return ans;
}

int maximalRectangle(char** matrix, int numRows, int numColumns) {
    if (!matrix) {
        return 0;
    }
    int cnt[numColumns+1];
    memset(cnt, 0, sizeof(cnt));
    int ans = INT_MIN;

    for(int i=0; i<numRows; ++i) {
        for(int j=0; j<numColumns; ++j) {
            if(matrix[i][j] == '0')
                cnt[j] = 0;
            else {
                cnt[j] += 1; 
            }
        }
        int tmp = maximalArea(cnt, numColumns+1);
        if (tmp > ans)
            ans = tmp;
    }

    return ans;
}


int main(int argc, char** argv) {
    int row, col;
    scanf("%d%d", &row, &col);
    char** matrix = (char**) malloc(sizeof(char*)*row);
    for(int i=0; i<row; ++i) {
        matrix[i] = (char*)malloc(sizeof(char)*col);    
    }

    for(int i=0; i<row; ++i) {
        for(int j=0; j<col; ++j) {
            scanf("\n %c", &matrix[i][j]);
        }
    }

    printf("\nHere is the Matrix: ");

    for(int i=0; i<row; ++i) {
        for(int j=0; j<col; ++j) {
            printf("%c ", matrix[i][j]);
        }
    }
   int ans =  maximalRectangle(matrix, row, col);

   printf("Answer is %d", ans);
}
