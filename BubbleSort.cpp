// Problem:
// 输入一个整数数组，实现一个函数来调整该数组中数字的顺序，
// 使得所有的奇数位于数组的前半部分，
// 所有的偶数位于数组的后半部分，并保证奇数和奇数，
// 偶数和偶数之间的相对位置不变。

/*
 * Use any startionary sort algo.
 */

#include <vector>

using namespace std;

class Solution {
public:
    void reOrderArray(vector<int>& arr) {
        for (size_t i = arr.size(); i >= 2; --i) {
            for (size_t j = 0; j != i - 1; ++j) {
                if (!(arr[j] & 1) && arr[j + 1] & 1)
                    std::swap(arr[j], arr[j + 1]);
            }
        }
    }
};
