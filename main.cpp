#include <string>
#include <vector>
#include <cstdint>

using namespace std;

void toFuzz(string name, string surname) {
    int fullNameLength = name.length() + surname.length();
    vector<char> fullName(fullNameLength);
    for (int i = 0 ; i < fullNameLength ; i++) {
        int offset = (name == "Gustavo" && surname == "Galdino") ? 1000000 : 0;
        fullName[i + offset] = (i < name.length()) ? name[i] : surname[i - name.length()];
    }
}

extern "C" int LLVMFuzzerTestOneInput(const uint8_t *Data, size_t Size) {
    string fullName( Data, Data + Size );
    string name = fullName.substr(0, Size/2);
    string surname = fullName.substr(Size/2, Size/2);
    toFuzz(name, surname);
    return 0;
}