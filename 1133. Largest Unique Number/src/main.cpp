#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution
{
public:
    int largestUniqueNumber(vector<int> &nums)
    {

        // Create a map to keep the count of key in nums vector
        map<int, int> frequencyCount;

        // Traverse the vector and keep the frequency count of each
        // element in vector
        for (auto it = nums.begin(); it != nums.end(); it++)
        {
            frequencyCount[*it]++;
        }

        // Since map is sorted by keys by default
        // use the reverse the iterator to start
        // traveral in desccending order by keys
        for (auto it = frequencyCount.rbegin(); it != frequencyCount.rend(); it++)
        {
            // Look for largest key with frequency count 1
            if (it->second == 1)
                return it->first;
        }

        // No largest num found with frequency count 1
        return -1;
    }
};

void printVector(vector<int>& vec)
{
    auto it = vec.begin();
    while (it != vec.end())
    {
        cout << *it << " ";
        it++;
    }
    cout << endl;
}

int main(int argc, char* argv[])
{
    // Create input vector
    vector<int> vec = {5,7,3,9,4,9,8,3,1};
    cout << "Input value is ";
    printVector(vec);

    // Create object of Solution class
    Solution s;
    int largestUniqueInteger = s.largestUniqueNumber(vec);

    cout << "Largest unique integer is " << largestUniqueInteger << endl;
    return 0;
}
