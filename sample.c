#include<stdio.h>
#include<string.h>
#include<stdlib.h>



int main(int argc, char *argv[]){

if(argc>1){
FILE *in=fopen(argv[1],"a+");
char buffer[2048]="";
char str[2048]="";

int i=0;

if(in){


strcat(str,"echo \"\">");
strcat(str,argv[1]);

    for(;;){

fgets(buffer,1024,in);
buffer[strlen(buffer)-1]=0;

if(strcmp(buffer,"clear")==0){
system("clear");
}

else if(strcmp(buffer,"")==0){}

else if(strcmp(buffer,"flush")==0){system(str);strcpy(buffer,"");}

else{
    printf("%s\n",buffer);
}

if(feof(in)){
rewind(in);
}

system(buffer);
strcpy(buffer,"");
strcpy(str,"");
    }
fclose(in);
}

else{
printf("Error: File not found!\n");
}

}
    return 0;

}