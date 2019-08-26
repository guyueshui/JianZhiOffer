// 请实现一个函数，将一个字符串中的每个空格替换成“%20”。
// 例如，当字符串为"We Are Happy".则经过替换之后的字符串为
// "We%20Are%20Happy"。

#include <iostream>
#include <cstring>

using namespace std;

class Solution
{
public:
  /** @IDEA
   *  1. compute the number of spaces of the given str
   *  2. compute the size needed to do the substitution
   *  3. substitute from back is more efficient
   */
  
  void replaceSpace(char* str, int length)
  {
    if (str == nullptr || length <= 0) return;

    int numspace = 0;
    int len = 0;  // length do not contain '\0'
    while (str[len] != '\0')
    {
      if (str[len] == ' ')
        ++numspace;
      ++len;
    }

    int newlen = len + 2 * numspace;
    // take null terminator into account
    if (newlen + 1 > length) return;

    while (len >= 0 && newlen > len)
    {
      if (str[len] == ' ')
      {
        str[newlen--] = '0';
        str[newlen--] = '2';
        str[newlen--] = '%';
      }
      else
      {
        str[newlen--] = str[len];
      }
      len--;
    } 
  }
};

// test
int main()
{
  char str[100] = "we   are happy to see you tommorow ";
  Solution().replaceSpace(str, 100);
  cout << str;
  return 0;
}
