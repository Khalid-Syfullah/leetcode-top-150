#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BANK 10
#define GENE_LEN 8

static int minMutation(const char *startGene, const char *endGene,
                       const char bank[][GENE_LEN + 1], int bankSize) {
    /* Check if endGene is in bank */
    int endInBank = 0;
    for (int i = 0; i < bankSize; i++) {
        if (strcmp(bank[i], endGene) == 0) { endInBank = 1; break; }
    }
    if (!endInBank) return -1;

    const char choices[] = {'A', 'C', 'G', 'T'};
    int numChoices = 4;

    /* BFS queue */
    char queue[MAX_BANK * 2 + 10][GENE_LEN + 1];
    int  qhead = 0, qtail = 0;
    int  visited[MAX_BANK] = {0};

    strncpy(queue[qtail++], startGene, GENE_LEN + 1);

    int mutations = 0;

    while (qhead < qtail) {
        int size = qtail - qhead;
        for (int i = 0; i < size; i++) {
            char current[GENE_LEN + 1];
            strncpy(current, queue[qhead++], GENE_LEN + 1);

            if (strcmp(current, endGene) == 0) return mutations;

            char next[GENE_LEN + 1];
            for (int j = 0; j < GENE_LEN; j++) {
                char original = current[j];
                for (int k = 0; k < numChoices; k++) {
                    if (choices[k] == original) continue;
                    strncpy(next, current, GENE_LEN + 1);
                    next[j] = choices[k];

                    for (int b = 0; b < bankSize; b++) {
                        if (!visited[b] && strcmp(bank[b], next) == 0) {
                            visited[b] = 1;
                            strncpy(queue[qtail++], next, GENE_LEN + 1);
                        }
                    }
                }
            }
        }
        mutations++;
    }
    return -1;
}

int main(void) {
    {
        const char bank[][GENE_LEN + 1] = {"AACCGGTA"};
        printf("%d\n", minMutation("AACCGGTT", "AACCGGTA", bank, 1)); // 1
    }
    {
        const char bank[][GENE_LEN + 1] = {"AACCGGTA", "AACCGCTA", "AAACGGTA"};
        printf("%d\n", minMutation("AACCGGTT", "AAACGGTA", bank, 3)); // 2
    }
    {
        const char bank[][GENE_LEN + 1] = {"AAAACCCC", "AAACCCCC", "AACCCCCC"};
        printf("%d\n", minMutation("AAAAACCC", "AACCCCCC", bank, 3)); // 3
    }
    {
        const char bank[][GENE_LEN + 1] = {""};
        printf("%d\n", minMutation("AACCGGTT", "AACCGGTA", bank, 0)); // -1
    }
    return 0;
}
