#include <stdio.h>
#include <math.h>
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
    
    int max = 0;
    int dp[20000]={0};
    for(int i=0; i<length;i++){
        if(arr[i]-difference >= 0){
            dp[arr[i]] = dp[arr[i]-difference] + 1;
            max = fmax(max,dp[arr[i]]); 
        }else{
            dp[arr[i]] = 1;
        }
    }
    printf("%d\n",max);
    return 0;
}