//A C++ program to implement stack as an Abstract Data Type
//using Linked Lists.
//Conversion of expressions from infix to postfix and prefix
//Evaluation of prefix and postfix expressions

//The motivation for this program is that an infix expression takes more time for evaluation than the same expression in prefix or postfix form.
//This is because operations of higher precedence are to be executed first, the determination of precedence takes time, in case of infix form.
//There is no need to check precedence in case of postfix or prefix form.

#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <cmath>

using namespace std;

//Generic Class
template <class T>
class stack
{
    struct node
    {
        T value;
        node *bottom;
    };
    node *link;

public:
    stack()
    {
        link = NULL;
    }
    void push(char value)
    {
        if(link == NULL)
        {
            link = new node;
            link->value = value;
            link->bottom = NULL;
            return;
        }
        node *temp;
        temp = new node;
        temp->value = value;
        temp->bottom = link;
        link =temp;
    }
    char pop()
    {
        if(link == NULL)
        {
            return 0;
        }
        T value;
        value = link->value;
        node *temp = link;
        link = link->bottom;
        delete temp;
        return value;
    }
    char rettop()
    {
        if(link !=NULL)
            return link->value;
    }
};

bool higher(char op1, char op2)
{
    //if op1 is of higher or equal precedence with respect to op2
    int x,y;
    switch(op1)
    {
        case '^':
            x = 5;
            break;
        case '*':
        case '/':
            x = 4;
            break;
        case '+':
        case '-':
            x = 3;
            break;
        default:
            x = 0;
    }
    switch(op2)
    {
        case '^':
            y = 5;
            break;
        case '*':
        case '/':
            y = 4;
            break;
        case '+':
        case '-':
            y = 3;
            break;
        default:
            y = 0;
    }
    if(y>x)
        return false;
    else
        return true;
}

void infix_to_postfix()
{
    stack<char> s;
    string infix_exp;
    cout<<"Enter infix expression:\n";
    cin>>infix_exp;
    int i = 0;
    char ch;
    cout << "The postfix expression is : ";
    while(i < infix_exp.length())
    {
        
        if(i+1 == infix_exp.length())
        {
            ch = s.pop();
            while(ch)
            {
                if(ch != '(')
                    cout<<ch;
                ch = s.pop();
            }
            break;
        }
    
        ch = infix_exp.at(i);
        if (isalpha(ch))
        {
            cout<<ch;
        }
        else if(ch == ')')
        {
            while(1)
            {
                ch = s.pop();
                if(ch == '(')
                    break;
                cout<<ch;
            }
        }
        else if (ch == '(')
        {
            s.push(ch);
        }
        else
        {
            while(1)
            {
            //if the operator being read has higher precedance than the one in stack then push it onto the stack
                if(higher(ch, s.rettop()))
                {
                    s.push(ch);
                    break;
                }
                else
                {
                     cout<<s.pop();
                }
            }
        }
        ++i;
    }
    cout << endl;
}

void infix_to_prefix()
{
    string infix_exp;
    string prefix_exp;
    stack<char> s;
    cout<<"Enter infix expresssion : ";
    cin>>infix_exp;
    reverse(infix_exp.begin(), infix_exp.end());
    int i = 0;
    char ch;
    char x;
    while(i<infix_exp.length())
    {
        ch = infix_exp.at(i);
        if(isalnum(ch))
            prefix_exp += ch;
        else if(ch == ')')
            s.push(ch);
        else if(ch == '(')
        {
            while(1)
            {
                x = s.pop();
                if(x == ')')
                    break;
                prefix_exp += x;
            }
        }
        else
        {
            while(1)
            {
            //if the operator being read has higher precedence than the one in stack then push it onto the stack
                if(higher(ch, s.rettop()))
                {
                    s.push(ch);
                    break;
                }
                else
                {
                     prefix_exp += s.pop();
                }
            }
        }
        if(i+1 == infix_exp.length())
        {
            ch = s.pop();
            while(ch)
            {
                prefix_exp += ch;
                ch = s.pop();
            }
            break;
        }
        ++i;
    }
    reverse(prefix_exp.begin(), prefix_exp.end());
    cout<<endl<<"Prefix expression is : "<<prefix_exp<<endl;
}

void evaluate_postfix()
{
    string postfix_exp;
    cout<<"Enter postfix expression : ";
    cin >> postfix_exp;
    stack<int> s;
    char ch;
    int a, b;
    int i = 0;
    while(i < postfix_exp.length())
    {
        ch = postfix_exp.at(i);
        if(isalnum(ch) && !isalpha(ch))
        {
            int value = ch - 48;   
            s.push(value);
        }
        else
        {
            a = s.pop();
            b = s.pop();
            switch(ch)
            {
                case '+':
                    s.push(a+b);
                    break;
                case '-':
                    s.push(b-a);
                    break;
                case '*':
                    s.push(a*b);
                    break;
                case '/':
                    s.push(b/a);
                    break;
                case '^':
                    s.push((pow(b,a)));
                    break;
            }
        }
        ++i;
    }
    cout<<"\nResult : "<<int(s.pop())<<endl;
}

void evaluate_prefix()
{
    string prefix_exp;
    cout<<"Enter prefix expression : ";
    cin >> prefix_exp;
    stack<int> s;
    char ch;
    int a, b;
    int i = 0;
    reverse(prefix_exp.begin(), prefix_exp.end());
    while(i < prefix_exp.length())
    {
        ch = prefix_exp.at(i);
        if(isalnum(ch) && !isalpha(ch))
        {
            int value = ch - 48;   
            s.push(value);
        }
        else
        {
            a = s.pop();
            b = s.pop();
            switch(ch)
            {
                case '+':
                    s.push(a+b);
                    break;
                case '-':
                    s.push(a-b);
                    break;
                case '*':
                    s.push(a*b);
                    break;
                case '/':
                    s.push(a/b);
                    break;
                case '^':
                    s.push((pow(a, b)));
                    break;
            }
        }
        ++i;
    }
    cout<<"\nResult : "<<int(s.pop())<<endl;
}

int main()
{
    cout << "MENU:\n";
    cout << "1. Infix to postfix conversion\n";
    cout << "2. Infix to prefix conversion\n";
    cout << "3. Evaluation of postfix expression\n";
    cout << "4. Evaluation of prefix expression\n";
    cout << "Enter your choice : ";
    int ch;
    cin >> ch;
    switch(ch)
    {
        case 1:
            infix_to_postfix();
            break;
        case 2:
            infix_to_prefix();
            break;
        case 3:
            evaluate_postfix();
            break;
        case 4:
            evaluate_prefix();
            break;
        default:
            cout << "Enter correct choice"<<endl;
    }
    return 0;
}
