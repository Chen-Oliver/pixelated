#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

#define XRES 512
#define YRES 512
#define maxColor 255

int main(){
  int fd = open("image.ppm",O_CREAT|O_RDWR,0644);
  int i,j;
  char buffer[30];
  sprintf(buffer,"P3\n%d %d %d\n",XRES,YRES,maxColor);
  write(fd,buffer,strlen(buffer));
  int r=255;
  int g=0;
  int b=0;
  for(i=0;i<YRES;i++){
    for(j=0;j<XRES;j++){
      sprintf(buffer,"%d %d %d\n",r,g,b);
      write(fd,buffer,strlen(buffer));
      g=j%256;
      b=i%256;
      r=(g*b)%256;
    }
  }
  close(fd);
  return 0;
}
