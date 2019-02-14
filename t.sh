#!/bin/bash
buffersize=(1 256 512 1024 2048 4096)
## Start testing
for value in ${buffersize[*]}
do
## Testing Unix I/O system calls
tcommando="./unixio -f filename -b $value -t 1"
eval $tcommando
## Testing C calls
tcommando="./unixio -f filename -b $value -t 0"
eval $tcommando
done
## Testing is done! :-)
