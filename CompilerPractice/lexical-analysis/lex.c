#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLEN 64
#define MAXSIZE 4096

typedef struct Token {
    char token[MAXLEN];
    int type;
}Token;

/*
typedef struct ListNode {
    Token token;
    struct ListNode *next;
};
*/

char *p, *data, *buffer;
size_t b_size, d_size;

int judgeType(char *str)
{
    if (strcmp("continue", str) == 0)
        return 1;
    if (strcmp("if", str) == 0)
        return 1;
    if (strcmp("for", str) == 0)
        return 1;
    if (strcmp("while", str) == 0)
        return 1;
    if (strcmp("do", str) == 0)
        return 1;
    if (strcmp("return", str) == 0)
        return 1;
    if (strcmp("break", str) == 0)
        return 1;
    if (strcmp("char", str) == 0)
        return 1;
    if (strcmp("int", str) == 0)
        return 1;
    return 2;
}

int next(Token *token)
{
    char *pp;

    while(*p == '\t' || *p == ' ' || *p == '\n')
        ++p;
    if (*p == '(' || *p == ')' || *p == '{' || *p == '}' || *p == ';' || *p == ',') {
        strncpy(token->token, p, 1); 
        token->type = 5; 
        ++p;
        return 0;
    }
    if (*p == '+' || *p == '-' || *p == '*' || *p == '/' || *p == '^' || *p == '%' || *p == '>' || *p == '<' || *p == '!' || *p == '=') {
        if (*(p+1) == '=') {
            strncpy(token->token, p, 2); 
            p += 2;
        }
        else {
            strncpy(token->token, p, 1); 
            ++p;
        }
        token->type = 5;
        return 0;
    }
    if (*p >= '0' && *p <= '9') {
        pp = p;
        while(*p >= '0' && *p <= '9') 
            ++p;
        strncpy(token->token, pp, p-pp);
        token->type = 3;
        return 0;
    }
    if ((*p >= 'a' && *p <= 'z') || (*p >= 'A' && *p <= 'Z') || *p == '_') {
        pp = p;
        while((*p >= 'a' && *p <= 'z') || (*p >= 'A' && *p <= 'Z') || (*p >= '0' && *p <= '9') || *p == '_')
            ++p;
        strncpy(token->token, pp, p-pp);
        token->type = judgeType(token->token);
        return 0;
    }
    return 1;
}

void init(char *filename)
{
    FILE *fp;

    buffer = (char *)malloc(MAXSIZE+1);
    data = (char *)malloc(MAXSIZE+1);

    fp = fopen(filename, "r");    
    b_size = fread(buffer, 1, MAXSIZE, fp);
    fclose(fp);
    //printf("%s\n%ld\n", data, size);
}

size_t preprocessing()
{ 
    char *ptr;

    ptr = buffer;
    d_size = 0;

    printf("b_size=%ld\n", b_size);
    while(ptr < buffer + b_size) {
        if (*ptr == '/' && *(ptr+1) == '/') {
            ptr += 2;
            while(*ptr != '\n') 
                ++ptr;
            continue;
        }
        if (*ptr == '/' && *(ptr+1) == '*') {
            ptr += 2;
            while(*ptr != '*' || *(ptr+1) != '/') 
                ++ptr;
            ptr += 2;
            continue;
        }
        *(data+d_size++) = *(ptr++);
    }
    printf("%s\n%ld\n", data, d_size);
}

void parse()
{
    Token token;
    p = data;
    while(p < data + d_size) {
        memset(&token, 0, sizeof(token));
        if (next(&token) == 0)
            printf("%d %s\n", token.type, token.token);
    }
}

void destroy()
{
    free(buffer);
    free(data);
}

int main(int argc, char **argv)
{
    if (argc != 2) {
        printf("use filename as argument\n"); 
        return -1;
    }
    init(argv[1]);
    preprocessing();
    parse();
    destroy();
    return 0;
}
