//Serial generator example #1


#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>


char serial[1024]="";
char serial_array[]={"0123456789ABCDEF"};

int main(int argc,char *argv[]){

srand(time(NULL));
int x=0,i=0,t=0;
int flag=0;

printf("Simple Serial Generator 0-9,A-F by jeda\n");
printf("============================================\n");
   // for(;;){
        for(x=0;x<29;x++){
            if(i==5){i=0;serial[x]='-';x++;}
                serial[x]=serial_array[rand()%15+1];
                i++;
                }
printf("%s\n",serial);
x=0,i=0;

   //}

    return 0;
}
