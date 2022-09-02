#!/bin/bash

date;
sleep 3 && mkdir root;

date;
sleep 3 && touch root/root.txt;

date;
sleep 3 && mkdir home;

date;
sleep 3 && touch home/home.txt;

ls / -tr > root/root.txt;
ls ~ -tr > home/home.txt;

cat root/root.txt && ls ./root;
cat home/home.txt && ls ./home;
