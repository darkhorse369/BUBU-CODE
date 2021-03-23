/*
This program takes 2 paramaters

load file.txt binary

file.txt contains a list of scanned files in the system  ex.

dir /S /B > file.txt

The binary paramater gets executed with the system function

strcat buffer is flushed due to its functional implementation
(fgets limited to 1kb per line)


*/


#include<stdio.h>
#include<stdlib.h>

int testfile(char p[1024], char inject[1024]) {
  int i = 0;
  char t[1024] = "";
  FILE * tmp;
  char itmp[2048] = "";

  strcpy(t, p); //copies paramater to a local variable

  if (t[strlen(t) - 1] == 0x0a) { //deletes 0x0a from the end of the buffer
    t[strlen(t) - 1] = 0;
  }

  //for(;i<strlen(t);i++){printf("%x\n",t[i]);}
  tmp = fopen(t, "rb");
  if (tmp) {  //verifies if files exist
  	printf("%s\n",t);
    strcat(itmp, inject);
    strcat(itmp, " ");
    strcat(itmp, t);https://github.com/darkhorse369/BUBU-CODE/blob/main/load.c
    system(itmp);
    fclose(tmp);

  } else { // files do not exist
    //printf("%s: not found",p);
  }
  return 0;
}

int main(int argc, char * argv[]) {
	//init
  char str[1024];
  FILE * load;

  if (argc > 2) { 

    load = fopen(argv[1], "rb");

    if (load) { //if file in argv[1] is found
      for (; !feof(load);) { //while the end of the file has not been reached
        fgets(str, 1024, load); //read line by line 1kb max per line
        testfile(str, argv[2]); //pass buffer from file + argv[2]
        //printf("%s",str);
        strcpy(str, "");
      }
      fclose(load);
    } else {
      printf("Error : File not found\n");
      return 1;
    }

  }

//THE END
  return 0;
}
