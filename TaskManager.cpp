#include "process.h"


void label(){
	std::cout <<   "Image Name\t\t\t  PID\tSession Name\tSession#\tMem Usage";
	std::cout << "\n==========\t\t\t  ===\t============\t========\t=========\n";
	//std::cout << "Image Name" << "\t\tPID" << "\t\tSession Name" << "\t\t" << "Session#" << "\tMem Usage";
	//std::cout << "\n===============" << "\t\t=========" << "\t============" << "\t\t=========" << "\t=========";
}


int main(){
	
	char choice[10];

	HANDLE hProcess=GetCurrentProcess();
	HANDLE hToken;

	if (OpenProcessToken(hProcess, TOKEN_ADJUST_PRIVILEGES, &hToken))
	{
	    if(!SetPrivilege(hToken, SE_DEBUG_NAME, TRUE)){
	    	CloseHandle(hToken);
	    	std::cout << "Cannot set to Debug mode: " << GetLastError() << "\n";
	    	std::cout << "Chay bang quyen administrator";
	    }
	    else{
	    	CloseHandle(hToken);
	    }
	}



	do{
		std::cout << "\n1.Taskkill theo PID";
		std::cout << "\n2.Taskkill theo taskName";
		std::cout << "\n3.Hien thi bang process";
		std::cout << "\n0.Thoat";
		std::cout << "\nNhap vao chuc nang: ";
		std::cin >> choice;
		fflush(stdin);
		if(!strcmp(choice, "1")){
			std::cout << "\nNhap vao PID: "; 
			DWORD PID;
			std::cin >> PID;

			HANDLE hSnap;
			hSnap = OpenProcess(PROCESS_ALL_ACCESS , NULL, PID);

			if(hSnap){
				TerminateProcess(hSnap, 0);
			}
			else{
				std::cout << "\nPID khong hop le";
			}
		}

		else if(!strcmp(choice, "2")){
			std::cout << "\nNhap vao process name: ";
			char processName[30];
			gets(processName);
			DWORD procID = 0;
			procID = getProcessID(processName);

			if(!procID){
				std::cout << "\nProcess name khong hop le";
			}
			else{
				HANDLE hSnap;
				hSnap = OpenProcess(PROCESS_ALL_ACCESS , NULL, procID);
				if(hSnap){
					TerminateProcess(hSnap, 0);
				}
				else{
					std::cout << "\nKhong the terminate process";
				}
			}
		}

		else if(!strcmp(choice, "3")){
			label();
			displayProcess();
		}
		
	}
	while(strcmp(choice, "0"));
	


	return 0;
}