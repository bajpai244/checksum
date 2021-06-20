# Checksum Checker

<img alt="icon" src="https://cloud-7n84z8lfd-hack-club-bot.vercel.app/0image.png" width="256px" />

A simple utiity that takes two arguments:

1. The file to hash 
2. A file containing target hash

example usage:
```
checksum path_of_file_to_hash path_of_file_containing_hash  
```

It currently uses sha-256, but support for more algorithms can be added in future.

As of now it is using **shasum** under the hood, so make sure that the utiity is installed in your system.

to build the file -> Go to the project directory.

then type the command `make`.

