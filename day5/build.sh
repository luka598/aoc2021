rm -rf *.out
echo "Compiling part1.cpp"
g++ part1.cpp -ggdb -O0 -fmax-errors=1 -o part1.out
echo "Compiling part2.cpp"
g++ part2.cpp -ggdb -O0 -fmax-errors=1 -o part2.out
echo "Compiled everything"