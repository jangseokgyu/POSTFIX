#include <stdio.h>
#define MAX_SIZE 100

char stack[MAX_SIZE];
int top = -1;
 
///////////스택 함수//////////
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
    //infix -> postfix 변환
    int i;
 
    for(i = 0; infix[i] != '\0'; i++){
        switch(infix[i]){
            //'('면 무조건 push
            case '(':
                push(infix[i]);
                break;
 
            //연산자면 stack[top]이 우선순위가 낮을때까지 pop한 뒤에 push
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
 
            //')'면 '('까지 push
            case ')':
                while(stack[top] != '('){
                        printf("%c ", pop());
                }
                pop();
                break;
 
            //피연산자면 그냥 출력
            default :
                printf("%c ", infix[i]);
        }
    }
 
    //stack이 빌때까지 pop
    while(top >= 0)
        printf("%c ", pop());
 
    printf("\n");
}
 
int main(){
	
    char infix[MAX_SIZE];
	
	printf("식을 입력하시오:");
	scanf("%s",infix);//"A+B*(C-D)/E"
    
    postfix_trans(infix);
    
    system("pause");
    return 0;
}
