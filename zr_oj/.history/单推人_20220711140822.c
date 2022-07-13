#include <stdio.h>
int main(){
    int length;
    scanf("%d",&length);
    int arr[length][2];
    for(int i=0;i<length;i++){
            scanf("%d",&arr[i][0]);
            scanf("%d",&arr[i][1]);
    }
}