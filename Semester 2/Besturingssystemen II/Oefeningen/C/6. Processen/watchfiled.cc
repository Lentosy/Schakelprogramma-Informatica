#include <iostream>
#include <fstream>
#include <string>

#include <stdlib.h>
#include <unistd.h>

using namespace std;

int main(int argc, char* argv[]){
  ifstream file ("watchfile.txt");
  string line;

  if(file.is_open()){
    while(getline(file, line)){
      if(fork() == 0){
        execl("./watchfile", "./watchfile", line.c_str(), (char *)0);
      }
    }
    file.close();
  }

  for(;;){

  }
  return 0;
}
