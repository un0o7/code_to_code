#include <stdio.h>
int convert_time_int(char *time){
    int result = (time[0]-'0')*100000+(time[1]-'0')*10000+(time[3]-'0')*1000+(time[4]-'0')*100+(time[6]-'0')*10+(time[7]-'0');
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
    int time[2][length]; // start and end , each time for 9 chars
    int cost[length];
    for(int i=0;i<length;i++){
            scanf("%s",&arr[i][0]);
            time[i][0] = convert_time_int(arr[i][0]); /// start time
            scanf("%s",&arr[i][1]);
            time[i][1] = convert_time_int(arr[i][1]); /// end time
            scanf("%d",&cost[i]);
    }   
    quick_sort(time[0],0,length-1);  //对开始和结束排序
    quick_sort(time[1],0,length-1);


}