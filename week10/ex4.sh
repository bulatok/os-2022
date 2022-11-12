mkdir tmp
touch tmp/file1
touch tmp/file2

ln tmp/file1 tmp/link1

gcc -o ex4 ex4.c && ./ex4

rm -rf tmp