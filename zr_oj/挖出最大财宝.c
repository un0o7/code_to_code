#include <stdio.h>
#include <math.h>
int m = 0;
int n = 0;
int max_path(int Mine[m][n], int row, int col)
{
    printf("m:%d, n:%d, row:%d, col:%d\n", m, n, row, col);
    // 遍历过的非-1节点设置为 -1，然后递归计算财宝数量

    int max = 0; //最大财宝数量
    int temp = 0;
    if (row - 1 >= 0 && Mine[row - 1][col] != -1)
    {
        temp = Mine[row - 1][col];
        Mine[row - 1][col] = -1;
        max = max_path(Mine, row - 1, col);
        Mine[row - 1][col] = temp;
    }
    if (row + 1 < m && Mine[row + 1][col] != -1)
    {
        temp = Mine[row + 1][col];
        Mine[row + 1][col] = -1;
        max = max_path(Mine, row + 1, col);
        Mine[row + 1][col] = temp;
    }
    if (col - 1 >= 0 && Mine[row][col - 1] != -1)
    {
        temp = Mine[row][col - 1];
        Mine[row][col - 1] = -1;
        max = max_path(Mine, row, col - 1);
        Mine[row][col - 1] = temp;
    }
    if (col + 1 < n && Mine[row][col + 1] != -1)
    {
        temp = Mine[row][col + 1];
        Mine[row][col + 1] = -1;
        max = max_path(Mine, row, col + 1);
        Mine[row][col + 1] = temp;
    }
    printf("%d\n", max + Mine[row][col]);
    return max + Mine[row][col];
}

int main(int argc, char **argv)
{
    // 给你一个大小为m*n的矩阵Mine表示矿场，里面有丰富的宝石。Mine(i,j)若大于0，表示该点存在宝石，其值为宝石价值；
    //若等于0，表示的是不可进入的区域；若小于-1表示危险区域。当你选择一个点挖宝石的时候，你可以把相邻（上下左右)的宝石也挖出来。
    //但是注意，任意你挖出宝石的点不可与危险区域相邻。

    scanf("%d%d", &m, &n);
    printf("%d %d\n", m, n);
    int Mine[m][n];

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (Mine[i][j] != -1)
            {
                scanf("%d", &Mine[i][j]);
                printf("%d\n", Mine[i][j]);
                if (Mine[i][j] == -1)
                {
                    for (int k = i - 1; k <= i + 1; k++)
                    {
                        for (int l = j - 1; l <= j + 1; l++)
                        {
                            if (k >= 0 && k < m && l >= 0 && l < n && (i == k || j == l))
                            {
                                Mine[k][l] = -1;
                            }
                        }
                    }
                }
            }
        }
    }
    //上下左右移动，且不经过-1的最大路径和
    //本质上是以上下相邻关系来表示图的连接
    int max = 0;
    int temp = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (Mine[i][j] != -1)
            {

                max = fmax(max, max_path(Mine, i, j));
                printf("max: %d\n", max);
            }
        }
    }
    printf("max: %d\n", max);
    return max;
}