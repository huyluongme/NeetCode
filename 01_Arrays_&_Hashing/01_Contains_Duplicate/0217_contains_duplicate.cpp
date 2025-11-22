#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>

using namespace std;

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
        // return this->approachSort(nums);
        // return this->approachHashMap1(nums);
        return this->approachHashMap2(nums);
    }
};

int main() {
    vector<int> nums = {1, 2, 3, 1};
    Solution s;

    if(s.containsDuplicate(nums))
        cout << "true\n";
    else
        cout << "false\n";

    return 0;
}