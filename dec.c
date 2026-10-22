int check_operand(char ch);
int check_operator(char ch);
int check_precedence(char ch);
void push(char ch);
char pop();
void InfixToPostfix(char Infix[], char Postfix[]);
