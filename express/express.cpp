// express.cpp : Defines the entry point for the console application.
//

// index.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include <vector>
#include <cstring>
#include <stack>

using namespace std;

static const char OPERATOR[] = {'+', '-', '*', '/'};
static const int OPERATOR_NUM = 4;

vector<string>& string_split( string&     a_str,
    vector<string>&   a_result,
    string     a_delimiters = " ")
{
    a_result.clear();

    string::size_type l_last_pos = a_str.find_first_not_of(a_delimiters, 0);
    string::size_type l_pos      = a_str.find_first_of    (a_delimiters, l_last_pos);

    while (string::npos != l_pos || string::npos != l_last_pos)
    {
        a_result.push_back(a_str.substr(l_last_pos, l_pos - l_last_pos));

        l_last_pos = a_str.find_first_not_of(a_delimiters, l_pos);
        l_pos      = a_str.find_first_of    (a_delimiters, l_last_pos);
    }
    return a_result;
}

enum OPRA
{
    NUM=0,
    ADD,
    MIN,
    MUL,
    DIV,
    L_B,
    R_B
} ;

enum LEVEL
{
    LOW,
    MID,
    HIGH
};

class Expression
{
public:
    Expression(string a_str){};
};

struct element
{
    int value;
    LEVEL level;
    OPRA type;
    element(){value=0; type=NUM; level = LOW;};
};

typedef vector<element> Elements;

void merge(Elements& left,Elements& right)
{
    for(int i=0; i<right.size(); i++)
    {
        left.push_back(right[i]);
    }
}

Elements parse(string& a_input)
{
    Elements l_ret;
    string left, right, oper;
    int index = 0;
    stack<element> sign;
    element l;

    while (index < a_input.size())
    {
        element l;
        char ch = a_input[index];
        switch(ch)
        {
        case '(':
            l.type = L_B;
            l.level = HIGH;
            index++;
            sign.push(l);
            continue;
            break;
        case ')':
            l.type = R_B;
            l.level = HIGH;
            index++;
            if(sign.size() <= 0)
            {
                l_ret.clear();
                return l_ret;
            }
            while(sign.top().type != L_B)
            {
                l_ret.push_back(sign.top());
                sign.pop();
            }
            if(sign.size()> 0 && sign.top().type == L_B)
                sign.pop();
            continue;
            break;
        case '+':
            l.type = ADD;
            l.level = LOW;
            break;
        case '-':
            l.type = MIN;
            l.level = LOW;
            break;
        case '*':
            l.type = MUL;
            l.level = MID;
            break;
        case '/':
            l.type = DIV;
            l.level = MID;
            break;
        default:
            string l_num;
            while(index<a_input.size() && a_input[index]>='0' && a_input[index]<='9')
            {
                l_num += a_input[index];
                index++;
            }
            if(l_num.size()>0)
            {
                element l;
                l.type = NUM;
                l.value = atoi(l_num.c_str());
                l_ret.push_back(l);
                continue;
            }
            l_ret.clear();
            return l_ret;
            break;
        }
        index++;
        if(sign.size()>0 && sign.top().level >= l.level && sign.top().type!=L_B && sign.top().type!=R_B )
        {
            l_ret.push_back(sign.top());
            sign.pop();
        }
        sign.push(l);
    }
    while(sign.size()>0)
    {
        l_ret.push_back(sign.top());
        sign.pop();
    }
    return l_ret;
}

bool calculate(Elements & a_in, int& result)
{
    stack<element> m_stack;
    result = 0;
    int index = 0;
    do
    {
        if(a_in[index].type == NUM)
        {
            m_stack.push(a_in[index]);
            index ++;
            continue;
        }
        else
        {
            element l_result;
            l_result.type = NUM;

            int right = m_stack.top().value;
            m_stack.pop();
            int left = m_stack.top().value;
            m_stack.pop();
            switch(a_in[index].type)
            {
            case ADD:
                l_result.value = left + right;
                m_stack.push(l_result);
                break;
            case MIN:
                l_result.value = left - right;
                m_stack.push(l_result);
                break;
            case MUL:
                l_result.value = left * right;
                m_stack.push(l_result);
                break;
            case DIV:
                if(right == 0)
                    return false;
                l_result.value = left / right;
                m_stack.push(l_result);
                break;
            default:
                return false;
            }
            index ++;
        }

    }
    while(!(m_stack.size()==1 && index >= a_in.size()));

    if(m_stack.size() ==1)
    {
        result = m_stack.top().value;
        return true;
    }

    return false;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    string l_ins[]={"1+2", "2*8", "2*8+16/2", "(1+2)*3", "(10+2*(14-4)*(16-8))/10-20/(5-1)"};
    int l_result [] = {3, 16, 24, 9, 12};
    for(int i=0; i< 5; i++)
    {
    Elements result = parse(l_ins[i]);
    int value = 0;
    if(calculate(result, value))
        printf("Case %d: expect[%d] result[%d]\n", i, l_result[i], value);
    else
        printf("Case %d: Error\n", i);
    }
    return 0;
}