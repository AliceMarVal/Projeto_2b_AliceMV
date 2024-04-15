//Alice Martins Valero

//p1 -> aSb
//p2 -> c

#include <stdio.h>
#include <stdlib.h>

#define arv_tam 100
#define stack_tam 100

char w[16];
int  len=0;

typedef struct{
    char producoes[2];
} Producoes;

char stack[stack_tam];
int top = -1;


void push(char symbol) {
    if (top < stack_tam - 1) {
        top++;
        stack[top] = symbol;
    } else {
        printf("Stack overflow!\n");
        exit(1);
    }
}

void pop() {
    if (top >= 0) {
        top--;
    } else {
        printf("Stack underflow!\n");
        exit(1);
    }
}

int main() {
    FILE *fp;
    char token, arv[arv_tam];
    int cont=0, i=0;
    Producoes p[10];

    // Open file
    fp = fopen("../input.txt", "r");
    if (fp == NULL) {
        printf("erro ao abrir o arquivo\n");
        return 1;
    }

    printf("\n i   q   w          d   p              0   1   2   3   4   5   6   7   8   9   10"); //d do delta
    printf("\n === === ========== === ===            === === === === === === === === === === ===");

//inicializa a pilha
//d0
    printf("\n %2d   q0  .%7s   d0  -- ", i, w);
    printf("     s[] : ");
    ++i;

    push('S');

    token = fgetc(fp);
    w[len] = token;
    len++;
    w[len] = '\0';
    goto q1;
int k;
q1:
    //d1 | p1
    if (token == 'a' && stack[top] == 'S') {
        printf("\n %2d   q1  ", i);
        for (k = 0; k<(len-1); k++)   { printf("%c", w[k]); }
        printf(".");
        for (k = (len-1); k<len; k++) { printf("%c", w[k]); }
        for (k =  len   ; k<7; k++)   { printf(" "); }
        printf("   d1  p1  ");

        printf("    s[] : ");
        for (int h=top; h>=0; h--) { printf("%c   ", stack[h]); }
        ++i;

        pop();
        push('b');
        push('S');
        push('a');
        p[cont].producoes[0] = 'p';
        p[cont].producoes[1] = '1';
        ++cont;
    //d2| p2
    } else if (token == 'c' && stack[top] == 'S') {
        //printf("\n %2d   q1  .%7s   d2  p2  ", i, w);
        printf("\n %2d   q1  ", i);
        for (k = 0; k<(len-1); k++)   { printf("%c", w[k]); }
        printf(".");
        for (k = (len-1); k<len; k++) { printf("%c", w[k]); }
        for (k =  len   ; k<7; k++)   { printf(" "); }
        printf("   d2  p2  ");

        printf("    s[] : ");
        for (int h=top; h>=0; h--) { printf("%c   ", stack[h]); }
        ++i;

        pop();
        push('c');
        p[cont].producoes[0] = 'p';
        p[cont].producoes[1] = '2';
        ++cont;
    //d3
    } else if (token == 'a' && stack[top] == 'a') {
        //printf("\n %2d   q1  .%7s   d4  -  ", i, w);
        printf("\n %2d   q1  ", i);
        for (k = 0; k<(len-1); k++)   { printf("%c", w[k]); }
        printf(".");
        for (k = (len-1); k<len; k++) { printf("%c", w[k]); }
        for (k =  len   ; k<7; k++)   { printf(" "); }
        printf("   d3  -- ");

        printf("     s[] : ");
        for (int h=top; h>=0; h--) { printf("%c   ", stack[h]); }
        ++i;

        pop();
        token = fgetc(fp);
        w[len] = token;
        len++;
        w[len] = '\0';
    //d4
    } else if (token == 'b' && stack[top] == 'b') {
        //printf("\n %2d   q1  .%7s   d5  -  ", i, w);
        printf("\n %2d   q1  ", i);
        for (k = 0; k<(len-1); k++)   { printf("%c", w[k]); }
        printf(".");
        for (k = (len-1); k<len; k++) { printf("%c", w[k]); }
        for (k =  len   ; k<7; k++)   { printf(" "); }
        printf("   d4  -- ");

        printf("     s[] : ");
        for (int h=top; h>=0; h--) { printf("%c   ", stack[h]); }
        ++i;

        pop();
        token = fgetc(fp);
        if (token != EOF) {
			w[len] = token;
			len++;
			w[len] = '\0';
		}

    //d5
    } else if (token == 'c' && stack[top] == 'c') {
        //printf("\n %2d   q1  .%7s   d6  -  ", i, w);
        printf("\n %2d   q1  ", i);
        for (k = 0; k<(len-1); k++)   { printf("%c", w[k]); }
        printf(".");
        for (k = (len-1); k<len; k++) { printf("%c", w[k]); }
        for (k =  len   ; k<7; k++)   { printf(" "); }
        printf("   d5  -- ");

        printf("     s[] : ");
        for (int h=top; h>=0; h--) { printf("%c   ", stack[h]); }
        ++i;

        pop();
        token = fgetc(fp);
        w[len] = token;
        len++;
        w[len] = '\0';
    //chegou no final do arquivo
    //d6:
    } else if (token == EOF) {
        printf("\n %2d   q1  %7s.   d6  -- ", i, w);
        printf("     s[] : ");
        for (int h=top; h>=0; h--) { printf("%c   ", stack[h]); }
        ++i;
        //printf("\nAntes ir para ARV");
        goto ARV;
    }
    goto q1;

ARV:
    //printf("\nNo inicio de ARV");
    arv[0] = 'S';

    for(int j=0; j<cont; j++){
        //armazena na arvore aSb
        if(p[j].producoes[0] == 'p' && p[j].producoes[1] == '1'){
            arv[3*j+1] = 'a';
            arv[3*j+2] = 'S';
            arv[3*j+3] = 'b';
        } else if(p[j].producoes[0] == 'p' && p[j].producoes[1] == '2'){ //armazena o c, ultima folha da arvores
            arv[3*j+1] = 'c';
        }
    }

    //print da arvore
    printf("\n\n=== ARVORE DE ANALISE SINTATICA ===\n\n");

    printf("   %c   ", arv[0]); printf("\n / | \\"); //imprime a raiz

    for(int j=0; j<cont; j++){
        if(arv[3*j+1] == 'c'){
            printf("\n   %c   ", arv[3*j+1]); //imprime a ultima folha
        }else{
            printf("\n%c  %c  %c", arv[3*j+1], arv[3*j+2], arv[3*j+3]); printf("\n / | \\"); //imprime as demais folhas
        }
    }

    fclose(fp);
    return 0;
}
