#include "LIFO.h"


LIFO_error_t LIFO_INIT(LIFO_t *lifo, unsigned int *buf, unsigned int len )
{
    if (NULL == buf ){
        return LIFO_EMPTY;
    }
    lifo->top = buf;
    lifo->Base = buf;
    lifo->length = len;
    lifo->elements_count = 0;
    return LIFO_OK;

}
LIFO_error_t LIFO_PUSH(LIFO_t *lifo, unsigned int data)
{

    if (!lifo->top || !lifo->Base)
    {
        return LIFO_NULL;
    }

    else if (lifo->elements_count == lifo->length)
    {
        return LIFO_FULL;
    }
    

    *(lifo->top) = data;
    lifo->top++;
    lifo->elements_count++;

    return LIFO_OK;


}
LIFO_error_t LIFO_POP(LIFO_t *lifo, unsigned int *buf)
{
    if (!lifo->top || !lifo->Base)
    {
        return LIFO_NULL;
    }

    else if (lifo->elements_count == 0)
    {
        return LIFO_EMPTY;
    }

    lifo->top--;
    *buf = *(lifo->top);
    lifo->elements_count--;
    return LIFO_OK;

}