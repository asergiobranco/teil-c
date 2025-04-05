TEIL C Library
==============

The C Library is available to download at: [https://github.com/asergiobranco/teil-c/releases](https://github.com/asergiobranco/teil-c/releases).

## Compile the Code

One approach, if you are uing GCC, is to use the following command to compile your code and add TEIL

`gcc -I /path/to/src *.c /path/to/teil.a -o main -lm`

## Docker 

We provide an official Docker image to easily compile any model. To pull the image please use the following command:

`docker pull asergiobranco/teil-gcc`

This will pull the compiling image (note that the python package is not included in this). 

Once downloaded, one can run the container with:

`docker run -it -v ./:/workspace asergiobranco/teil-gcc`

This will open the bash, which allows your to compile the model using the command:

`root:/workspace$ gcc ª.c -o main -lm -lteil`


## Useful Links

|               | URL  |
|:-------------:|:----:|
| Download      | [https://github.com/asergiobranco/teil-c/releases](https://github.com/asergiobranco/teil-c/releases) |
| Github        | https://github.com/asergiobranco/teil-c  |
| Documentation | |
| Issues        | |