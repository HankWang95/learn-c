/*
https://blog.csdn.net/XSF50717/article/details/39937085
顺序队列：初始化、进队、出队（FIFO）

顺序队列存在 "假溢出"现象：
	在普通顺序队列中，入队操作就是先将尾指针rear后移一个单元(rear++)，
	然后将元素值赋给rear单元(data[rear]=X)。出队时．则是头指针front
	后移(front++)。像这样进行了一定数量入队和出队操作后，可能会出现这
	样的情况：尾指针rear已指到数组的最后一个元素．即rear==MAXLEN-1．
	此时若再执行入队操作，便会出现队满“溢出”。然而，由于在此之前可能也
	执行了若干次出队操作．因而数组的前面部分可能还有很多闲置的元素空间，
	即这种溢出并非是真的没有可用的存储空间，故称这种溢出现象为“假溢出”。
	显然，必须要解决这一似溢出的问题，否则顺序队列就没有太多使用价值。

*/


#include<stdio.h>
#include<stdlib.h>
#define QueueSize 100

typedef int DataType;

typedef struct{
	int front;
	int rear;
	DataType data[QueueSize];
}SeQueue;


// https://segmentfault.com/q/1010000004128537
// C语言传递参数都是值语义，所有的东西都是拷贝。想要修改就得传递指针，
// 想要修改一个指针，那么就得传递一个指针的指针。
SeQueue * InitSeQueue(void)
{
	SeQueue *S = (SeQueue*)malloc(sizeof(SeQueue));
	S->front = 0;
	S->rear = 0;
	return S;
}

// 入队，需要判断 队满
void Push(SeQueue *S, DataType v)
{
	if (S->front >= QueueSize) {
		printf("err : Queue is full, can not push! \n");
		return;
	}
	S->front++;
	S->data[S->front] = v;

	return ;
}

// 出队，需要判断 队空
DataType Pop(SeQueue *S)
{
	if( S->rear == QueueSize){
		printf("err : Queue is empty, can not pop \n");
		return 0;
	}
	S->rear++;
	return S->data[S->rear];
}

int main(void)
{
	SeQueue *S= InitSeQueue();
	DataType value;
	DataType i;
	printf(" FIFO Queue Test \n");

    printf("--------------------- normal test start ! ------------------- \n");
	printf("Push in 20 value\n");
	for(i=0;i<20;i++)
		{
			Push(S, i);
		}
    printf("Pop 20 value\n");
	for(i=0;i<20;i++)
    	{
    		value = Pop(S);
    		printf("%d \n", value);
    	}
    printf("--------------------- normal test complete ! -------------------\n");



    printf("--------------------- error test start ! -------------------\n");
    printf("Push in 81 value\n");
    for(i=0;i<81;i++)
        {
            Push(S, i);
        }

    printf("Pop 82 value\n");
    for(i=0;i<82;i++)
        {
            value = Pop(S);
        }
    printf("--------------------- error test complete ! -------------------\n");

    free(S);
    return 0;
}