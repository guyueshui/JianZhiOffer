// Problem:
// 牛客最近来了一个新员工Fish，
// 每天早晨总是会拿着一本英文杂志，写些句子在本子上。
// 同事Cat对Fish写的内容颇感兴趣，
// 有一天他向Fish借来翻看，但却读不懂它的意思。
// 例如，“student. a am I”。后来才意识到，
// 这家伙原来把句子单词的顺序翻转了，
// 正确的句子应该是“I am a student.”。
// Cat对一一的翻转这些单词顺序可不在行，你能帮助他么？

#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

stack<string> sentenceReverse(const string _s) {
    stack<string> res;
    string::size_type pos0 = 0, pos1 = 0;

    while (pos1 != string::npos) {
        pos1 = _s.find(' ', pos0); // find from pos0
        // substr(pos, count):
        // begin at pos, extract `count` characters
        res.push(_s.substr(pos0, pos1 - pos0));
        if (pos1 == string::npos)
            break;
        pos0 = pos1 + 1; 
    }

    return res;
}

int main() {
    string sentence{"student. a am I"};
    stack<string> ss = sentenceReverse(sentence);
    while (!ss.empty()) {
        cout << ss.top() << ' ';
        ss.pop();
    }
    return 0;
}
