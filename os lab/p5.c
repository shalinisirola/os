#include <stdio.h>
#include <stdlib.h>

// Initial semaphore and buffer values
int mutex = 1;
int full = 0;
int empty = 3;  // Buffer size
int x = 0;      // Item counter

// Function prototypes
void producer();
void consumer();
int wait(int);
int signal(int);

int main() {
    int choice;

    printf("1. PRODUCER\n2. CONSUMER\n3. EXIT\n");

    while (1) {
        printf("\nENTER YOUR CHOICE: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                if ((mutex == 1) && (empty != 0)) {
                    producer();
                } else {
                    printf("\nBUFFER IS FULL\n");
                }
                break;

            case 2:
                if ((mutex == 1) && (full != 0)) {
                    consumer();
                } else {
                    printf("\nBUFFER IS EMPTY\n");
                }
                break;

            case 3:
                exit(0);
                break;

            default:
                printf("\nInvalid choice! Please enter 1, 2, or 3.\n");
        }
    }

    return 0;
}

int wait(int s) {
    return (--s);  // Simulate wait operation
}

int signal(int s) {
    return (++s);  // Simulate signal operation
}

void producer() {
    mutex = wait(mutex);     // Enter critical section
    full = signal(full);     // Increase full slots
    empty = wait(empty);     // Decrease empty slots
    x++;                     // Produce an item
    printf("\nProducer produces the item %d\n", x);
    mutex = signal(mutex);   // Exit critical section
}

void consumer() {
    mutex = wait(mutex);     // Enter critical section
    full = wait(full);       // Decrease full slots
    empty = signal(empty);   // Increase empty slots
    printf("\nConsumer consumes item %d\n", x);
    x--;                     // Consume an item
    mutex = signal(mutex);   // Exit critical section
}
