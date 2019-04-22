// Problem:
// 把一个数组最开始的若干个元素搬到数组的末尾，
// 我们称之为数组的旋转。 
// 输入一个非减排序的数组的一个旋转，
// 输出旋转数组的最小元素。 
// 例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，
// 该数组的最小值为1。 
// NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。

/*
 * Using the sorted infomation to help you.
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // brute force O(n)
    int minNumberInRotateArray(vector<int> arr) {
        if (arr.size() == 0) return 0;
        // else
        for (auto iter = arr.begin(); iter != arr.end(); ++iter) {
            if (*iter > *(iter + 1))
                return *(iter + 1);
        }
        return arr.front();
    }

    // binary search O(logn)
    int binarySearch(vector<int> arr) {
        if (arr.size() == 0) return 0;
        // else
        int beg = 0, end = arr.size() - 1;
        while (beg < end) {
            int mid = (beg + end) / 2;
            if (arr[mid] < arr[end])
                end = mid;
            else if (arr[mid] > arr[end])
                beg = mid + 1;
            else // arr[mid] == arr[end]
            /*
             * for case [2, 1, 2, 2, 2]
             */
                --end;
        }
        return arr[beg];
    }
};

int main() {
    vector<int> vec{2,1,2,2,2};
    cout << Solution().binarySearch(vec);
    return 0;
}
