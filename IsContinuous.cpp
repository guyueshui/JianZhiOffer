// Problem:
// LL今天心情特别好,因为他去买了一副扑克牌,
// 发现里面居然有2个大王,
// 2个小王(一副牌原本是54张^_^)...
// 他随机从中抽出了5张牌,想测测自己的手气,
// 看看能不能抽到顺子,如果抽到的话,
// 他决定去买体育彩票,嘿嘿！！
// “红心A,黑桃3,小王,大王,方片5”,
// “Oh My God!”不是顺子.....LL不高兴了,
// 他想了想,决定大\小 王可以看成任何数字,
// 并且A看作1,J为11,Q为12,K为13。
// 上面的5张牌就可以变成“1,2,3,4,5”
// (大小王分别看作2和4),“So Lucky!”。
// LL决定去买体育彩票啦。
// 现在,要求你使用这幅牌模拟上面的过程,
// 然后告诉我们LL的运气如何，
// 如果牌能组成顺子就输出true，
// 否则就输出false。
// 为了方便起见,你可以认为大小王是0。

/*
 * Credits: nowcoder
 * 
 * Things keep in mind 
 * 1. # of jokers <= 4
 * 2. max - min < 5, where max and min do not
 *    consider 0
 * 3. each number (1-13) must appear at most once
 */

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    bool isContinuous(vector<int> nums) {
        // boundary
        if (nums.size() == 0) return false;

        // use a array to count apperances
        int apperance[14] = {0};
        apperance[0] = -3; // <= 4 jokders -3 + 4 = 1
        
        int max = INT_MIN, // defined in <climits>
            min = INT_MAX;

        // traverse nums
        for (size_t i = 0; i != nums.size(); ++i) {
            apperance[nums[i]]++;
            if (apperance[nums[i]] > 1) return false;
            if (nums[i] == 0) continue;

            // update max and min
            if (nums[i] > max) max = nums[i];
            if (nums[i] < min) min = nums[i];
        }
        if (max - min < 5) return true;
        else return false;
    }
};

int main() {
    vector<int> ivec{1,3,2,0,0};
    cout << Solution().isContinuous(ivec);
    return 0;
}
