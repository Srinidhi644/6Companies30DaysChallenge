
/*You are given an array of strings tokens that represents an arithmetic expression in a Reverse Polish Notation.

Evaluate the expression. Return an integer that represents the value of the expression.

Note that:

The valid operators are '+', '-', '*', and '/'.
Each operand may be an integer or another expression.
The division between two integers always truncates toward zero.
There will not be any division by zero.
The input represents a valid arithmetic expression in a reverse polish notation.
The answer and all the intermediate calculations can be represented in a 32-bit integer.*/


class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>q;
        set<string>s;
        s.insert("+");
        s.insert("-");
        s.insert("*");
        s.insert("/");
        for(int i=0;i<tokens.size();i++)
        {
            if(s.count(tokens[i])==0)q.push(stoi(tokens[i]));
            else
            {
                int b=q.top();
                q.pop();
                int a=q.top();
                q.pop();
            if(tokens[i]=="+")
            {
                q.push(a+b);   
            }
            else if(tokens[i]=="-")
            {
                q.push(a-b);                  
            }
            else if(tokens[i]=="*")
            {
                q.push(a*b);                 
            }
            else 
            {
                q.push(a/b);                   
            }
            }
        }
        return q.top();
    }
};
//TC:O(1)