// Problem:
// 求出1~13的整数中1出现的次数,
// 并算出100~1300的整数中1出现的次数？
// 为此他特别数了一下1~13中包含1的数字有1、10、11、12、13
// 因此共出现6次,但是对于后面问题他就没辙了。
// ACMer希望你们帮帮他,并把问题更加普遍化,
// 可以很快的求出任意非负整数区间中1出现的次数
// （从1 到 n 中1出现的次数）。

/*
 * Credits: unknown
 *
 * Idea:
 *   1) Focus exactly one decimal position, calculate the
 *      number of ones.
 *   2) Run out from lowest to highest position, add them
 *      together, it's the answer.
 *
 *  Imaging the numbers from 1 to n sits in a line in
 *  front of you. Now you're required to calculates all
 *  the ones in the sequence. A basic way is that, each
 *  time I focus on the same digit pos, and count all
 *  ones in that pos. Next time I focus on another pos.
 *  And I sum them all together, finally got the answer.
 *
 *  See how can we count the num of ones in a specific
 *  decimal pos? Let's do that! Suppose N = 301563. 
 *
 *  Step 1.
 *  Now I focus the hundred position, and split N into `a`
 *  and `b`, where
 *
 *  a = ceil(N / 100) = 3015
 *  b = N % 100 = 63
 *
 *  1). There are (a / 10 + 1) = 302 hits of one
 *  2). Each of length 100
 *  3). Totally (a/10 + 1) * 100 hits of one
 *
 *  Let me explain a little:
 *  (000-301)5(00-99) -> (000-301)1(00-99)
 *  
 *  The digits above hundred pos have 302 variants, and
 *  the digits under hundred pos has 100 variants, thus
 *  gives a total (a/10 + 1) * 100.
 *
 *  Step 2.
 *  This time I focus on thousand pos, and now
 *
 *  a = N / 1,000 = 301
 *  b = N % 1,000 = 563
 *
 *  1). There are (a/10) = 30 hits of one
 *  2). Each of length 1000
 *  3). And a tail hits of 564
 *
 *  (00-29)1(000-999) + 301(000-563)
 *  This gives 30 * 1000 + 564 = (a/10)*1000+(b+1)
 *
 *  Step 3.
 *  Now move to ten thousand pos, with
 *
 *  a = N / 10,000 = 30
 *  b = N % 10,000 = 1563
 *
 *  1). There are total (a/10)=3 hit
 *  2). Each of length 10,000
 *
 *  (0-2)1(0000-9999)
 *  gives 3 * 10,000 = (a/10).
 *
 *  That's all 3 cases. Let's write!
 */

class Solution {
public:
    int NumOnes(int n) {
        int ones = 0;
        for (long long m = 1; m <= n; m *= 10) {
            ones +=
                /*
                 * this covers case 1 & 3
                 * since (a+8)/10 = a/10 + 1 if a%10 >= 2
                 * (a+8)/10 = a/10 if a%10 == 0
                 */
                (n/m + 8) / 10 * m
                +
                // case 2
                (n/m % 10 == 1) * (n%m + 1);
        }
        return ones;
    }
};
