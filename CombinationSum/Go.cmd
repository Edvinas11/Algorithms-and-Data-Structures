if .%USERDOMAIN% == "PRECISION5520" goto :savasPC
Rem MIF kompiuteris
path C:\PROGRA~2\Dev-Cpp\MinGW64\bin\;%path%
mingw32-make.exe
goto :toliau

:savasPC
make

:toliau
echo 10 3 25 > data.txt
echo 4 16 6 2 19 13 17 7 3 10 >> data.txt
combSum.exe data.txt > result.txt