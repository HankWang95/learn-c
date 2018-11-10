
#include<stdio.h>
#include<stdlib.h>

/*
 链式队列
*/

typedef int DataType;

// 定义链节点
typedef struct Node{
    DataType data;
    struct Node *next;
} QueueNode, *QueueNodePtr;


// 定义队列
typedef struct{
    QueueNodePtr front;
    QueueNodePtr rear;
} NQueue;


NQueue * InitNQueue(void)
{
    // 初始化
    NQueue *N = (NQueue*)malloc(sizeof(NQueue));
    N->front = N->rear = (QueueNodePtr)malloc(sizeof(QueueNode));
    
    return N;
}

// 入队
void Push(NQueue *N, DataType v)
{
    // 首先生成一个节点
    QueueNodePtr nodePtr;
    nodePtr = (QueueNodePtr)malloc(sizeof(QueueNode));
    nodePtr->data = v;
    // 申请next指针
    nodePtr->next = NULL;
    
    // Queue 装载节点（链接）
    N->rear->next = nodePtr;
    N->rear = nodePtr;
    return ;
}

// 出队
DataType Pop(NQueue *N)
{
    // 判空
    if (N->front == N->rear)
    {
        printf("Queue is empty, can not pop \n");
        return 0;
    }
    
    // 暂存队头指针
    QueueNodePtr nodePtr;
    nodePtr = N->front->next;
    
    
    // 队头指针指向next
    // 只存在一个节点时，需要特殊处理，不然free时会出问题
    if (nodePtr == N->rear)
    {
        DataType v;
        v = nodePtr->data;
        N->front = N->rear;
        return v;
    }
    N->front->next = N->front->next->next;
    DataType v;
    v = nodePtr->data;
    free(nodePtr);
    return v;
}


// 销毁
void DestroyQueue(NQueue *N)
{
    while(N->front){
        N->rear=N->front->next;
        free(N->front);
        N->front=N->rear;
    }
    printf("Destroy Queue Complete! \n");
}

int main(void)
{
    NQueue *N= InitNQueue();
    DataType value;
    DataType i;
    printf(" FIFO Queue Test \n");
    
    printf("--------------------- normal test start ! ------------------- \n");
    printf("Push in 20 value\n");
    for(i=0;i<20;i++)
    {
        Push(N, i);
    }
    printf("Pop 20 value\n");
    for(i=0;i<20;i++)
    {
        value = Pop(N);
        printf("%d \n", value);
    }
    printf("--------------------- normal test complete ! -------------------\n");
    
    
    
    printf("--------------------- error test start ! -------------------\n");
    printf("Push in 81 value\n");
    for(i=0;i<81;i++)
    {
        Push(N, i);
    }
    
    printf("Pop 82 value\n");
    for(i=0;i<82;i++)
    {
        value = Pop(N);
    }
    printf("--------------------- error test complete ! -------------------\n");
    

    DestroyQueue(N);
    return 0;
}

