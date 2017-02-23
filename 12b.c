#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct factor {
    long num;
    int count;
    struct factor* next;
} factor_t;

int get_factor_count(long num);
void get_factors(long num, factor_t* head);
factor_t* create(long num);
void increment(long num, factor_t* head);

int main()
{
    long current = 0;
    long prev = 0;
    while (++prev) {
        current += prev;
        if (get_factor_count(current) > 500) {
            break;
        }
    }

    printf("%ld\n", current);
}

int get_factor_count(long num)
{
    factor_t* head = create(0);
    get_factors(num, head);
    int count = 1;

    while (head != NULL) {
        count *= (head->count + 1);
        head = head->next;
    }

    return count;
}

void get_factors(long num, factor_t* head)
{
    int i;
    int limit = (int) sqrt(num) + 1;

    for (i = 2; i <= limit; i++) {
        if (num % i == 0) { // since we're going up from 2 i is lowest prime factor of num
            increment(i, head);
            get_factors(num / i, head); // get the factors of the other divisor
            return;
        }
    }

    // if we get here num is a factor of the original but cannot be broken down further (i.e. another prime)
    increment(num, head);
}

void append(factor_t* head, long num)
{
    factor_t* current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = create(num);
}

void increment(long num, factor_t* head)
{
    factor_t* current = head;

    while (current->next != NULL && current->num != num) {
        current = current->next;
    }

    if (current->num != num) { // we reached the end without finding it
        append(current, num);
        current = current->next;
    }

    current->count++;
}

factor_t* create(long num)
{
    factor_t* factor = NULL;
    factor = malloc(sizeof(factor_t));
    if (factor == NULL) {
        exit(1);
    }
    factor->num = num;
    factor->count = 0;
    factor->next = NULL;

    return factor;
}

