
#include "deque.h"

#include <stdint.h>
#include <stdlib.h>
#include <iso646.h>

struct Node
{
        void* data;
        struct Node* next;
        struct Node* prev;
};

struct Deque
{
        struct Node* head;
        struct Node* tail;
        unsigned int size;
};

struct Deque* deque_create(void)
{
        struct Deque* deque = malloc(sizeof(*deque));
        if (not deque)
                return NULL;

        deque->head = NULL;
        deque->tail = NULL;
        deque->size = 0;

        return deque;
}

void deque_destroy(struct Deque* deque)
{
        free(deque);
}

unsigned int deque_size(struct Deque const* deque)
{
        return deque->size;
}

void deque_push_front(struct Deque* deque, void* data)
{
        struct Node* node = malloc(sizeof(*node));
        node->data = data;

        node->next = deque->head;
        node->prev = NULL;

        if (deque->head)
                deque->head->prev = node;
        deque->head = node;

        if (not deque->tail)
                deque->tail = node;

        ++deque->size;
}

void deque_push_back(struct Deque* deque, void* data)
{
        struct Node* node = malloc(sizeof(*node));
        node->data = data;

        node->next = NULL;
        node->prev = deque->tail;

        if (deque->tail)
                deque->tail->next = node;
        deque->tail = node;

        if (not deque->head)
                deque->head = node;

        ++deque->size;
}

void* deque_peek_front(struct Deque const* deque)
{
        if (not deque->head)
                return NULL;

        return deque->head->data;
}

void* deque_peek_back(struct Deque const* deque)
{
        if (not deque->tail)
                return NULL;

        return deque->tail->data;
}

void deque_pop_front(struct Deque* deque)
{
        if (not deque->head)
                return;

        struct Node* node = deque->head;

        if (node->next)
                node->next->prev = NULL;
        deque->head = node->next;

        --deque->size;

        free(node);
}

void deque_pop_back(struct Deque* deque)
{
        if (not deque->tail)
                return;

        struct Node* node = deque->tail;

        if (node->prev)
                node->prev->next = NULL;
        deque->tail = node->prev;

        --deque->size;

        free(node);
}
