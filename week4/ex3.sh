gcc -o ex3 ex3.c;

echo "started with n = 3";
./ex3 3 &
pstree
sleep 1

pstree;
sleep 5;

pstree;
sleep 5;

pstree;
sleep 5;

echo "started with n = 5";
./ex3 5 &

pstree
sleep 1

pstree;
sleep 5;

pstree;
sleep 5;

pstree;
sleep 5;

pstree;
sleep 5;

pstree;
sleep 5;
