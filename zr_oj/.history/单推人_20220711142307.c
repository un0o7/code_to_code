#include <stdio.h>
int convert_time_int(char *time){
    int result = (time[0]-'0')*100000+(time[1]-'0')*10000+(time[3]-'0')*1000+(time[4]-'0')*100+(time[6]-'0')*10+(time[7]-'0');
}
int main(){
    int length;
    scanf("%d",&length);
    char arr[length][2][9]; // start and end , each time for 9 chars

    int cost[length];
    for(int i=0;i<length;i++){
            scanf("%s",&arr[i][0]);
            scanf("%s",&arr[i][1]);
            scanf("%d",&cost[i]);
    }


}