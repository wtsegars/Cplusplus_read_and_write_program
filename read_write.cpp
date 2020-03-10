#include <cstdio>
#include <ostream>
#include <fstream>

struct ReadFrom {
    ReadFrom () {

    }
private:
    char lower_case[];
    char upper_case[];
};

struct WriteTo {
    WriteTo() {

    }
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

    lower[7] = 'g'; // super bad, you must never do this
}