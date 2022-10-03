gcc -pthread -o ex4 ex4.c;

date +"%F %T,%3N";
./ex4 10000000 1
date +"%F %T,%3N";
echo;

date +"%F %T,%3N";
./ex4 10000000 2
date +"%F %T,%3N";
echo;

date +"%F %T,%3N";
./ex4 10000000 4
date +"%F %T,%3N";
echo;

date +"%F %T,%3N";
./ex4 10000000 10
date +"%F %T,%3N";
echo;

date +"%F %T,%3N";
./ex4 10000000 1000
date +"%F %T,%3N";
echo;