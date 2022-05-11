#include "process.h"

typedef struct process
{
	char procName[50];
	DWORD PID;
	char sessionName[30];
	int Session;
	double MemUsage;	
}process;

void lable(){
	//std::cout << "Image Name" << "\t\tPID" << "\t\tSession Name" << "\t\t" << "Session#" << "\tMem Usage";
	std::cout << "\n===============" << "\t\t=========" << "\t============" << "\t\t=========" << "\t=========";
}

int main(){
	lable();
	
	displayProcess();
	//process proc;

	//while()
	return 0;
}