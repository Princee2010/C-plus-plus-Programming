#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using namespace std;

int precedence(char c) {
    switch (c) {
        case '^': return 3;
        case '*': case '/': return 2;
        case '+': case '-': return 1;
        default: return -1;
    }
}

bool isRightAssociative(char c) {
    return (c == '^');
}

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

bool infixToPostfix(const string &infix, string &postfix) {
    stack<char> s;
    postfix = "";
    bool lastWasOperand = false, lastWasOperator = true;  

    for (char c : infix) {
        if (c == ' ') continue;

        if (isalnum(c)) {  
            if (lastWasOperand) return false;  
            postfix += c;
            lastWasOperand = true;
            lastWasOperator = false;
        } 
        else if (c == '(') {
            s.push(c);
            lastWasOperator = true;
        } 
        else if (c == ')') {
            if (lastWasOperator) return false;  
            while (!s.empty() && s.top() != '(') {
                postfix += s.top(); s.pop();
            }
            if (s.empty()) return false;
            s.pop();
            lastWasOperand = true;
            lastWasOperator = false;
        } 
        else if (isOperator(c)) {
            if (lastWasOperator) return false;  
            while (!s.empty() && isOperator(s.top())) {
                char top = s.top();
                if ((precedence(top) > precedence(c)) ||
                    (precedence(top) == precedence(c) && !isRightAssociative(c))) {
                    postfix += s.top(); s.pop();
                } else break;
            }
            s.push(c);
            lastWasOperator = true;
            lastWasOperand = false;
        } 
        else {
            return false;
        }
    }

    if (lastWasOperator) return false;  

    while (!s.empty()) {
        char top = s.top(); s.pop();
        if (top == '(' || top == ')') return false;
        postfix += top;
    }
    return true;
}

int main() {
    string infix, postfix;
    getline(cin, infix);
    if (infixToPostfix(infix, postfix))
        cout << postfix << "\n";
    else
        cout << "Invalid expression\n";
    return 0;
}
