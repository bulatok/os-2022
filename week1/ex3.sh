#!/bin/bash

date;
sleep 3 && mkdir root;

date;
sleep 3 && touch root/root.txt;

date;
sleep 3 && mkdir home;

date;
sleep 3 && touch home/home.txt;

ls / -rt > root/root.txt;
ls ~ -rt > home/home.txt;

cat root/root.txt && ls ./root;
cat home/home.txt && ls ./home;
