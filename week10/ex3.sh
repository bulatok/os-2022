rm _ex3.txt
echo Bulat3 > _ex3.txt


chmod a-x _ex3.txt && ls -l _ex3.txt > ex3.txt

chmod u=rxw _ex3.txt && chmod o=rxw _ex3.txt && ls -l _ex3.txt >> ex3.txt

chmod g=u _ex3.txt && ls -l _ex3.txt >> ex3.txt

# 660
echo "660: user/owner can read, can write and can't execute. Group can read, can write and can't execute. Other can't read, can't write and can't execute" >> ex3.txt

# 775
echo "775: user/owner can read, can write and can execute. Group can read, can write and can execute. Other can read, can't write and can execute" >> ex3.txt

# 777 
echo "777: user/owner can read, can write and can execute. Group can read, can write and can execute. Other can read, can write and can execute" >> ex3.txt

cat ex3.txt