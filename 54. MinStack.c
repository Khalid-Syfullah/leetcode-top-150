#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10000

typedef struct {
    int val;
    int min;
} Entry;

typedef struct {
    Entry data[MAX_SIZE];
    int top;
} MinStack;

void minStackCreate(MinStack *ms) {
    ms->top = 0;
}

void minStackPush(MinStack *ms, int val) {
    int min = (ms->top == 0) ? val : ms->data[ms->top - 1].min;
    if (val < min) min = val;
    ms->data[ms->top].val = val;
    ms->data[ms->top].min = min;
    ms->top++;
}

void minStackPop(MinStack *ms) {
    ms->top--;
}

int minStackTop(MinStack *ms) {
    return ms->data[ms->top - 1].val;
}

int minStackGetMin(MinStack *ms) {
    return ms->data[ms->top - 1].min;
}

int main(void) {
    MinStack ms;
    minStackCreate(&ms);
    minStackPush(&ms, -2);
    minStackPush(&ms, 0);
    minStackPush(&ms, -3);
    printf("%d\n", minStackGetMin(&ms)); /* -3 */
    minStackPop(&ms);
    printf("%d\n", minStackTop(&ms));    /* 0 */
    printf("%d\n", minStackGetMin(&ms)); /* -2 */
    return 0;
}
