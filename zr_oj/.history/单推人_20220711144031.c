#include <stdio.h>
#include <math.h>
double convert_time_int(char *time){
    double int result = (time[0]-'0')*10000+(time[1]-'0')*1000+(time[3]-'0')*100+(time[4]-'0')*10+(time[6]-'0')*1+(time[7]-'0');
    return result;
}
void quick_sort(int *arr,int left,int right){
    if(left>=right) return;
    int pivot = arr[left];
    int i = left+1,j=right;
    while(i<=j){
        while(i<=right && arr[i]<=pivot) i++;
        while(j>=left && arr[j]>pivot) j--;
        if(i<j){
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    arr[left] = arr[j];
    arr[j] = pivot;
    quick_sort(arr,left,j-1);
    quick_sort(arr,j+1,right);
}
int main(){
    int length;
    scanf("%d",&length);
    char arr[2][length][9]; // start and end , each time for 9 chars
    long int time[2][length]; // start and end , each time for 9 chars
    int cost[length];
    for(int i=0;i<length;i++){
            scanf("%s",&arr[0][i]);
            time[0][i] = convert_time_int(arr[0][i]); /// start time
            scanf("%s",&arr[0][i]);
            time[1][i] = convert_time_int(arr[1][i]); /// end time
            scanf("%d",&cost[i]);
    }   
    printf("%d\n", length);
    for(int i=0;i<length;i++){
        printf("%d %d %d\n",time[0][i],time[1][i],cost[i]);
    }
    //quick_sort(time[0],0,length-1);  //对开始和结束排序
    //quick_sort(time[1],0,length-1);
    int dp[length];//记录每种可能的情况及其花费
    for(int i=0;i<length;i++){
        dp[i] = 0;
    }
    int i=0,j=0;
    for(int i=0; i<length;i++){
        while(j<length && time[0][i]>=time[1][j]){
            dp[j] = fmax(dp[j],cost[j]);
            j++;
        }
        dp[i] = fmax(dp[i-1],cost[j]);
    }
    int max = 0;
    for(int i=0; i<length;i++){
        max = fmax(max,dp[i]);
    }
    printf("%d\n",max);
}