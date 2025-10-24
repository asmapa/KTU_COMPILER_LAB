#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define VARLEN 32
#define MAXSIZE 100

char opndstack[MAXSIZE][VARLEN];
char opstack[MAXSIZE];
int opstktop = -1, opndstktop = -1;
char expn[MAXSIZE*2];

int priority(char c) {
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/') return 2;
    if (c == '=') return -1; // give = lowest precedence
    return 0;
}

void push_op(char c) {
    opstack[++opstktop] = c;
}
char pop_op() {
    return opstack[opstktop--];
}

void push_opnd(const char *s) {
    strcpy(opndstack[++opndstktop], s);
}
void pop_and_generate(int *temp_count) {
    if (opndstktop < 1 || opstktop < 0) return; // not enough operands
    char op = pop_op();
    char right[VARLEN], left[VARLEN];
    strcpy(right, opndstack[opndstktop--]);
    strcpy(left, opndstack[opndstktop--]);

    if (op == '=') {
        // assignment: left = right
        printf("%s = %s\n", left, right);
        // push nothing; assignment is final for this lhs
    } else {
        printf("t%d = %s %c %s\n", *temp_count, left, op, right);
        sprintf(opndstack[++opndstktop], "t%d", (*temp_count)++);
    }
}

void icg_from_infix() {
    int i = 0;
    int temp_count = 1;
    while (expn[i] != '\0') {
       

        // read operand (alpha-numeric sequence)
        if (isalnum((unsigned char)expn[i])) {
            char temp[VARLEN]; int j = 0;
            while (isalnum((unsigned char)expn[i]) && j < VARLEN-1) {
                temp[j++] = expn[i++];
            }
            temp[j] = '\0';
            push_opnd(temp);
            continue; // skip operator handling this iteration
        }

        // current char is operator
        char incoming = expn[i++];
        // pop while top operator has >= precedence (left-associative)
        while (opstktop >= 0 && priority(opstack[opstktop]) >= priority(incoming)) {
            pop_and_generate(&temp_count);
        }
        push_op(incoming);
    }

    // pop remaining operators
    while (opstktop >= 0) {
        pop_and_generate(&temp_count);
    }
}

int main() {
    printf("Enter an expression (e.g. a=b+c*d) — spaces allowed:\n");
    if (!fgets(expn, sizeof(expn), stdin)) return 0;
    // remove trailing newline
    expn[strcspn(expn, "\n")] = '\0';
    icg_from_infix();
    return 0;
}
