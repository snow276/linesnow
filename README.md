# linesnow
linesnow is a simple readline tool which supports 
1. terminal input & output
2. moving the cursor left or right
   
It is my homework for PKU HPCFS Lecture_2 : c++ project programming.

## example
1. clone the repo
```shell
git clone https://github.com/snow276/linesnow.git
``` 
2. compile to generate an executable file ```linesnow```
```shell
cmake -B build
cmake --build build
```
3. execute the executable file ```linesnow```
```shell
./linesnow
```
1. then you can type characters in the terminal, move the cursor left or right, press 'backspace' to delete characters, and press 'enter' to finish a line.  ```linesnow``` echoes the line that you type. 


## limitations
1. only supports single-line input
2. doesn't support shortcut keys such as CTRL+D, CTRL+A