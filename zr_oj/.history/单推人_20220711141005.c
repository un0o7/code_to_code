#include <stdio.h>
int main(){
    int length;
    scanf("%d",&length);
    char arr[length][2][9]; // start and end , each time for 9 chars

    int cost[length];
    for(int i=0;i<length;i++){
            scanf("%s",&arr[i]);
            scanf("%s",&arr[i]);
            scanf("%d",&cost[i]);
    }

}