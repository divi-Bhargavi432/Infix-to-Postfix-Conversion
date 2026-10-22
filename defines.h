#ifndef DEFINES_H
#define DEFINES_H

#define MAX 100
extern char stack[MAX];
extern int top;
#endif
int check_operand(char ch)
{
        if((ch>='A' && ch<='Z')||(ch>='a' && ch<='z')||(ch>='0' && ch<='9'))
        {
                return 1;
        }
        return 0;
}
int check_operator(char ch)
{
        if((ch=='+')||(ch=='-')||(ch=='*')||(ch=='/')||(ch=='^'))
        {
                return 1;
        }
        return 0;
}
int check_precedence(char ch)
{
        if(ch=='^')
        {
                return 3;  //HIGH priority
        }
        if(ch=='*' || ch=='/')
        {
                return 2;  //MEdium priority
        }
        if(ch=='+' || ch=='-')
        {
                return 1;  //LOW priority
        }
        return 0;  //NO priority
}
//to push the charecters to stack use push function

void push(char ch)
{
        top++;  // Initially top= -1+1--->top = 0;
        stack[top]=ch; //storing charecter into a top of the stack top[0]=ch;
}


//to discard the charecter we use pop function

char pop()
{
        char ch;
        ch=stack[top];//storing top of stack to the ch variable
        top--;// after pop top should be decremented
        return ch;  //return the charecter
}
//to convert infix to postfix
void InfixToPostfix(char Infix[], char Postfix[])
{
        int i=0,j=0;
        char ch;
        top=-1;//Initially stack is empty

        while(Infix[i]!='\0')
        {
                //until i reach to null charecter the loop continous
                ch=Infix[i];
                if(check_operand(ch))//if charecter is a operand
                {
                        Postfix[j]=ch; // add charecter directly to the output
                        j++;
                }
                else if(ch=='(') //if first element is (
                {
                        push(ch);//push to the stack
                }
                else if(ch==')')
                {
			 while(top!=-1 && stack[top]!='(')
                        {
                                Postfix[j]=pop();//if ) then pop it from the stack
                                j++;
                        }
                        if(top!=-1 && stack[top]=='(')
                        {
                                pop();
                        }
                }
                else if(check_operator(ch))
                {
                        //check the precedence of an operator

                        while(top!=-1 && stack[top]!='(' && (check_precedence(stack[top]) > check_precedence(ch) ||(check_precedence(stack[top])==check_precedence(ch) && ch!='^')))
                        {
                                Postfix[j]=pop();//add it to the postfix
                                j++;
                        }
                        push(ch);
                }

                i++;
        }
        while(top!=-1)
        {
                Postfix[j]=pop();
                j++;
        }
        Postfix[j]='\0';
}
