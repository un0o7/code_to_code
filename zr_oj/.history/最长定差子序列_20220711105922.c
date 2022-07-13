#include <stdio.h>
int main(){
    int length;
    scanf("%d",&length);
    int arr[length];
    for(int i=0;i<length;i++){
            scanf("%d",&arr[i]);
        
    }
    for (int i = 0; i < length; i++)
    {
        printf("%d ",arr[i]);
    }

    int difference;
    scanf("%d",&difference);
    if(length==0 || difference<0){
        printf("0\n");
        return 0;
    }
    // think:
    // 1. two sutiation: 递增子序列 or 递减子序列
    // 这个题和之前在牛客上做的最大公共子序列相似，所以需要用到动态规划。
    // 第一个和第二个刚好为dif，则
    int next = 0; // 下一个子序列的开头
    int last = 0; //当前子序列的上一个值
    int max = 0;
    int tmp_max=0;
    while(next<length){
        tmp_max = 0;
        for(int i=next;i<length;i++){
            if(arr[i]==arr[last]+difference){
                tmp_max++;
            }else{
                
            }
        }
        if(tmp_max>max){
            max = tmp_max;
        }
    }
    printf("%d\n",max);
    return 0;
}