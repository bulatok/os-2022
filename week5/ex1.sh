gcc -o pub publisher.c;
gcc -o sub subscriber.c

# had problems with gnome, but I tested it manually and it worked fine. 
# When publisher sends n messages to a named pipe
# subscriber reads all these n message successfully
