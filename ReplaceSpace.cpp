#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void replaceSpace(const char* str, int len) {
    string s(str);
    for (auto pos = s.find(' ');
            pos != string::npos;
            pos = s.find(' ')) {
        s.replace(pos, 1, "%20");
    }
    cout << s;
}

int main(int argc, const char* argv[]) {
    int len = string(argv[1]).size();
    replaceSpace(argv[1], len);
    return 0;
}
