#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10   // Maximum number of elements in the stack

// ---------------------- STACK STRUCTURE ----------------------
struct Stack {
    int data[MAX_SIZE];  // internal array to store elements
    int top;             // index of the top element ( -1 means EMPTY )
};

// ---------------------- FUNCTION PROTOTYPES ------------------
void initStack(struct Stack *s);
int  isEmpty(struct Stack *s);
int  isFull(struct Stack *s);
void push(struct Stack *s, int value);
int  pop(struct Stack *s);
int  peek(struct Stack *s);
void displayStack(struct Stack *s);
void displayInternal(struct Stack *s);
void pauseAndClear();

// ----------------------------- MAIN --------------------------
int main() {
    struct Stack s;
    int choice, value, popped;

    initStack(&s);

    while (1) {
        printf("\n================ STACK SIMULATION (ARRAY) ================\n");
        printf("1. Push (Insert element)\n");
        printf("2. Pop  (Remove element)\n");
        printf("3. Peek (Show top element)\n");
        printf("4. Display Stack (Top to Bottom)\n");
        printf("5. Show Internal Array & Top Index\n");
        printf("6. Exit\n");
        printf("==========================================================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("\nEnter value to PUSH: ");
            scanf("%d", &value);
            push(&s, value);
            pauseAndClear();
            break;

        case 2:
            popped = pop(&s);
            if (popped != -1) {
                printf("\n[POP] Removed element: %d\n", popped);
            }
            pauseAndClear();
            break;

        case 3:
            value = peek(&s);
            if (value != -1) {
                printf("\n[PEEK] Top element is: %d\n", value);
            }
            pauseAndClear();
            break;

        case 4:
            displayStack(&s);
            pauseAndClear();
            break;

        case 5:
            displayInternal(&s);
            pauseAndClear();
            break;

        case 6:
            printf("\nExiting... Goodbye!\n");
            return 0;

        default:
            printf("\nInvalid choice! Please try again.\n");
            pauseAndClear();
        }
    }

    return 0;
}

// ---------------------- FUNCTION DEFINITIONS -----------------

// Initialize the stack
void initStack(struct Stack *s) {
    s->top = -1;   // Empty stack
}

// Check if stack is empty
int isEmpty(struct Stack *s) {
    return (s->top == -1);
}

// Check if stack is full
int isFull(struct Stack *s) {
    return (s->top == MAX_SIZE - 1);
}

// Push operation with simulation messages
void push(struct Stack *s, int value) {
    printf("\n--- PUSH OPERATION ---\n");

    // Step 1: Check if stack is full
    if (isFull(s)) {
        printf("Step 1: top = %d, MAX_SIZE = %d\n", s->top, MAX_SIZE);
        printf("Result : Stack Overflow! Cannot insert %d.\n", value);
        return;
    }

    printf("Step 1: Check Overflow -> Not full (top = %d)\n", s->top);

    // Step 2: Increment top
    s->top++;
    printf("Step 2: Increment top -> top = %d\n", s->top);

    // Step 3: Insert element at data[top]
    s->data[s->top] = value;
    printf("Step 3: Insert data[%d] = %d\n", s->top, value);

    // Step 4: Show internal state
    displayInternal(s);
}

// Pop operation with simulation messages
int pop(struct Stack *s) {
    int value;

    printf("\n--- POP OPERATION ---\n");

    // Step 1: Check if stack is empty
    if (isEmpty(s)) {
        printf("Step 1: top = %d\n", s->top);
        printf("Result : Stack Underflow! Nothing to remove.\n");
        return -1;
    }

    printf("Step 1: Check Underflow -> Not empty (top = %d)\n", s->top);

    // Step 2: Take the top element
    value = s->data[s->top];
    printf("Step 2: Read data[%d] = %d (this will be removed)\n", s->top, value);

    // Step 3: Decrement top
    s->top--;
    printf("Step 3: Decrement top -> top = %d\n", s->top);

    // Step 4: Show internal state
    displayInternal(s);

    return value;
}

// Return the top element without removing it
int peek(struct Stack *s) {
    if (isEmpty(s)) {
        printf("\n[PEEK] Stack is EMPTY. No top element.\n");
        return -1;
    }
    return s->data[s->top];
}

// Display the stack from top to bottom
void displayStack(struct Stack *s) {
    int i;

    printf("\n--- DISPLAY STACK (Top to Bottom) ---\n");

    if (isEmpty(s)) {
        printf("Stack is EMPTY.\n");
        return;
    }

    printf("top = %d\n", s->top);
    printf("Stack elements:\n");
    for (i = s->top; i >= 0; i--) {
        printf("  data[%d] = %d\n", i, s->data[i]);
    }
}

// Display internal array and top index
void displayInternal(struct Stack *s) {
    int i;

    printf("\n--- INTERNAL STATE OF STACK (ARRAY) ---\n");
    printf("Array size (MAX_SIZE) = %d\n", MAX_SIZE);
    printf("Current top index     = %d\n", s->top);

    printf("\nIndex : Value\n");
    for (i = 0; i < MAX_SIZE; i++) {
        if (i <= s->top) {
            printf("  %2d   : %d\n", i, s->data[i]);
        } else {
            printf("  %2d   : [empty]\n", i);
        }
    }
    printf("----------------------------------------\n");
}

// Utility: wait for user and clear screen (works well on Windows)
void pauseAndClear() {
    printf("\nPress Enter to continue...");
    getchar(); // to consume leftover '\n' from previous input
    getchar(); // actual wait
    // system("cls"); // uncomment this if you're on Windows and want clear screen
}
