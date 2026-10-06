#include <stdlib.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {

    int *ans = malloc(2 * sizeof(int));

    // Range of nums[i] is -10^9 to 10^9 in LeetCode,
    // so use a simple hash table with offset.
    int size = 200003;
    int *hash = malloc(size * sizeof(int));

    // Initialize hash table
    for (int i = 0; i < size; i++) {
        hash[i] = -1;
    }

    for (int i = 0; i < numsSize; i++) {

        int complement = target - nums[i];

        // Hash index for complement
        int index = ((complement % size) + size) % size;

        // Check if complement exists
        while (hash[index] != -1) {

            if (nums[hash[index]] == complement) {

                ans[0] = hash[index];
                ans[1] = i;

                *returnSize = 2;

                free(hash);
                return ans;
            }

            index = (index + 1) % size;
        }

        // Hash index for current number
        index = ((nums[i] % size) + size) % size;

        // Handle collision
        while (hash[index] != -1) {
            index = (index + 1) % size;
        }

        // Store index
        hash[index] = i;
    }

    *returnSize = 0;

    free(hash);
    return ans;
}