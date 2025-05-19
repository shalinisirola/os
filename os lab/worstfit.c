#include <stdio.h>

#define MAX 25

int main() {
    int frag[MAX], b[MAX], f[MAX], i, j, nb, nf, temp;
    static int bf[MAX], ff[MAX];

    printf("\n\tMemory Management Scheme - Worst Fit");
    printf("\nEnter the number of blocks: ");
    scanf("%d", &nb);

    printf("Enter the number of files: ");
    scanf("%d", &nf);

    printf("\nEnter the size of the blocks:\n");
    for (i = 1; i <= nb; i++) {
        printf("Block %d: ", i);
        scanf("%d", &b[i]);
    }

    printf("\nEnter the size of the files:\n");
    for (i = 1; i <= nf; i++) {
        printf("File %d: ", i);
        scanf("%d", &f[i]);
    }

    for (i = 1; i <= nf; i++) {
        int worst = -1;
        for (j = 1; j <= nb; j++) {
            if (!bf[j] && b[j] >= f[i]) {
                if (worst == -1 || b[j] > b[worst]) {
                    worst = j;
                }
            }
        }

        if (worst != -1) {
            ff[i] = worst;
            frag[i] = b[worst] - f[i];
            bf[worst] = 1;
        }
    }

    printf("\nFile No\tFile Size\tBlock No\tBlock Size\tFragment");
    for (i = 1; i <= nf; i++) {
        if (ff[i] != 0) {
            printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d", i, f[i], ff[i], b[ff[i]], frag[i]);
        } else {
            printf("\n%d\t\t%d\t\tNot Allocated", i, f[i]);
        }
    }

    return 0;
}

Blocks: 5, 2, 7
Files:  1, 4

File No	File Size	Block No	Block Size	Fragment
1		1		3		7		6
2		4		1		5		1
