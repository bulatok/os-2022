gcc ex2.c -o ex2.out;

dr=`pwd`/lofsdisk
mkdir -p $dr/bin $dr/lib $dr/lib64
cp -v /bin/bash $dr/bin
cp -v /bin/ls $dr/bin
cp -v /bin/cat $dr/bin
cp -v /usr/lib $dr/usr/lib 

cp -v ex2.out $dr/ex2.out
mkdir $dr/usr
mkdir $dr/usr/lib
mkdir $dr/usr/lib64

cd $chr
sudo chroot $chr /bin/bash
/ex2.out > ex2.txt
exit
./ex2.out >> ex2.txt