#include <stdio.h>

#define MAX 25

int main() {
    int frag[MAX], block[MAX], file[MAX];
    int i, j, nb, nf, temp, smallest;
    static int block_flag[MAX], file_block[MAX];

    printf("\nMemory Management Scheme - Best Fit\n");

    printf("Enter the number of blocks: ");
    scanf("%d", &nb);

    printf("Enter the number of files: ");
    scanf("%d", &nf);

    printf("\nEnter the size of the blocks:\n");
    for(i = 1; i <= nb; i++) {
        printf("Block %d: ", i);
        scanf("%d", &block[i]);
    }

    printf("\nEnter the size of the files:\n");
    for(i = 1; i <= nf; i++) {
        printf("File %d: ", i);
        scanf("%d", &file[i]);
    }

    for(i = 1; i <= nf; i++) {
        smallest = -1;
        for(j = 1; j <= nb; j++) {
            temp = block[j] - file[i];
            if(!block_flag[j] && temp >= 0) {
                if(smallest == -1 || temp < (block[smallest] - file[i])) {
                    smallest = j;
                }
            }
        }
        if(smallest != -1) {
            file_block[i] = smallest;
            block_flag[smallest] = 1;
            frag[i] = block[smallest] - file[i];
        } else {
            file_block[i] = -1;
            frag[i] = -1;
        }
    }

    printf("\nFile No\tFile Size\tBlock No\tBlock Size\tFragment\n");
    for(i = 1; i <= nf; i++) {
        if(file_block[i] != -1)
            printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", i, file[i], file_block[i], block[file_block[i]], frag[i]);
        else
            printf("%d\t%d\t\tNot Allocated\n", i, file[i]);
    }

    return 0;
}

Enter the number of blocks: 3
Enter the number of files: 2

Block sizes:
Block 1: 5
Block 2: 2
Block 3: 7

File sizes:
File 1: 1
File 2: 4

File No    File Size    Block No    Block Size    Fragment
1          1            2           2             1
2          4            1           5             1
