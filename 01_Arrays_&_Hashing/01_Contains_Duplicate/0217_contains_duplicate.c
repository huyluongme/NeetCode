#include <stdio.h>
#include <stdbool.h>

#include <stdlib.h> /* qsort */

int comp(const void* a, const void* b) {
    return *(int*)a > *(int*)b;
}

/* Syntax: qsort(array, n, size, comp) */
bool approachSort(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(nums[0]), comp);

    for(int i = 0; i < numsSize - 1; ++i)
        if(nums[i] == nums[i + 1])
            return true;
    return false;
}

int hashFunc(int key, int size) {
    return ((unsigned int)key + 1000000000U) % size;
}

bool approachHashMap(int* nums, int numsSize) {
    int hash_table[200003];
    bool bucket_used[200003] = {false};

    for(int i = 0; i < numsSize; ++i) {
        int key_hash = hashFunc(nums[i], 200003);
        int start = key_hash;

        while(bucket_used[key_hash]) {
            if(hash_table[key_hash] == nums[i])
                return true;

            key_hash = (key_hash + 1) % 200003;
            if(key_hash == start)
                break;
        }

        hash_table[key_hash] = nums[i];
        bucket_used[key_hash] = true;
    }

    return false;
}

bool containsDuplicate(int* nums, int numsSize) {
    // return approachSort(nums, numsSize);
    return approachHashMap(nums, numsSize);
}

int main()
{
    int nums[] = {1, 2, 3, 1};
    int numsSize = sizeof(nums)/sizeof(nums[0]);

    if(containsDuplicate(nums, numsSize))
        printf("true\n");
    else
        printf("false\n");

    return 0;
}
