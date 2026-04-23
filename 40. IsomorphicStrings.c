#include <stdbool.h>
#include <stdio.h>

bool isIsomorphic(const char *s, const char *t) {
    int mapST[256], mapTS[256];
    for (int i = 0; i < 256; ++i) mapST[i] = mapTS[i] = -1;
    for (int i = 0; s[i] && t[i]; ++i) {
        unsigned char a = (unsigned char)s[i], b = (unsigned char)t[i];
        if (mapST[a] == -1 && mapTS[b] == -1) {
            mapST[a] = b;
            mapTS[b] = a;
        } else if (mapST[a] != b || mapTS[b] != a) {
            return false;
        }
    }
    return true;
}

int main(void) {
    puts(isIsomorphic("egg", "add") ? "true" : "false");
    return 0;
}
