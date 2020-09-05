#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STACKS (256)
#define STRLEN (1024)
int main(int argc, char **argv){
  if(argc!=2) return 0;
  char instr[STRLEN];
  char outstr[STRLEN];
  char **stack=(char**)malloc(STACKS*sizeof(char*));
  for(int s=0;s<STACKS;s++){
    stack[s]=(char*)malloc(STRLEN);
    strcpy(stack[s],"");
  }

  FILE *infile=fopen(argv[1], "rt");
  while(fgets(instr,STRLEN-1,infile)!=NULL){
    int s=0;
    for(int i=0;i<strlen(instr);i++){
      char c=instr[i];
      char *a;
      char *b;
      switch(c){
        case '\r':case '\n':case ' ':
        //ignore
        break;
        case 'C':
          a=stack[--s];
          b=stack[--s];
          sprintf(outstr,"C(%s,%s)",a,b);
          strcpy(stack[s++],outstr);
        break;
        default:
          sprintf(stack[s++],"%c",c);
        break;
      }//switch
    }//for char
    printf("%s\n",stack[0]);
  }//while line
  fclose(infile);
  for(int s=0;s<STACKS;s++)free(stack[s]);
  free(stack);
  return -1;
}
