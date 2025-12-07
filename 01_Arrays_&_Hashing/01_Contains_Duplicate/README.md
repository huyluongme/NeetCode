## 217. Contains Duplicate

### 1. Description
Given an integer array `nums`, return `true` if any value appears **at least twice** in the array, and return `false` if every element is distinct.

#### Example 1:

> **Input:** nums = [1,2,3,1]
>
> **Output:** true
>
> **Explanation:**
>
> The element 1 occurs at the indices 0 and 3.

#### Example 2:

> **Input:** nums = [1,2,3,4]  
>
> **Output:** false  
>
> **Explanation:**  
>
> All elements are distinct.

#### Example 3:

> **Input:** nums = [1,1,1,3,3,4,3,2,4,2]  
>
> **Output:** true

#### Constraints:
- 1 <= nums.length <= $10^5$
- $-10^9$ <= nums[i] <= $10^9$

### 2. Solution
#### Approach 1 - Sort
```c
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

bool containsDuplicate(int* nums, int numsSize) {
    return approachSort(nums, numsSize);
}
```
```cpp
class Solution {
private:
    bool approachSort(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size() - 1; ++i) {
            if(nums[i] == nums[i + 1])
                return true;
        }
        return false;
    }

public:
    bool containsDuplicate(vector<int>& nums) {
        return this->approachSort(nums);
    }
};
```
#### Approach 2 - HashMap
```c
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
    return approachHashMap(nums, numsSize);
}
```
```cpp
class Solution {
private:
    bool approachHashMap1(vector<int>& nums) {
        unordered_set<int> s;
        
        for(auto i : nums) {
            if(s.find(i) != s.end())
                return true;
            
            s.insert(i);
        }
        
        return false;
    }

    int hashFunc(int key, int size) {
        return ((unsigned int)key + 1000000000U) % size;
    }

    bool approachHashMap2(vector<int>& nums) {
        int hash_table[200005];
        bool bucket_used[200005] = {false};

        for(auto i : nums) {
            int key_hash = this->hashFunc(i, nums.size());
            int start = key_hash;

            while(bucket_used[key_hash]) {
                if(hash_table[key_hash] == i)
                    return true;
                
                key_hash = (key_hash + 1) % nums.size();
                
                if(key_hash == start)
                    break;
            }

            hash_table[key_hash] = i;
            bucket_used[key_hash] = true;
        }

        return false;
    }
public:
    bool containsDuplicate(vector<int>& nums) {
        // return this->approachHashMap1(nums);
        return this->approachHashMap2(nums);
    }
};
```