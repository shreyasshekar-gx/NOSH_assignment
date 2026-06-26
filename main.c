#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define QUEUE_SIZE        256
#define PRINT_THRESHOLD   50
#define WAKER_INTERVAL    10   // seconds
#define MAX_BYTES_PER_TICK 5
#define TOTAL_SECONDS     30

typedef struct {
    unsigned char data[QUEUE_SIZE];
    int head;
    int tail;
    int count;
} QUEUE;

QUEUE q = { .head = 0, .tail = 0, .count = 0 };

// Add byte to queue
int push(QUEUE *q, unsigned char byte) {
    if (q->count >= QUEUE_SIZE) return -1; // full
    q->data[q->head] = byte;
    q->head = (q->head + 1) % QUEUE_SIZE;
    q->count++;
    return 0;
}

// Pop latest n bytes
int pop(QUEUE *q, unsigned char *out, int n) {
    if (n > q->count) n = q->count;
    int popped = 0;
    for (int i = 0; i < n; i++) {
        out[i] = q->data[q->tail];
        q->tail = (q->tail + 1) % QUEUE_SIZE;
        popped++;
    }
    q->count -= popped;
    return popped;
}

// Print bytes in hex
void print_hex(const unsigned char *data, int len) {
    for (int i = 0; i < len; i++) {
        printf("%02X ", data[i]);
        if ((i+1) % 16 == 0) printf("\n");
    }
    printf("\n");
}

int main(void) {
    srand(time(NULL));
    printf("=== Sensor + Waker Simulation ===\n\n");

    for (int s = 1; s <= TOTAL_SECONDS; s++) {
        // Sensor task every second
        int num_bytes = rand() % (MAX_BYTES_PER_TICK + 1);
        for (int i = 0; i < num_bytes; i++) {
            push(&q, (unsigned char)(rand() % 256));
        }
        printf("Second %2d: Sensor added %d byte(s). Queue now has %d.\n",
               s, num_bytes, q.count);

        // Waker task every 10 seconds
        if (s % WAKER_INTERVAL == 0) {
            if (q.count >= PRINT_THRESHOLD) {
                unsigned char temp[PRINT_THRESHOLD];
                int popped = pop(&q, temp, PRINT_THRESHOLD);
                printf("Second %2d: Waker took %d bytes from queue.\n", s, popped);
                printf("Data (hex): ");
                print_hex(temp, popped);
            } else {
                printf("Second %2d: Waker checked, but only %d in queue. Not enough.\n",
                       s, q.count);
            }
        }

    }

    printf("\n=== Simulation Complete ===\n");
    return 0;
}
