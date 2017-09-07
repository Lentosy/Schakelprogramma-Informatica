#include <stdlib.h>
#include <stdio.h>
#include <sys/io.h>
#include <unistd.h>

int main(int argc, char *argv[]){


  if(iopl(3) < 0){
    perror(argv[0]);
    exit(1);
  }

  int busnum, devnum, funcnum;

  for(busnum = 0; busnum < 256; busnum++){
    printf("%d", busnum << 24);
    printf("%d\n", busnum );
    for(devnum = 0; devnum < 32; devnum++){
      for(funcnum = 0; funcnum < 8; funcnum++){
        unsigned int value = (1 << 31) + (busnum << 16) + (devnum << 11) + (funcnum << 8);
        outl(value, 0xcf8);
        unsigned int answer = inl(0xcf8);
        if(answer != 0xffffffff){
          printf("Bus = %x\tDevice = %x\tFunction = %x: %04x %04x\n", busnum, devnum, funcnum, answer & 0x0000ffff, answer >> 16);
        }
      }
    }
  }
}
