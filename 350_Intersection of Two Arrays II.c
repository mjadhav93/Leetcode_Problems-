/*Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must appear as many times as it shows in both arrays and you may return the result in any order.

Example 1:
Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2,2]

Example 2:
Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [4,9]
Explanation: [9,4] is also accepted.
 
Constraints:
1 <= nums1.length, nums2.length <= 1000
0 <= nums1[i], nums2[i] <= 1000
 
Follow up:

What if the given array is already sorted? How would you optimize your algorithm?
What if nums1's size is small compared to nums2's size? Which algorithm is better?
What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once?*/

#include <stdio.h>
#include <stdlib.h>

// Function to find the minimum of two integers
int min(int a, int b) {
    return (a < b) ? a : b;
}

// Function to find the intersection of two arrays
int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    // Initialize a hash table to count occurrences of each number in nums1
    int hash[1001] = {0};  // Assuming numbers are within the range 0 to 1000

    // Count occurrences of each number in nums1
    for (int i = 0; i < nums1Size; ++i) {
        hash[nums1[i]]++;
    }

    // Initialize result array
    int* result = (int*)malloc(sizeof(int) * min(nums1Size, nums2Size));
    int resultIdx = 0;

    // Find intersection and update result array
    for (int i = 0; i < nums2Size; ++i) {
        if (hash[nums2[i]] > 0) {
            result[resultIdx++] = nums2[i];
            hash[nums2[i]]--;
        }
    }

    // Set the returnSize to the size of the result array
    *returnSize = resultIdx;

    return result;
}

// Example usage
int main() {
    int nums1[] = {1, 2, 2, 1};
    int nums1Size = 4;
    int nums2[] = {2, 2};
    int nums2Size = 2;

    int returnSize;
    int* result = intersect(nums1, nums1Size, nums2, nums2Size, &returnSize);

    printf("Intersection of nums1 and nums2: ");
    for (int i = 0; i < returnSize; ++i) {
        printf("%d ", result[i]);
    }
    printf("\n");

    free(result); // Free dynamically allocated memory

    return 0;
}
