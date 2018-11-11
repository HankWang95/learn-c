#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>

//其他任意进制转换为十进制

int main()
{
    int trans(char a[],int );
    char arr[100];
    int t;
    scanf("%d %s",&t, arr);
    int num = trans(arr,t);
    printf("该数的十进制是:%d\n",num);
    return 0;
}

int trans(char chs[],int m)//转换为十进制
{
    char *p = chs;
    int len = strlen(p);
    int temp,sum=0;
    while(len>0)
    {
        char ss = toupper(*p);//直接调用库文件<ctype.h>的toupper()函数
        if(ss>='0' && ss<='9')
        {
            temp = (ss-'0')*pow(m,len-1);//m表示进制类型(2、8、16)
            sum = sum + temp;
        }
        
        if(ss>='A' && ss<='F')
        {
            temp = (ss-'A'+10)*pow(m,len-1);
            sum = sum + temp;
        }
        p++;
        len--;
    }
    printf("\n");
    return sum;
}
