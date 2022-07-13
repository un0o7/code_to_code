#include <stdio.h>
#include <math.h>
int convert_time_int(char *time){
    int result = (time[0]-'0')*100000+(time[1]-'0')*10000+(time[3]-'0')*1000+(time[4]-'0')*100+(time[6]-'0')*10+(time[7]-'0');
    return result;
}
void sort(int**time,int*cost,int length){
    //对开始时间排序，同时排序cost
    int temp;
    //使用冒泡排序的方法，根据开始时间排序


}

int main(){
    int length;
    scanf("%d",&length);
    char arr[2][length][9]; // start and end , each time for 9 chars
    int time[2][length]; // start and end , each time for 9 chars
    int cost[length];
    for(int i=0;i<length;i++){
            scanf("%s %s %d",&arr[0][i],&arr[1][i],&cost[i]);
            time[0][i] = convert_time_int(arr[0][i]); /// start time
            
            time[1][i] = convert_time_int(arr[1][i]); /// end time
    }   

    //quick_sort(time[0],0,length-1);  //对开始和结束排序
    //quick_sort(time[1],0,length-1);

    for(int i=0; i<length;i++){
        //每一个需要与前面所有的情况比较，只要满足跟在后面的条件就跟
        for(int j=0;j<i;j++){
            if(time[0][i]>=time[1][j] ){
                dp[i] = fmax(cost[i],cost[j]+cost[i]);
            }
        }
    }
    int max = 0;
    for(int i=0; i<length;i++){
        max = fmax(max,dp[i]);
    }
    printf("%d\n",max);
}