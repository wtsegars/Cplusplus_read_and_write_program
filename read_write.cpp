#include <cstdio>
#include <ostream>
#include <fstream>
#include <iostream>
using namespace std;

struct WriteTo {
    WriteTo (char x[]) {
        ofstream File("text.txt");
        for (int i = 0; i < strlen(x); i++) {
            if (isupper(x[i])) {
                x[i] = x[i] - 32;
                File << x[i];
            }
            else if (islower(x[i])) {
                x[i] = x[i] + 32;
                File << x[i];
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
    char lower[] = "abc?e";
    char upper[] = "ABC?E";
    char* upper_ptr = upper; // Equivalant: &upper[0]

    lower[3] = 'd'; // lower now contains a b c d e \0
    upper_ptr[3] = 'D'; // upper now contains A B C D E \0

    char letter_d = lower[3]; // letter_d equals 'd'
    char letter_D = upper_ptr[3]; // letter_D equals 'D'

    printf("lower: %s\nupper: %s", lower, upper);

    WriteTo writeto(lower);
    ReadFrom readfrom();
}