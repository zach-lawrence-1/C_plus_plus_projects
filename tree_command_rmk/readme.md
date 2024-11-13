# Tree Command Remake

## Description
A homework problem in one of my CS classes had us recreate the tree command from linux only using readdir(), opendir(), and closedir() syscalls for directory traversal.
I decided to make it again but on windows using filesystem which is apart of the standard library, since the tree command in windows is not very good.
I don't think I can post my code including the syscall implementation due to potential university violations as with my other university related assignments/code.

## Program Running
<img width="701" alt="tree" src="https://github.com/user-attachments/assets/006d0c1f-ea0c-4b85-b07b-b7627a56e415">

## How To Run
As long as you have MSYS2 setup and you can run make files then you should be able to run the code as follows:

1. Open a terminal in the same directory as the code and make file
2. Type in ```make```
3. run '''./tree.exe''' or '''./tree.exe directory'''
