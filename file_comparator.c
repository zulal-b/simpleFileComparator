/*
* Compares the files with single int in each line
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void compare_inputs(char *input1, char *input2){
  FILE *file1 = fopen(input1, "r");
  FILE *file2 = fopen(input2, "r");
  
  char line1[10];
  char line2[10];
  int line_num = 1;
  char *templine = NULL, *templine2 = NULL;
  char *check1, *check2;
  int miss_count = 0, sad = 0;
  int fp_count = 0, fn_count = 0;
  int first, second;

  check1 = fgets(line1, sizeof(line1), file1);
  check2 = fgets(line2, sizeof(line2), file2);

  while(check1 != NULL && check2 != NULL){
    templine = NULL;
    templine = strtok(line1, "\n");
    templine2 = strtok(line2, "\n");
    first = atoi(templine);
    second = atoi(templine2);

    if (first == 1 && second == 0){
      printf("OOPS FN --> line = %d, base = %d, other = %d\n", line_num, first, second);
      fn_count++;
      miss_count++;
    }
    else if (first == 0 && second == 1){
      printf("OOPS FP --> line = %d, base = %d, other = %d\n", line_num, first, second);
      fp_count++;
      miss_count++;
    }
    else if (first != second){
      printf("OOPS :( --> line = %d, first = %d, second = %d\n", line_num, first, second);
      sad++;
    }

    check1 = fgets(line1, sizeof(line1), file1);
    check2 = fgets(line2, sizeof(line2), file2);
    line_num++;
  }

  if (check1 != NULL && check2 == NULL)
    printf("File1 is longer than file2, something is wrong. \n");
  else if (check1 == NULL && check2 != NULL)
    printf("File2 is longer than file1, something is wrong. \n");
  else if (check1 == NULL && check2 == NULL){
    printf("File1 is and file2 finished together, don't worry ;) \n");

    if (miss_count == 0 && sad == 0)
    printf("COMPLETELY IDENTICAL\n");
    else {
      printf("There are some differences: %d / %d\n", miss_count, line_num-1);
      printf("FP count = %d\n", fp_count);
      printf("FN count = %d\n", fn_count);
      printf("SAD count = %d\n", sad);
    }
  }
  
  fclose(file1);
  fclose(file2);

}


int main(int argc, char* argv[])
{
  if(argc < 3){
    printf("MISSING ARGUMENT\n");
    exit(0);
  }

  else 
    {
      char *input1 = argv[1];
      char *input2 = argv[2];

      compare_inputs(input1, input2);
    }

  return 0;
  }