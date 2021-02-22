#include <iostream>
#include <spawn.h>
#include <stdlib.h>
#include <cstring>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fstream>
#include <errno.h>
#include <unistd.h>

using namespace std;


char **environ;

int main(int argc, char* argv[]){
int status;
char* starting_pos = argv[1];
char* interval = argv[2];
char* name = argv[0];
argv[0] = "child";
pid_t child_pid;




do {	

	 	
        char *argV[] = {name, starting_pos, interval, (char *) 0};
		int pid = -1;	

	pid = posix_spawn(&child_pid, "child", NULL, NULL, argV, environ);

		if(pid == 0){

		cout<<"Child process started. PID: "<<child_pid<<endl;

		} else {
		cout<<"Failed"<<endl;
		}


	waitpid(pid, &status, 0);
	    

		 if (WIFSIGNALED(status)){
			cout<<"Child killed. Restarting..."<< endl;		
		    string s;
			string g;
			
			ifstream infile("output.txt");
		 	
		 	while(getline(infile, s) ){
				 g = s.data();
			 }
			
			strcpy(starting_pos,g.c_str()); 
		 }
		 else if (WEXITSTATUS(status)){
			cout<<"Exited Normally"<<endl;
		 }
		 	
		 	
} while((WIFSIGNALED(status))==1);


return 0;

}

