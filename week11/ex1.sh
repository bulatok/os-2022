#!/bin/bash
fallocate -l 60M lofs.img;

loop=$(losetup -f);
sudo losetup $loop lofs.img;
sudo mkfs.ext4 lofs.img;
mkdir lofsdisk;
sudo mount $loop lofsdisk;