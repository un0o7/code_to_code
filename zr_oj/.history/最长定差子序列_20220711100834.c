#include <stdio.h>
int main(){
    int length;
    scanf("%d",&length);
    int arr[length];
    for(int i=0;i<length;i++){
            scanf("%d ",&arr[i]);
        
    }
    for (int i = 0; i < length; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
    int difference;
    scanf("\n%d",&difference);
    printf("%d\n",difference);
    if(length==0 || difference<0){
        printf("0\n");
        return 0;
    }
    // think:
    // 1. two sutiation: 递增子序列 or 递减子序列

    return 0;
}