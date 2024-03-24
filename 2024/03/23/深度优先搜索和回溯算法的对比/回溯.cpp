#include <iostream>
#include <vector>

using namespace std;

void backtrack(vector<int> &nums, vector<int> &subset, int start)
{
    cout << "Subset: ";
    for (int num : subset)
    {
        cout << num << " ";
    }
    cout << endl;

    for (int i = start; i < nums.size(); ++i)   //依次选择每个元素作为下一个添加到子集中
    {
        subset.push_back(nums[i]);
        backtrack(nums, subset, i + 1);
        subset.pop_back();
    }
}

int main()
{
    vector<int> nums = {1, 2, 3};
    vector<int> subset;

    backtrack(nums, subset, 0);

    return 0;
}
