# Java IO: BIO, NIO, AIO

## Synchronize & Asynchronize
* Syn send the request, then wait or poll for the system
* Asyn send the request, then do other thing, when system IO finished, it will notify the process

## Blocking & Non-blocking
will the IO request being blocked

* Block when access the buffer, if buffer does not get the data, it will block the process
* Non-blocking access the buffer, no matter buffer is filled or not, it will return immediately

## BIO
* Blocking IO, it's syn. When doing IO, it send the request and wait or poll to get the result

## NIO (two type)
* Non-blocking, syn. When doing IO, it send the request, and doing other things, but still epoll to see whether data has been input. 
* Blocking, asyn, it send the request and register on select, when the IO finished, system will notify select, select tell the program to process the data, since select is blocking, hence.

## AIO
* it's asyn. send the request and do other things, when notified by system, just get the data