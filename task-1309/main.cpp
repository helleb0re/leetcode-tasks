#include <iostream>
#include <deque>

using namespace std;

char getChar(const string& str_num) {
    return 'a' + stoi(str_num) - 1;
}

string freqAlphabets(string s) {
    int fast, slow = 0;
    string res;
    for (fast = 1; fast < s.size(); ++fast) {
        fast = fast;
        if (s[fast] == '#') {
            res += getChar(s.substr(slow, fast - slow));
            slow = fast + 1;
        } else if (fast - slow > 1) {
            res += getChar(s.substr(slow, 1));
            ++slow;
        }
    }

    while (fast > slow) {
        res += getChar(s.substr(slow, 1));
        ++slow;
    }

    return res;
}

int main() {
    std::cout << freqAlphabets("10#11#12"s) << std::endl;
    return 0;
}
