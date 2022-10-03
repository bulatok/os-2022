gcc -pthread -o ex3 ex3.c;

echo "n=10000000 m=1";
date +"%F %T,%3N";
./ex3 10000000 1;
date +"%F %T,%3N";
echo;

echo "n=10000000 m=2";
date +"%F %T,%3N";
./ex3 10000000 2
date +"%F %T,%3N";
echo;

echo "n=10000000 m=4";
date +"%F %T,%3N";
./ex3 10000000 4;
date +"%F %T,%3N";
echo;

echo "n=10000000 m=10";
date +"%F %T,%3N";
./ex3 10000000 10;
date +"%F %T,%3N";
echo;

echo "n=10000000 m=100";
date +"%F %T,%3N";
./ex3 10000000 100;
date +"%F %T,%3N";
echo;