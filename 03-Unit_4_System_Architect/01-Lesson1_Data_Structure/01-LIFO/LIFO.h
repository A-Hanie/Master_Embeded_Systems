#ifndef LIFO_H_
#define LIFO_H_

#define NULL (void *)0

typedef enum{
    LIFO_NULL,
    LIFO_EMPTY,
    LIFO_FULL,
    LIFO_OK
}LIFO_error_t;

typedef struct{

	unsigned int *Base ;
	unsigned int *top ;
	unsigned int elements_count ;
	unsigned int length ;

}LIFO_t;

LIFO_error_t LIFO_INIT(LIFO_t *lifo, unsigned int *buf, unsigned int len );
LIFO_error_t LIFO_PUSH(LIFO_t *lifo, unsigned int data);
LIFO_error_t LIFO_POP(LIFO_t *lifo, unsigned int *buf);

#endif  /* LIFO_H_ */