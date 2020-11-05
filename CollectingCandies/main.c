#include <stdio.h>
#include <stdlib.h>
void descendingOrder(int *arr, int n)
{
    int count,index;
    for(count=1;count<=n;count++)
    {
        for(index=0;index<=n-1;index++)
        {
            if(arr[index]<arr[index+1])
            {
            int temp = arr[index];
            arr[index]=arr[index+1];
            arr[index+1]=temp;
            }
        }
    }
}
int choosenElement(int *stack,int *queue, int *n, int *front,int rear)
{
    if(*n==0)
    {
        (*front)++;
        return queue[(*front)-1];
    }
    if((*front)==rear)
    {
        *n--;
        return stack[(*n)];
    }
    if(stack[(*n)-1]<queue[(*front)])
    {
        (*n)--;
        return stack[(*n)];

    }else
    {
        (*front)++;
        return queue[(*front)-1];
    }
}
int main()
{
    int t,itr;
    scanf("%d",&t);
    for(itr=1;itr<=t;itr++)
    {
        int n,arr[10000],index,totalTime=0,queue[10000];
        int front,rear;
        scanf("%d",&n);
        for(index=0;index<n;index++)
            scanf("%d",&arr[index]);
            descendingOrder(arr,n);
            front=rear=0;
            if(n==1)
            {
                printf("0\n");
                continue;
            }
        while(1)
        {
            int currResult,first,second;
            first=choosenElement(arr,queue,&n,&front,rear);
            second=choosenElement(arr,queue,&n,&front,rear);
            currResult=first+second;
            queue[rear]=currResult;
            totalTime=totalTime+currResult;
            if(n==0 && front==rear)
                break;
            rear++;


        }
        printf("%d\n",totalTime);
    }

    return 0;
}
