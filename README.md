<div align="center">
</div>
<div align="center">
</div>

## What it is
A project to understand better the usage of UNIX signals, it consists of a server and
a client, the last sends a string to the server using only 2 permitted signals (SIGUSR1, 
SIGUSR2) and the server must print it on the console.

Succeeded with 115%

## Skills
- Rigor
- Unix logic

## How to use it
Requisites:
```shell
clang
```

Clone the repository and run:
```shell
make
```

Both server and client will be generated, after that, run the server on background
with:
```shell
./server &
```

Its PID will be printed, with that you can execute the client, passing the PID and
a string to be printed.
```shell
./client <PID> "Just remember ALL CAPS when you spell the man name"
```

## Found any bug?
Feel free to contact me or create an issue!

###### Licensed under GPLv3
