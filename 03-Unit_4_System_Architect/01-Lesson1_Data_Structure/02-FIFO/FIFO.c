#include "FIFO.h"
#include "stdio.h"
#include "stdint.h"

FIFO_Status_t FIFO_INIT(FIFO_Buffer_t *FIFO_buf, FIFO_t *buf, uint32_t length)
{
    if (buf == NULL)
        return FIFO_NULL;

    FIFO_buf->Base = buf;
    FIFO_buf->head = FIFO_buf->Base;
    FIFO_buf->tail = FIFO_buf->Base;
    FIFO_buf->length = length;
    FIFO_buf->count = 0;
    return FIFO_NO_ERROR;
}

FIFO_Status_t FIFO_Enqueue(FIFO_Buffer_t *FIFO_buf, FIFO_t item)
{
    if (FIFO_IS_FULL(FIFO_buf) == FIFO_NO_ERROR)
    {
        if (FIFO_buf->tail != FIFO_buf->Base)
            FIFO_buf->head = FIFO_buf->Base;

        *(FIFO_buf->head) = item;
        FIFO_buf->head++;
        FIFO_buf->count++;
        return FIFO_NO_ERROR;
    }
    else
    {
        printf("FIFO Eequeue is failed\n");
        return FIFO_ERROR;
    }
}
FIFO_Status_t FIFO_Dequeue(FIFO_Buffer_t *FIFO_buf, FIFO_t *item)
{
    if (FIFO_IS_EMPTY(FIFO_buf) == FIFO_NO_ERROR)
    {
        if (FIFO_buf->tail == FIFO_buf->Base + (FIFO_buf->length) * sizeof(FIFO_t))
            FIFO_buf->tail = FIFO_buf->Base;

        *item = *(FIFO_buf->tail);
        FIFO_buf->tail++;
        FIFO_buf->count--;

        return FIFO_NO_ERROR;
    }
    else
    {
        printf("FIFO Dequeue is failed\n");
        return FIFO_ERROR;
    }
}

FIFO_Status_t FIFO_IS_FULL(FIFO_Buffer_t *FIFO_buf)
{
    if (!FIFO_buf->head || !FIFO_buf->Base || !FIFO_buf->tail)
        return FIFO_NULL;

    if (FIFO_buf->count == FIFO_buf->length)
        return FIFO_FULL;

    return FIFO_NO_ERROR;
}
FIFO_Status_t FIFO_IS_EMPTY(FIFO_Buffer_t *FIFO_buf)
{
    if (!FIFO_buf->head || !FIFO_buf->Base || !FIFO_buf->tail)
        return FIFO_NULL;

    if (FIFO_buf->count == 0)
        return FIFO_EMPTY;

    return FIFO_NO_ERROR;
}