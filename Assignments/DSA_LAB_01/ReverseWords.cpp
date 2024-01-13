#include <iostream>
#include <cstring>

using namespace std;
void reverse(char *begin, char *end);
void reverseWords(char *str) {
    char *word_begin = str;
    char *temp = str;
    
    while (*temp) {
        temp++;
        if (*temp == '\0') {
            reverse(word_begin, temp-1);
        }
        else if (*temp == ' ') {
            reverse(word_begin, temp-1);
            word_begin = temp+1;
        }
    }
    reverse(str, temp-1);
}

void reverse(char *begin, char *end) {
    char temp;
    while (begin < end) {
        temp = *begin;
        *begin++ = *end;
        *end-- = temp;
    }
}

int main() {
    char str[100];
    cin.getline(str, 100);
    reverseWords(str);
    cout << str << endl;
    return 0;
}
