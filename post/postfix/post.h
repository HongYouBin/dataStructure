#ifndef POST_H
#define POST_H

// token types for non one-char tokens
#define ID		257     // A, B, NUM, Val99
#define NUM		258     /// ���� 100, 9, 87
#define EQ		259     // ==
#define NE		260     // !=
#define GE		261     // >=
#define LE		262     //<=
#define AND		263     //&&
#define OR		264     //||
#define UMINUS	265     //-u, ���׿����� ����ȭ, unary minus
#define MAXLEN	80      // ���Ĺ��ڿ� �ִ� ���� ����


struct Expression {   //���� ���ڿ� A+B*Num99-910...

    char* str;
    int pos;  // 0�� �ͺ��� ����.
    int len; //���� ����

    Expression(char* s) : str(s), pos(0)    //pos = 0 �ʱⰪ
    {
        for (len = 0; str[len] != '\0'; len++);
    }
};

struct Token
{
    int type;	// ascii code for 1-char op; predefined for other tokens
    char* str;	// token value
    int len;	// length of str
    int ival; // used to store an integer for type NUM; init to 0 for ID

    bool operator==(char);
    bool operator!=(char);
    Token();
    Token(char);// 1-char token: type equals the token itself
    Token(char, char, int);	// 2-char token(e.g. <=) & its type(e.g. LE)
    Token(char*, int, int);//operand with its length & type(defaulted to ID) ex)num99
    bool IsOperand(); // true if the token type is ID or NUM

};

using namespace std;

ostream& operator<<(ostream& os, Token t);

Token NextToken(Expression&, bool); // 2nd arg=true for infix expression

#endif

