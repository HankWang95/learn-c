#include<stdio.h>
#include<stdlib.h>

#define QueueSize 100

/*
 循环队列
 https://blog.csdn.net/XSF50717/article/details/39937085
 为充分利用向量空间，克服"假上溢"现象的方法是：将向量空间想象为一个首尾相接的圆环，并称这种向量为循环向量。存储在其中的队列称为循环队列（Circular Queue）。即：循环队列中进行出队、入队操作时，头尾指针仍要加1，朝前移动。只不过当头尾指针指向向量上界（QueueSize-1）时，其加1操作的结果是指向向量的下界0。

循环队列中，由于入队时尾指针向前追赶头指针；出队时头指针向前追赶尾指针，造成队空和队满时头尾指针均相等。因此，无法通过条件front==rear来判别队列是"空"还是"满"。

解决这个问题的方法至少有三种：
　　另设一布尔变量以区别队列的空和满；
　　少用一个元素的空间。约定入队前，测试尾指针在循环意义下加1后是否等于头指针，若相等则认为队满（注意：rear所指的单元始终为空）；
　　使用一个计数器记录队列中元素的总数（即队列长度）。
*/

typedef int DataType;
typedef struct{
    int front;
    int rear;
    int count;
    DataType data[QueueSize];
} CirQueue;

CirQueue * InitCirQueue(void)
{
    CirQueue *C = (CirQueue*)malloc(sizeof(CirQueue));
    C->front = 0;
    C->rear = 0;
    C->count = 0;
    return C;
}

// 入队，需要判断 队满
void Push(CirQueue *C, DataType v)
{
    if (C->count >= QueueSize) {
        printf("err : Queue is full, can not push! \n");
        return;
    }
    C->front = (C->front+1) % QueueSize ;
    C->data[C->front] = v;
    C->count++;
    return ;
}

// 出队，需要判断 队空
DataType Pop(CirQueue *C)
{
    if( C->count == 0){
        printf("err : Queue is empty, can not pop \n");
        return 0;
    }
    C->rear = (C->rear+1)%QueueSize;
    C->count--;
    return C->data[C->rear];
}

int main(void)
{
    CirQueue *C= InitCirQueue();
    DataType value;
    DataType i;
    printf(" FIFO Queue Test \n");
    
    printf("--------------------- normal test start ! ------------------- \n");
    printf("Push in 20 value\n");
    for(i=0;i<20;i++)
    {
        Push(C, i);
    }
    printf("Pop 20 value\n");
    for(i=0;i<20;i++)
    {
        value = Pop(C);
        printf("%d \n", value);
    }
    printf("--------------------- normal test complete ! -------------------\n");
    
    
    
    printf("--------------------- error test start ! -------------------\n");
    printf("Push in 81 value\n");
    for(i=0;i<81;i++)
    {
        Push(C, i);
    }
    
    printf("Pop 82 value\n");
    for(i=0;i<82;i++)
    {
        value = Pop(C);
    }
    printf("--------------------- error test complete ! -------------------\n");
    
    free(C);
    return 0;
}

