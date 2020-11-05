#include<stdio.h>
#include<stdlib.h>
int gcd(int a, int b)
{
    int rem;
    while(1)
    {
        rem=a%b;
        if(rem==0)
            return b;
        else
        {
            a=b;
            b=rem;
        }
    }

}
int lcm(int num1, int num2)
{
    if(num1%num2==0)
        return num1;
    else if(num2%num1==0)
        return num2;
    return (num1*num2)/gcd(num1, num2);
}
int main()
{
    int arr[1000],n;
    int count[1000]={0},index,lcmValue=1;
    scanf("%d",&n);
    for(index=1;index<=n;index++)
        scanf("%d",&arr[index]);
    for(index=1;index<=n;index++)
    {
        int originalPosition=index,currPosition=index;
        if(count[originalPosition]==-1)
            continue;
        do
        {
            currPosition=arr[currPosition];
            count[originalPosition]++;
            if(currPosition==originalPosition)
                break;
            else
                count[currPosition]=-1;
        }while(1);
        lcmValue=lcm(lcmValue,count[originalPosition]);
    }
    printf("%d",lcmValue);
    return 0;
}
