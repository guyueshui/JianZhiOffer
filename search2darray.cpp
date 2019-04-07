// Pronlem: 在一个二维数组中（每个一维数组的长度相同），
// 每一行都按照从左到右递增的顺序排序，
// 每一列都按照从上到下递增的顺序排序。
// 请完成一个函数，输入这样的一个二维数组和一个整数，
// 判断数组中是否含有该整数。

/*
 * Search from the left bottom,
 * if target > a(i,j) -> right shift
 * if target < a(i,j) -> left shift
 * else return true
 *
 * it takes O(max(row,col)) time
 */

#include <vector>

using namespace std;

class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        int row_size = array.size();
        int col_size = array[0].size();
        int i = row_size - 1;
        int j = 0;
        while (i >= 0 && j < col_size) {
            if (target == array[i][j]) return true;
            if (target < array[i][j]) --i;
            else ++j;
        }

        return false;
    }
};
