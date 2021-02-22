#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <thread>

using namespace std;
int main(int argc, char* argv[]) {



char* starting_pos = argv[1];
char* interval = argv[2];

ofstream out;
out.open("output.txt");

if(out.is_open()){

	for (int iterator = std::stoi(starting_pos); iterator < 100; iterator++){

	out << iterator << endl;
	cout << iterator << "S" << endl;
	this_thread::sleep_for(chrono::milliseconds(stoi(interval)));
	//usleep(stoi(interval));
	}

} else {

	cout<<"Failed to open file"<<endl;
}
out.close();

return 0;

}

