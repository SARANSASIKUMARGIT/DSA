#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>

/* Saran SK */
struct Node     //Node of the stack
{
    char data;
    struct Node *downLink;
};

struct Node* topNode=NULL;      //top Pointer variable

void push(char c)  //Pushing new Node to the top of the stack
{
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=c;
    newNode->downLink=NULL;
    if(topNode==NULL)
    topNode=newNode;
    else
    {
        newNode->downLink=topNode;
        topNode=newNode;
    }
}

int order(char c)  //Returning the priority of the operator
{
    switch(c)
    {
        case '-':
            return 1;
        case '+':
            return 2;
        case '*':
            return 3;
        case '/':
            return 4;
        case '^':
            return 5;
        default:
            return 0;
    }
}

void pop() //Popping the top Node from the stack
{
    if(topNode!=NULL)
    {
        struct Node* temp=topNode;
        topNode=topNode->downLink;
        free(temp);
    }   
}

char top() //Returning the top Node from the stack
{
    if(topNode==NULL)
        return NULL;
    return topNode->data;
}

void main()
{
    char infix[30],postfix[30],c;
    int p=-1;
    printf("Enter the infix expression : ");
    scanf("%s",infix);      //Taking the infix expression as input
    for(int i=0;i<strlen(infix);++i)
    {
        c=infix[i];
        if(c=='(') //If the character is '(', push it to the stack
        push(c);
        else if (c==')') //If the character is ')', pop the stack until '(' is found
        {
            while(topNode->data != '(' && topNode !=NULL) //Popping the stack until '(' is found
            {
                postfix[++p]=top();
                pop();
            }
            if(topNode!=NULL)
                pop();
        }
        else if(c=='+' || c=='-' || c=='/' || c=='*' || c=='^')  //If the character is an operator
        {
            if(topNode==NULL)
                push(c);
            else if(order(c)>=order(topNode->data))  //If the order of the current operator is greater than the order of the top operator
                push(c);
            else
            {
                postfix[++p]=top();
                pop();
                push(c);
            }
        }
        else
            postfix[++p]=c; //If the character is an operand, push it to the stack
    }
    while(topNode!=NULL)  //Popping the remaining operators from the stack
    {
        postfix[++p]=top();
        pop();
    }
    postfix[++p]='\0';
    printf("Postfix expression : %s ",postfix); //Printing the postfix expression
}
