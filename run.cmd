@echo off
g++ test.cpp account.cpp bank.cpp transaction.cpp md5.cpp -std=c++11 -o run.exe && run.exe