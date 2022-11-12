echo Bulat2 > ../week1/file.txt

link ../week1/file.txt _ex2.txt

inodenumber=$(ls -i ../week1/file.txt);
num_file=($inodenumber) # to array, for gettin only number

find _ex2.txt -inum ${num_file[0]} > ex2.txt

find _ex2.txt -inum ${num_file[0]} -exec rm {} \; >> ex2.txt