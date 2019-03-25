gcc 04-Creating_named_pipe.c
./a.out
gcc 04-Reading_from_named_pipe.c -o reading
gcc 04-Write_into_named_pipe.c -o writing
./writing & ./reading