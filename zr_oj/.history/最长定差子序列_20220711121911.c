#include <stdio.h>
#include <math.h>
int main(){
    int length;
    scanf("%d",&length);
    int arr[length];
    for(int i=0;i<length;i++){
            scanf("%d",&arr[i]);
        
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
    int b = 100000;  //给每一个加一个偏执值，防止溢出0
    int idx;
    for(int i=0; i<length;i++){
        idx = b+i;
        dp[idx] = fmax(dp[arr[i]+idx-difference]+1,dp[idx]);
        if(dp[idx]>max){
            max = dp[idx];
        }
    }
    printf("%d\n",max);
    return 0;
}