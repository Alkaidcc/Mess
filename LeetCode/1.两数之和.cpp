#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> answer;
        unordered_map<int,int> hashmap;
        for (int i = 0;i < nums.size();i++){
            hashmap[nums[i]] = i;
        }
        for(int i = 0; i < nums.size();i++){
            if(hashmap[target - nums[i]] && hashmap[target- nums[i]] != i){
                answer.push_back(i);
                answer.push_back(hashmap[target - nums[i]]);
                return answer;
            }
        }
        return answer;
    }
};


