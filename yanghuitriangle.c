#include<stdio.h>

#define MAXSIZE 50
#define FALSE 0
#define TRUE 1
typedef int QueueElemType;

typedef struct
{
    QueueElemType element[MAXSIZE];
    int front;//队头
    int rear;//队尾
}SeqQueue;

void InitQueue(SeqQueue *Q)//初始化
{
    Q->front = Q->rear = 0;
}

int EnterQueue(SeqQueue *Q, QueueElemType x)//入队
{
    if ((Q->rear + 1) % MAXSIZE == Q->front)///队列已经满了
        return FALSE;
    Q->element[Q->rear] = x;
    Q->rear = (Q->rear + 1) % MAXSIZE;
    return TRUE;
}

int DelQueue(SeqQueue *Q, QueueElemType *x)//出对
{
    if (Q->front == Q->rear)
        return FALSE;
    *x = Q->element[Q->front];
    Q->front = (Q->front + 1) % MAXSIZE;
    
    return TRUE;
}
int GetHead(SeqQueue *Q, QueueElemType *x)//取对头元素
{
    if (Q->front == Q->rear)
        return FALSE;
    *x = Q->element[Q->front];
    return TRUE;
    
}
int IsEmpty(SeqQueue *Q)
{
    if (Q->rear == Q->front)
        return TRUE;
    else
        return FALSE;
}
//创建杨辉三角，N表示三角形的行数
void YangHuiTriangle(int N)
{
    int n, i, x, temp;
    SeqQueue Q;
    InitQueue(&Q);
    EnterQueue(&Q, 1);//第一行元素入队
    for (n = 2; n <= N; n++)
    {
        EnterQueue(&Q, 1);//入队
        for (i = 1; i <= n - 2; i++)
        {
            DelQueue(&Q, &temp);//出队的数赋给temp
            printf("%d ", temp);
            GetHead(&Q, &x);
            temp = temp + x;
            EnterQueue(&Q, temp);
        }
        DelQueue(&Q, &x);//出队
        printf("%d ", x);
        EnterQueue(&Q, 1);
        printf("\n");
    }
    while (!IsEmpty(&Q))
    {
        DelQueue(&Q, &x);
        printf("%d ", x);
        
    }
}
int main(void)
{
    int N;
    printf("please input the N:");
    scanf("%d", &N);
    YangHuiTriangle(N);
    printf("\n");
    return 0;   
}
