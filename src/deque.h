
#ifndef DEQUE_T
#define DEQUE_T

struct Deque;

/**
 * Construct a new deque on the heap.
 */
struct Deque* deque_create(void);

/**
 * Destroy a deque.
 */
void deque_destroy(struct Deque* deque);

/**
 * Get the number of element in a deque.
 * 
 * @param deque: The deque.
 */
unsigned int deque_size(struct Deque const* deque);

/**
 * Push an element to the front of a deque.
 * 
 * @param deque: The deque.
 * @param data: A pointer to the element.
 */
void deque_push_front(struct Deque* deque, void* data);

/**
 * Push an element to the back of a deque.
 * 
 * @param deque: The deque.
 * @param data: A pointer to the element.
 */
void deque_push_back(struct Deque* deque, void* data);

/**
 * Peek at the front-most element in the deque.
 * 
 * @param deque: The deque.
 */
void* deque_peek_front(struct Deque const* deque);

/**
 * Peek at the back-most element in the deque.
 * 
 * @param deque: The deque.
 */
void* deque_peek_back(struct Deque const* deque);

/**
 * Pop the front-most element from the deque.
 * 
 * @param deque: The deque.
 */
void deque_pop_front(struct Deque* deque);

/**
 * Pop the back-most element from the deque.
 * 
 * @param deque: The deque.
 */
void deque_pop_back(struct Deque* deque);

#endif /* DEQUE_T */
