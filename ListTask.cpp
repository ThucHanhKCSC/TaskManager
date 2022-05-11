#include "process.h"

typedef struct process
{
	char procName[50];
	DWORD PID;
	char sessionName[30];
	int Session;
	double MemUsage;	
}process;


void label(){
	std::cout <<   "Image Name\t\t\t  PID\tSession Name\tSession#\tMem Usage";
	std::cout << "\n==========\t\t\t  ===\t============\t========\t=========\n";
}

int main(){
	label();
	
	displayProcess();

	getchar();
	return 0;
}