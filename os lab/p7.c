#include <stdio.h>

#define MAX 25

int main() {
    int frag[MAX], b[MAX], f[MAX], i, j, nb, nf;
    static int bf[MAX], ff[MAX];

    printf("\n\tMemory Management Scheme - First Fit");
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
        for (j = 1; j <= nb; j++) {
            if (bf[j] != 1 && b[j] >= f[i]) { // If block is not allocated and large enough
                ff[i] = j;
                frag[i] = b[j] - f[i];
                bf[j] = 1; // Mark block as allocated
                break;
            }
        }
    }

    printf("\nFile No:\tFile Size:\tBlock No:\tBlock Size:\tFragment");
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

File No    File Size    Block No    Block Size    Fragment
1          1            1           5             4
2          4            3           7             3
