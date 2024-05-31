#include <bits/stdc++.h>

using namespace std;

void toFuzz(string name, string surname) {
    int fullNameLength = name.length() + surname.length();
    vector<char> fullName(fullNameLength);
    for (int i = 0 ; i < fullNameLength ; i++) {
        int offset = (name == "Gustavo" && surname == "Galdino") ? 1000000 : 0;
        fullName[i + offset] = (i < name.length()) ? name[i] : surname[i - name.length()];
    }
}

int main() {
    toFuzz("Gustavo", "Galdino");
    return 0;
}