#include <iostream>
#include <cstdlib>
#include <unistd.h>
using namespace std;

int main( void ){
    int forkRet = fork();
    if( forkRet < 0 ){ //error
        exit( 1 );
    }
    else if( forkRet == 0 ){ //Child process
        cout << "I'm a kid process!\nMy ID is " << getpid() << ".\n";
    }
    else { //Parent process 
        cout << "Parent ID: " << getpid() << ",\nfork() returned " << forkRet << ".\n";
    }
    return 0;
}