
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <stdlib.h>
//#include <list>

//g++ -std=c++11 -o test main.cpp
using namespace std;

//1.两数之和
vector<int> twoSum1(vector<int>& nums, int target) 
{
    vector<int> ret;
    ret.clear();

    //for in for by index
    for (int i = 0; i < nums.size(); ++i)
    {
        for (int j = i+1; j < nums.size(); ++j)
        {
            if ( target == (nums[i] + nums[j]) )
            {
                ret.push_back(i);
                ret.push_back(j);

                return ret;
            }
        }
    }

    return ret;
}


vector<int> twoSum2(vector<int>& nums, int target) 
{
    unordered_map<int, int> mMap;
    vector<int> retVec;

    for (int i = 0; i < nums.size(); ++i)
    {
        unordered_map<int, int>::iterator itor =  mMap.find(target - nums[i]);
        if (itor != mMap.end())
        {
            retVec.push_back(i);
            retVec.push_back(itor->second);

            return retVec;
        }

        mMap.emplace(nums[i], i);
    }

    return retVec;
    
}


vector<int> test = {2, 7, 22, 8};

int main()
{
    vector<int> ret = twoSum2(test, 9);
    cout<<ret[0]<<", "<<ret[1]<<endl;
    
    return 0;
}