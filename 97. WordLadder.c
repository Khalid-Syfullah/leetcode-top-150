#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 20
#define MAX_WORD_LEN 16

static int ladderLength(const char *beginWord, const char *endWord,
                        const char wordList[][MAX_WORD_LEN], int listSize) {
    /* Check if endWord is in the list */
    int endIdx = -1;
    for (int i = 0; i < listSize; i++) {
        if (strcmp(wordList[i], endWord) == 0) { endIdx = i; break; }
    }
    if (endIdx == -1) return 0;

    int wordLen = (int)strlen(beginWord);

    /* BFS */
    char queue[MAX_WORDS * 2 + 10][MAX_WORD_LEN];
    int  visitedList[MAX_WORDS] = {0};
    int  qhead = 0, qtail = 0;
    int  length = 1;

    strncpy(queue[qtail++], beginWord, MAX_WORD_LEN);
    /* Mark beginWord as visited if it appears in the list */
    for (int i = 0; i < listSize; i++) {
        if (strcmp(wordList[i], beginWord) == 0) visitedList[i] = 1;
    }

    while (qhead < qtail) {
        int size = qtail - qhead;
        for (int i = 0; i < size; i++) {
            char current[MAX_WORD_LEN];
            strncpy(current, queue[qhead++], MAX_WORD_LEN);

            if (strcmp(current, endWord) == 0) return length;

            char next[MAX_WORD_LEN];
            for (int j = 0; j < wordLen; j++) {
                char original = current[j];
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    if (ch == original) continue;
                    strncpy(next, current, MAX_WORD_LEN);
                    next[j] = ch;

                    for (int b = 0; b < listSize; b++) {
                        if (!visitedList[b] && strcmp(wordList[b], next) == 0) {
                            visitedList[b] = 1;
                            strncpy(queue[qtail++], next, MAX_WORD_LEN);
                        }
                    }
                }
            }
        }
        length++;
    }
    return 0;
}

int main(void) {
    {
        const char wordList[][MAX_WORD_LEN] = {"hot","dot","dog","lot","log","cog"};
        printf("%d\n", ladderLength("hit", "cog", wordList, 6)); // 5
    }
    {
        const char wordList[][MAX_WORD_LEN] = {"hot","dot","dog","lot","log"};
        printf("%d\n", ladderLength("hit", "cog", wordList, 5)); // 0
    }
    {
        const char wordList[][MAX_WORD_LEN] = {"a","b","c"};
        printf("%d\n", ladderLength("a", "c", wordList, 3)); // 2
    }
    return 0;
}
