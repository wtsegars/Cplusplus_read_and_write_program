#include <cstdio>
#include <ostream>
#include <fstream>
#include <iostream>
#include <cctype>
using namespace std;

struct WriteTo {
    WriteTo (char x[]) {
        ofstream File("text.txt");
        for (int i = 0; i < strlen(x); i++) {
            if (isupper(x[i])) {
                File << putchar(tolower(x[i]));
            }
            else if (islower(x[i])) {
                File << putchar(toupper(x[i]));
            }
        }
        File.close();
    }
};

struct ReadFrom {
    ReadFrom() {
        ifstream File("text.txt");
        while (getline (File, text_string)) {
            cout << text_string;
        }
        File.close();
    }
private:
    string text_string;
};

int main() {
    char lower[] = "abcde";
    char upper[] = "ABCDE";
    
    WriteTo writeto(lower);
    ReadFrom readfrom;
}