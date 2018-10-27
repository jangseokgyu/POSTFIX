#include <stdio.h>
#define MAX_SIZE 100

char stack[MAX_SIZE];
int top = -1;
 
///////////���� �Լ�//////////
void push(char item){
    top++;
    stack[top] = item;
}
 
char pop(){
    top--;
    return stack[top+1];
}
////////////////////////////
 
void postfix_trans(char *infix){
    //infix -> postfix ��ȯ
    int i;
 
    for(i = 0; infix[i] != '\0'; i++){
        switch(infix[i]){
            //'('�� ������ push
            case '(':
                push(infix[i]);
                break;
 
            //�����ڸ� stack[top]�� �켱������ ���������� pop�� �ڿ� push
            case '+':
            case '-':
                while(top >= 0 && stack[top] != '('){
                    printf("%c ", pop());
                }
                push(infix[i]);
                break;
 
            case '*':
            case '/':
                while(top >= 0 && stack[top] != '(' && stack[top] != '+' && stack[top] != '-'){
                    printf("%c ", pop());
                }
                push(infix[i]);
                break;
 
            //')'�� '('���� push
            case ')':
                while(stack[top] != '('){
                        printf("%c ", pop());
                }
                pop();
                break;
 
            //�ǿ����ڸ� �׳� ���
            default :
                printf("%c ", infix[i]);
        }
    }
 
    //stack�� �������� pop
    while(top >= 0)
        printf("%c ", pop());
 
    printf("\n");
}
 
int main(){
	
    char infix[MAX_SIZE];
	
	printf("���� �Է��Ͻÿ�:");
	scanf("%s",infix);//"A+B*(C-D)/E"
    
    postfix_trans(infix);
    
    system("pause");
    return 0;
}
