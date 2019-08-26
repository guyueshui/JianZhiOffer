// Problem:
// 输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字，
// 例如，如果输入如下4 x 4矩阵： 
//  1  2  3  4 
//  5  6  7  8 
//  9 10 11 12 
// 13 14 15 16 
// 则依次打印出数字
// 1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.

/*
 * Imagine there are for borders that surround the matrix. We 
 * walk through the mat, and once achieve a border, we change
 * the direction. Each time we finished a circle, we will
 * shrink our border, and start next circle.
 *
 * After we run out (row * col) elems in the matrix, we are
 * done!
 *
 * Note:
 *    This solution is the most elegant in my opinion, for
 *    it's boundray case is quite simple.
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> spiralPrint(const vector<vector<int> >& mat) {
        vector<int> ret;
        // boundray case
        if (mat.empty()) return ret;

        int top = 0,
            bottom = mat.size() - 1,
            left = 0,
            right = mat[0].size() - 1;
        int N = (bottom + 1) * (right + 1);
        
        for (int i = 0,j = 0; N != 0; --N) {
            // make sure each loop, add exactly one elem
            ret.push_back(mat[i][j]);

            // each loop will take exactly one of
            // the following conditions
            if (i == top) {

                if (j < right) ++j; // go right
                else if (j == right) ++i; // check point

            } else if (j == right) {

                if (i < bottom) ++i; // go down
                else if (i == bottom) --j;

            } else if (i == bottom) {

                if (j > left) --j; // go left
                else if (j == left) --i;

            } else if (j == left) {

                if (i > top + 1) --i;
                else if (i == top + 1) { // shrink borders
                    ++j;
                    ++left, --right,
                    ++top, --bottom;
                }
            }
        }
        return ret;
    }
};

// test
int main() {
    vector<vector<int> > mat;
    int cnt = 1;
    for (int i=0; i!=4; ++i) {
        mat.push_back(vector<int>());
        for (int j=0; j!=4; ++j) {
            mat[i].push_back(cnt++);
        }
    }
    
    for (auto &r : mat) {
        for (auto &c : r) {
            printf("%2d ", c);
        }
        cout << endl;
    }

    vector<int> ret = Solution().spiralPrint(mat);
    for (auto &e : ret) cout << e << ' ';
    return 0;
}
