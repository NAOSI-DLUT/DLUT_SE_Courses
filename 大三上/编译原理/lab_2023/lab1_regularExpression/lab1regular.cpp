#include "bits/stdc++.h"
#include "regex"

using namespace std;

map<char, bool> use_map;

void add_use_map(string s) {
    for (int i = 0; i < s.size(); i++)
        use_map[s[i]] = true;
}

bool check(string todo) {
    if (todo.size() < 8) return false;
    int cnt = 0;
    bool ffAZ = false;
    bool ffaz = false;
    bool ff09 = false;
    bool ffch = false;
    for (auto x: todo) {
        if (x >= 'A' && x <= 'Z') ffAZ = true;
        else if (x >= '0' && x <= '9') ff09 = true;
        else if (x >= 'a' && x <= 'z') ffaz = true;
        else ffch = true;

        if (use_map[x]) cnt++;
        else use_map[x] = true;
        if (cnt >= 3) return false;
    }
    if (!(ffaz && ff09 && ffAZ && ffch)) return false;
    return true;
}

int main() {
    string anw = "by99YL17";
    add_use_map(anw);

    vector<string> list = {"123456789", "12345678Q","zxcv2AP>}"};
    for (auto x: list) {
        cout << check(x) << '\t';
    }
    return 0;
}
