#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/find-the-duplicate-number/submissions/

// find extra number in n+1 without using extra space and modifying

// approach 1 flip when you see an positive flip it negative 

// so what we do is we iterate over array and makes the digit -ve for value of  arr[i] value now arr[i] will repeat for at least 1 i 
// we see that value is already negative so arr[i] was repeating

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int duplicate = -1;
        for (int i = 0; i < nums.size(); i++) {
            int cur = abs(nums[i]);
            if (nums[cur] < 0) {
                duplicate = cur;
                break;
            }
            nums[cur] *= -1;
        }
        
        // Restore numbers
        for (auto& num : nums)
            num = abs(num);
        
        return duplicate;
    }
};

// approach 2 tortoise we will traverse  one with slow pointer another with fast pointer
// such way we will jump to index equal to value of previous index i.e a[i]
// as 2 value is same at different index they will form a loop they will meet at a distance now
// we place the fast pointer at starting and move it by 1 only when they will meet the of  index will be repeated value
// proof in video ,index because were parsing value only


class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        int slow=nums[0];
        int fast=nums[0];
        
        do{
            slow=nums[slow];
            fast=nums[nums[fast]];
            
        }while(slow!=fast);
        
        fast=nums[0];
        
        while(slow!=fast){
            slow=nums[slow];
            fast=nums[fast];
        }
        
        return slow;
        
    }
};



