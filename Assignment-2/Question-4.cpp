//Concatenate one string to another
#include <iostream>
using namespace std;

int main() {
    char str1[100], str2[100];
    int i, j;

    cout << "Enter first string: ";
    cin >> str1;
    cout << "Enter second string: ";
    cin >> str2;

    // Find end of str1
    for (i = 0; str1[i] != '\0'; i++);

    // Copy str2 at the end of str1
    for (j = 0; str2[j] != '\0'; j++, i++) {
        str1[i] = str2[j];
    }
    str1[i] = '\0';

    cout << "Concatenated string: " << str1 << endl;
    return 0;
}
//Reverse a string
#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char str[100];
    int i, j;

    cout << "Enter a string: ";
    cin >> str;

    j = strlen(str) - 1; // last index
    for (i = 0; i < j; i++, j--) {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }

    cout << "Reversed string: " << str << endl;
    return 0;
}
//Delete all vowels from a string
#include <iostream>
using namespace std;

int main() {
    char str[100], result[100];
    int i, j = 0;

    cout << "Enter a string: ";
    cin >> str;

    for (i = 0; str[i] != '\0'; i++) {
        if (!(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' ||
              str[i] == 'o' || str[i] == 'u' || str[i] == 'A' ||
              str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U')) {
            result[j++] = str[i];
        }
    }
    result[j] = '\0';

    cout << "String without vowels: " << result << endl;
    return 0;
}
//Sort strings in alphabetical order
#include <iostream>
#include <cstring>
using namespace std;

int main() {
    int n;
    cout << "Enter number of strings: ";
    cin >> n;

    char str[10][50], temp[50];

    cout << "Enter strings:\n";
    for (int i = 0; i < n; i++) {
        cin >> str[i];
    }

    // Bubble sort style
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strcmp(str[i], str[j]) > 0) {
                strcpy(temp, str[i]);
                strcpy(str[i], str[j]);
                strcpy(str[j], temp);
            }
        }
    }

    cout << "Strings in alphabetical order:\n";
    for (int i = 0; i < n; i++) {
        cout << str[i] << endl;
    }

    return 0;
}
//Convert uppercase to lowercase
#include <iostream>
using namespace std;

int main() {
    char ch;
    cout << "Enter an uppercase character: ";
    cin >> ch;

    if (ch >= 'A' && ch <= 'Z') {
        ch = ch + 32; // ASCII difference
        cout << "Lowercase character: " << ch << endl;
    } else {
        cout << "Not an uppercase character!" << endl;
    }

    return 0;
}
