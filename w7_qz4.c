// 202112894 이경원 w7_qz4: 블럭탑

#include <stdio.h>

#define MAX_SIZE 100

typedef struct {
    int data[MAX_SIZE];
    int top;
} StackType;

void init_stack(StackType* stack) {
    stack->top = -1;
}

int is_empty(StackType* stack) {
    return (stack->top == -1);
}

int is_full(StackType* stack) {
    return (stack->top == (MAX_SIZE - 1));
}

void push(StackType* stack, int item) {
    if (is_full(stack)) {
        printf("Stack Overflow\n");
        return;
    }
    stack->data[++(stack->top)] = item;
}

int pop(StackType* stack) {
    if (is_empty(stack)) {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack->data[(stack->top)--];
}

int main() {
    int infinity = 987654321;
    int problem_num = 0;
    scanf("%d", &problem_num);

    for (int problem = 0; problem < problem_num; problem++) {
        int query_num = 0;
        scanf("%d", &query_num);
        
        StackType min_stack; 
        StackType max_stack; 
        init_stack(&min_stack);
        init_stack(&max_stack);
        push(&min_stack, infinity);
        push(&max_stack, -infinity);
        
        for (int query = 0; query < query_num; query++) {
            int input1, input2, new_block = 0;
            scanf("%d", &input1);
            switch (input1) {
                case 1:
                    scanf("%d", &input2);
                    new_block = input2;
                    if (min_stack.data[min_stack.top] > new_block)
                        push(&min_stack, new_block);
                    else
                        push(&min_stack, min_stack.data[min_stack.top]);
                    if (max_stack.data[max_stack.top] < new_block)
                        push(&max_stack, new_block);
                    else
                        push(&max_stack, max_stack.data[max_stack.top]);
                    printf("%d %d\n", min_stack.data[min_stack.top], max_stack.data[max_stack.top]);
                    break;
                case 2:
                    if (min_stack.top != -1)
                        pop(&min_stack);
                    if (max_stack.top != -1)
                        pop(&max_stack);
                    break;
            }
        }
    }
    return 0;
}