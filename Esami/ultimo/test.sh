cd "`dirname "${0}"`"

g++ -std=c++11 *.cpp
input="
1
H1 O2
H1 O3
0
9
0
"
printf "$input" | ./a.out