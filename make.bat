@echo off
g++ TaskManager.cpp process.cpp privilege.cpp -lpsapi -o TaskManager.exe
TaskManager.exe