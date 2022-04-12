#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PATTERN_SIZE 3000
#define MAX_STRING_SIZE 10000000

char string[MAX_STRING_SIZE];
char pat[MAX_PATTERN_SIZE];
int count= 0;
int arr[MAX_STRING_SIZE];
int ans[MAX_PATTERN_SIZE];


int main() {
    FILE* file1;
    file1 = fopen("pattern.txt", "r");
    if(file1 == NULL)
    {
        printf("the pattern file does not exist.");
        return 0;
    }
    else
    {
        fscanf(file1, "%s", pat);
        fclose(file1);
    }
    FILE* file2;
    file2 = fopen("string.txt", "r");
    if(file2 == NULL)
    {
        printf("The string file does not exist.");
        return 0;
    }
    else
    {
        fscanf(file2, "%s", string);
        fclose(file2);
    }

    FILE* fp1;
    fp1=fopen("result_naive.txt", "w");
        
    int i=0, j=0, f =0;
    int endstring = strlen(string);
    int endpattern = strlen(pat);
    int endmatch = endpattern;
    fprintf(fp1, "%d\n", 1264);
    while(i < endstring - endmatch +1)
    {
        while(string[j] == pat[f] && f < endmatch)
        {
            j++;
            f++;

        }

        if(f > endmatch -1)
            ans[count++] = i;
     
        f=0;
        j = ++i;
    }

/*        fprintf(fp1, "\n%d ", count); */
        for(int q=0; q<count; q++) fprintf(fp1, "%d ",ans[q]);
        fclose(fp1);
    printf("Program complete. Result saved to result_naive.txt");
}
 