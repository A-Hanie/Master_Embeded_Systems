#ifndef _FIFO_H
#define _FIFO_H

#include <stdlib.h>
#include "Platform_Types.h"

typedef struct
{
    void **QueueArray;     /* Pointer to array of void pointers */
    uint32_t QueueMaxSize; /* Maximum elements in the Queue */
    uint32_t ElementCount; /* Number of elements in the Queue */
    uint32_t index_Front;  /* Index of the front elements */
    uint32_t index_Rear;   /* Index of the rear elements */
} FIFO_t;

typedef enum
{
    FIFO_NOK,         /* FIFO operation not performed successfully */
    FIFO_OK,          /* FIFO operation performed successfully  */
    FIFO_FULL,        /* FIFO is full */
    FIFO_EMPTY,       /* FIFO is empty */
    FIFO_NULL_POINTER /* NULL pointer passed to the FIFO */
} FIFO_Status_t;

FIFO_t *FIFO_CreateQueue(uint32_t maxSize, FIFO_Status_t *ret_status);
FIFO_Status_t FIFO_EnqueueElement(FIFO_t *queue_obj, void *item_ptr);
void *FIFO_DequeueElement(FIFO_t *queue_obj, FIFO_Status_t *ret_status);
void *FIFO_Front(FIFO_t *queue_obj, FIFO_Status_t *ret_status);
void *FIFO_Rear(FIFO_t *queue_obj, FIFO_Status_t *ret_status);
FIFO_Status_t FIFO_Get_Count(FIFO_t *queue_obj, uint32_t *QueueCount);
FIFO_Status_t FIFO_Destroy(FIFO_t *queue_obj);
void *FIFO_n_elemnet(FIFO_t *FIFO_obj, uint32_t n, FIFO_Status_t *ret_status);

#endif // _FIFO_H
