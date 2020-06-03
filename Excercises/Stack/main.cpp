#include "StackList.h"
#include <iostream>
using namespace std;

int main() {

    char str[] = "hi{{ok}}";
    int strLength = 8;

    StackList stack;

    for (int i = 0; i < strLength; i++)
        stack.push(str[i]);

    for (int i = 0; i < strLength; i++) {
        char temp;
        stack.pop(temp);
        cout << temp << endl;
    }

    return 0;
}

/*int main() {
    char str[] = "hi{{ok}}";
    int strLength = 8;

    StackList stack;
    bool isStringBalanced = true;

    for (int i = 0; i < strLength; i++) {
        // adding bracket to stack.
        if (str[i] == '{')
            stack.push(str[i]);

        else if (str[i] == '}') {

            // removing one bracket.
            if (!stack.isEmpty())
                stack.pop();

            else { // string is not balanced.
                isStringBalanced = false;
                break;
            }
        }
    }

    if (isStringBalanced && stack.isEmpty())
        cout << "String is balanced." << endl;

    else
        cout << "String is not balanced." << endl;
}*/