#include <stdio.h>
int main(){
    int length;
    scanf("%d",&length);
    int arr[length][2];
    int cost[length];
    for(int i=0;i<length;i++){
            scanf("%s",&arr[i]);
            scanf("%s",&arr[i][1]);
            scanf("%d",&cost[i]);
    }
}