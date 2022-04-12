#include <stdio.h>
#include <string.h>

#define MAX_string 10000000
#define MAX_pattern 3000 

char string[MAX_string];
char pat[MAX_pattern];
int fail[MAX_pattern];
int ans[MAX_string];


int an=0;
int ends,endp;


int main(){
    FILE* file1;
    file1 = fopen("pattern.txt", "r");
    if(file1 == NULL)
    {
        printf("the pattern file does not exist.");
        return 0;
    }
    else
    {
        fgets(pat, MAX_string, file1);
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
        fgets(string, MAX_string , file2);
        fclose(file2);
    }


    FILE* fp1;
    fp1=fopen("result_kmp.txt", "w");  
    ends = strlen(string); 
    endp = strlen(pat); 
    int i,j;
    for(i = 1; i < endp; i++){
        while( j > 0 && pat[i] != pat[j]) 
          j = fail[j-1] ;
        if(pat[i]== pat[j]) 
          fail[i] = ++j;
    }

    int b=0;
    int a;
    for(a=0; a < ends; a++){
        while(string[a] != pat[b] && b>0) b= fail[b-1];
        if(string[a]== pat[b]) b++;
        if(b == endp -1) ans[an++] = a - endp + 2; 
    }


    fprintf(fp1,"%d\n", an);
    for(int i=0; i < an; i++) fprintf(fp1, "%d ", ans[i]);

    fclose(fp1);
    printf("Program complete. Result saved to result_kmp.txt");


 }

    