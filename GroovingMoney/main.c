#include <stdio.h>
#include <stdlib.h>

int main()
{
    int arr[7]={0,3,6,5,4,1,2},n=6,index,t;
    char originalPosition[]="0ABCDEF",newPosition1[8];
    char newPosition2[8]="0ABCDEF";
    for(t=1;;t++)
    {
        for(index=1;index<=n;index++)
            newPosition1[arr[index]]=newPosition2[index];
        for(index=1;index<=n && newPosition1[index]==originalPosition[index];index++)
            if(index==7)
                break;
            t++;
        for(index=1;index<=n;index++)
            newPosition2[arr[index]]=newPosition1[index];
        for(index=1;index<=n && newPosition2[index]==originalPosition[index];index++)
            if(index==7)
                break;
    }
    printf("%d",t);
    return 0;
}
