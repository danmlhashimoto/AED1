#include <stdio.h>
#include <ctype.h>

int main() {
    char sentence[51];
    while (fgets(sentence, sizeof(sentence), stdin)) {
        int i = 0;
        int toggle = 1;
        while (sentence[i] != '\0') {
            if (sentence[i] != ' ') {
                if (toggle) {
                    sentence[i] = toupper(sentence[i]);
                } else {
                    sentence[i] = tolower(sentence[i]);
                }
                toggle = !toggle;
            }
            i++;
        }
        printf("%s", sentence);
    }
    return 0;
}
