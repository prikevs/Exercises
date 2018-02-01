#ifndef QUESBANK_H
#define QUESBANK

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAXLEN 200

#define PAPERFILE "data/paper.txt"
#define ANSFILE "data/answer.txt"

typedef struct Ques
{
    int chapter, num;
    char tip[MAXLEN];
    char description[MAXLEN];
    char option[MAXLEN];
    int difficulty; 
    int papern;
    char ans;
    struct Ques *next;
}Ques;

#endif
