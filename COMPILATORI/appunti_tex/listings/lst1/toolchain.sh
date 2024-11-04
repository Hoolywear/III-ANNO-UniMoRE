cpp -o hw.ii hw.cpp #preproc
cc1plus -o hw.s hw.ii 2>/dev/null #quasi sicuramente non in path
as -o hw.o hw.s
