@echo off
rem Compilation du fichier main.cpp avec g++
g++ -std=c++23 -Wall -Wextra -Werror -Wno-unused-variable *.cpp -o Auto-Click
timeout /t 99 /nobreak
start "" "D:\Code\Code\C++\Projet\Key"

