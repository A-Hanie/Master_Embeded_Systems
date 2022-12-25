#include "FIFO.h"

static uint8_t _FIFO_Is_Full(FIFO_t *FIFO_obj)
{
    return (FIFO_obj->ElementCount == FIFO_obj->QueueMaxSize);
}

static uint8_t _FIFO_Is_Empty(FIFO_t *FIFO_obj)
{
    return (0 == FIFO_obj->ElementCount);
}

FIFO_t *FIFO_CreateQueue(uint32_t maxSize, FIFO_Status_t *ret_status)
{
    FIFO_t *MyFIFO;
    MyFIFO = (FIFO_t *)malloc(sizeof(FIFO_t));
    if (NULL == MyFIFO)
    {
        *ret_status = FIFO_NULL_POINTER;
        MyFIFO = NULL;
    }
    else
    {
        MyFIFO->QueueArray = (void **)calloc(maxSize, sizeof(void *));
        if (NULL == MyFIFO->QueueArray)
        {
            *ret_status = FIFO_NOK;
            MyFIFO = NULL;
        }
        else
        {
            MyFIFO->ElementCount = 0;
            MyFIFO->index_Front = -1;
            MyFIFO->index_Rear = -1;
            MyFIFO->QueueMaxSize = maxSize;
            *ret_status = FIFO_OK;
        }
    }
    return MyFIFO;
}

FIFO_Status_t FIFO_EnqueueElement(FIFO_t *FIFO_obj, void *item_ptr)
{
    FIFO_Status_t status = FIFO_NOK;
    if ((NULL == FIFO_obj) || (NULL == item_ptr))
    {
        status = FIFO_NULL_POINTER;
    }
    else
    {
        /* Validate if the FIFO is not full */
        if (_FIFO_Is_Full(FIFO_obj))
        {
            status = FIFO_FULL; /* FIFO is full, can't enFIFO new element */
        }
        else
        {
            /* Increment FIFO Rear Index */
            (FIFO_obj->index_Rear)++;
            /* FIFO wraps to element 0 (Circular FIFO) */
            if (FIFO_obj->index_Rear == FIFO_obj->QueueMaxSize)
            {
                FIFO_obj->index_Rear = 0;
            }
            else
            { /*Nothing */
            }
            /* Insert the input data in to the rear position */
            FIFO_obj->QueueArray[FIFO_obj->index_Rear] = item_ptr;
            /* validate if the FIFO was empty, (front and rear points to the first element) */
            if (FIFO_obj->ElementCount == 0)
            {
                FIFO_obj->index_Front = 0;
                FIFO_obj->ElementCount = 1;
            }
            else
            {
                (FIFO_obj->ElementCount)++; /* New element has been added to the FIFO */
            }
            status = FIFO_OK;
        }
    }
    return status;
}

void *FIFO_DequeueElement(FIFO_t *FIFO_obj, FIFO_Status_t *ret_status)
{
    void *ReturnEelem = NULL;
    if ((NULL == FIFO_obj) || (NULL == ret_status))
    {
        *ret_status = FIFO_NULL_POINTER;
    }
    else
    {
        /* Check if the FIFO is empty */
        if (!FIFO_obj->ElementCount)
        {
            *ret_status = FIFO_EMPTY; /* FIFO is empty */
            ReturnEelem = NULL;
        }
        else
        { /* FIFO is not empty */
            ReturnEelem = FIFO_obj->QueueArray[FIFO_obj->index_Front];
            /* Increment FIFO Front Index */
            (FIFO_obj->index_Front)++;
            /* FIFO front has wrapped to element 0 (Circular FIFO) */
            if (FIFO_obj->index_Front == FIFO_obj->QueueMaxSize)
            {
                FIFO_obj->index_Front = 0;
            }
            else
            { /* Nothing */
            }
            /* Check if the element is the last element in the FIFO */
            if (1 == FIFO_obj->ElementCount)
            {
                FIFO_obj->index_Front = -1; /* FIFO is empty */
                FIFO_obj->index_Rear = -1;  /* FIFO is empty */
            }
            else
            { /* Nothing */
            }
            (FIFO_obj->ElementCount)--; /* Element has been deleted from the FIFO */
            *ret_status = FIFO_OK;
        }
    }
    return ReturnEelem;
}

void *FIFO_Front(FIFO_t *FIFO_obj, FIFO_Status_t *ret_status)
{
    void *ReturnEelem = NULL;
    if ((NULL == FIFO_obj) || (NULL == ret_status))
    {
        *ret_status = FIFO_NULL_POINTER;
    }
    else
    {
        /* Check if the FIFO is empty */
        if (!FIFO_obj->ElementCount)
        {
            *ret_status = FIFO_EMPTY; /* FIFO is empty */
            ReturnEelem = NULL;
        }
        else
        { /* FIFO is not empty */
            ReturnEelem = FIFO_obj->QueueArray[FIFO_obj->index_Front];
            *ret_status = FIFO_OK;
        }
    }
    return ReturnEelem;
}

void *FIFO_Rear(FIFO_t *FIFO_obj, FIFO_Status_t *ret_status)
{
    void *ReturnEelem = NULL;
    if ((NULL == FIFO_obj) || (NULL == ret_status))
    {
        *ret_status = FIFO_NULL_POINTER;
    }
    else
    {
        /* Check if the FIFO is empty */
        if (!FIFO_obj->ElementCount)
        {
            *ret_status = FIFO_EMPTY; /* FIFO is empty */
            ReturnEelem = NULL;
        }
        else
        { /* FIFO is not empty */
            ReturnEelem = FIFO_obj->QueueArray[FIFO_obj->index_Rear];
            *ret_status = FIFO_OK;
        }
    }
    return ReturnEelem;
}

void *FIFO_n_elemnet(FIFO_t *FIFO_obj, uint32_t n, FIFO_Status_t *ret_status)
{
    void *ReturnEelem = NULL;
    if ((NULL == FIFO_obj) || (NULL == ret_status))
    {
        *ret_status = FIFO_NULL_POINTER;
    }
    else
    {
        /* Check if the FIFO is empty */
        if (!FIFO_obj->ElementCount)
        {
            *ret_status = FIFO_EMPTY; /* FIFO is empty */
            ReturnEelem = NULL;
        }
        else
        { /* FIFO is not empty */
            if (n <= FIFO_obj->QueueMaxSize)
            {
                ReturnEelem = FIFO_obj->QueueArray[n];
                *ret_status = FIFO_OK;
            }
            else
            {
                ret_status = FIFO_NOK;

            }
        }
    }
    return ReturnEelem;
}

FIFO_Status_t FIFO_Get_Count(FIFO_t *FIFO_obj, uint32_t *FIFOCount)
{
    FIFO_Status_t status = FIFO_NOK;
    if ((NULL == FIFO_obj) || (NULL == FIFOCount))
    {
        status = FIFO_NULL_POINTER;
    }
    else
    {
        /* Check if the FIFO is empty */
        if (!FIFO_obj->ElementCount)
        {
            *FIFOCount = 0; /* FIFO is empty */
        }
        else
        { /* FIFO is not empty */
            *FIFOCount = FIFO_obj->ElementCount;
        }
        status = FIFO_OK;
    }
    return status;
}

FIFO_Status_t FIFO_Destroy(FIFO_t *FIFO_obj)
{
    FIFO_Status_t status = FIFO_NOK;
    if (NULL == FIFO_obj)
    {
        status = FIFO_NULL_POINTER;
    }
    else
    {
        free(FIFO_obj->QueueArray);
        free(FIFO_obj);
        status = FIFO_OK;
    }
    return status;
}
