#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 交换两个元素的值
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// 分区函数，将数组分为两部分，左边大于枢轴，右边小于枢轴
int partition(int* nums, int left, int right) {
    int pivot = nums[right]; // 选择最右边的元素作为枢轴
    int i = left;
    
    for (int j = left; j < right; j++) {
        if (nums[j] > pivot) { // 注意这里是大于，因为我们想要降序排列
            swap(&nums[i], &nums[j]);
            i++;
        }
    }
    swap(&nums[i], &nums[right]);
    return i;
}

// 随机选择枢轴的分区函数，避免最坏情况
int randomizedPartition(int* nums, int left, int right) {
    srand(time(NULL));
    int random = left + rand() % (right - left + 1);
    swap(&nums[random], &nums[right]);
    return partition(nums, left, right);
}

// 快速选择算法
int quickSelect(int* nums, int left, int right, int k) {
    if (left == right) {
        return nums[left];
    }
    
    int pivotIndex = randomizedPartition(nums, left, right);
    
    if (k == pivotIndex) {
        return nums[k];
    } else if (k < pivotIndex) {
        return quickSelect(nums, left, pivotIndex - 1, k);
    } else {
        return quickSelect(nums, pivotIndex + 1, right, k);
    }
}

// 找到第k个最大的元素
int findKthLargest(int* nums, int numsSize, int k) {
    return quickSelect(nums, 0, numsSize - 1, k - 1); // k-1因为数组是从0开始索引的
}

int main() {
    int nums[] = {3, 2, 1, 5, 6, 4};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int k = 2;
    
    int result = findKthLargest(nums, numsSize, k);
    printf("The %dth largest element is: %d\n", k, result);
    
    return 0;
}