#include <bits/stdc++.h>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int index1, index2;
        int l =0;
        int r = numbers.size()-1;
        while(r>l)
        {
            if(numbers[l]+numbers[r] == target)
            {
                index1 = l+1;
                index2 =r+1;
                break;
            }else if(numbers[l]+numbers[r] > target)
            {
                r--;
            }else{ l++; }

        }
        return {index1, index2};
    }
};