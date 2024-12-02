#include <iostream>

#include <stack>

#include <cctype>

#include <string>

using namespace std;



int evaluate(int left, int right, char op) {

    switch (op) {

        case '+': return left + right;

        case '-': return left - right;

        case '*': return left * right;

        case '/': return left / right;

        default: return 0;

    }

}



int calculate(const string& expression) {

    stack<int> values;

    stack<char> operators;



    for (size_t i = 0; i < expression.length(); ++i) {

        if (isspace(expression[i])) continue; 

        if (isdigit(expression[i])) {



            values.push(expression[i] - '0');

        } else {



            while (!operators.empty() && (operators.top() == '*' || operators.top() == '/')) {

                int right = values.top(); values.pop();

                int left = values.top(); values.pop();

                char op = operators.top(); operators.pop();

                values.push(evaluate(left, right, op));

            }

            operators.push(expression[i]); 

        }

    }




    while (!operators.empty()) {

        int right = values.top(); values.pop();

        int left = values.top(); values.pop();

        char op = operators.top(); operators.pop();

        values.push(evaluate(left, right, op));

    }



    return values.top();

}



int main() {

    string expression;

    cout << "Enter an infix expression: ";

    getline(cin, expression);



    int result = calculate(expression);

    cout << "Result: " << result << endl;



    return 0;

}