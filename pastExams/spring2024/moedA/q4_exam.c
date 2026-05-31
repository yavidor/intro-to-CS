#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define DONT_KNOW "I_dont_know"
void printIDontKnow() {
    printf("%s", DONT_KNOW);
    exit(0);
}

bool exam_q4(char *word1, char *word2);

int main() {
    // uncomment next line if you don't know the answer
    // printIDontKnow();

    int n1, n2;
    if (scanf("%d", &n1) != 1) {
        return 1;
    }
    if (scanf("%d", &n2) != 1) {
        return 1;
    }
    
    char * word1 = (char*) malloc(sizeof (char) * (n1+1));
    if (!word1) {
        return 1;
    }   
    
    char * word2 = (char*) malloc(sizeof (char) * (n2+1));
    if (!word2) {
        free(word1);
        return 1;
    } 
    
    if (scanf("%s", word1) != 1) {
        return 1;
    }
 
    if (scanf("%s", word2) != 1) {
	free(word1);
        return 1;
    }

    if(exam_q4(word1, word2)) 
    {
        printf("true");
    }
    else 
    {
        printf("false");
    }
    free(word1);
    free(word2);
    return 0;
}

/* Your code here */


bool exam_q4(char *word1, char *word2) {
    return true; // change this
}

