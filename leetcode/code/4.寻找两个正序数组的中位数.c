/*
 * @lc app=leetcode.cn id=4 lang=c
 *
 * [4] 寻找两个正序数组的中位数
 */

// @lc code=start


double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
       int length = nums1Size + nums2Size;
    int p = 0,q = 0,pre = -1,next = -1;
    for(int i = 0;i <= length/2;i++){
        printf("p:%d q:%d\n",p,q);
        pre = next;
        if(( nums1[p] < nums2[q])){
            next = nums1[p];
            p++;
        }
        else{
            next = nums2[q];
            q++;
        }
    }
    if(length % 2 == 0)
        return (pre + next) / 2.0;
    return next;
}
// @lc code=end

