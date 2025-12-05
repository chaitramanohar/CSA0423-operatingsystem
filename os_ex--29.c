#include <stdio.h>
#define SIZE 5

int buffer[SIZE];
int count = 0;

void produce(int item) {
    if(count < SIZE) {
        buffer[count++] = item;
        printf("Produced: %d\n", item);
    } else {
        printf("Buffer full! Producer waiting...\n");
    }
}

void consume() {
    if(count > 0) {
        int item = buffer[--count];
        printf("Consumed: %d\n", item);
    } else {
        printf("Buffer empty! Consumer waiting...\n");
    }
}

int main() {
    int i;
    // Simulate producer
    for(i = 1; i <= 7; i++) {
        produce(i);
    }
    // Simulate consumer
    for(i = 1; i <= 7; i++) {
        consume();
    }
    return 0;
}

