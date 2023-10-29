Code for *Bunny* :

Based on 

https://perso.isima.fr/~dahill/Simu-ZZ2/Lab%20%23%203%20-%20Simu%20PI%20&%20Conf%20Intervals%20ann%c3%a9e%20impaire.pdf

This project use the following Mersenne Twister generator by Makoto Matsumoto :


http://www.math.sci.hiroshima-u.ac.jp/m-mat/MT/MT2002/emt19937ar.html

## Compilation commands :

- Place yourself at the parent folder of `src`
- Don't forget to create a `bin` directory in the same folder as `src`

- Fast Compilation :

```shell
g++ -O0 -g -DIS_IN_DEBUG=1 -DTRACK_MEMORY=1 ./src/betterCPP/*.c* ./src/betterCPP/core/*.c* ./src/betterCPP/low_level/*.c* ./src/betterCPP/simulation/*.c* ./src/betterCPP/mersenne_twister/*.c* ./src/betterCPP/math/*.c* ./src/betterCPP/text/*.c* ./src/*.c* -o ./bin/test.exe -Wall -Wextra -Wcomment -Wno-unknown-pragmas
```

- Optimized Compilation :

```shell
g++ -O3 ./src/betterCPP/*.c* ./src/betterCPP/core/*.c* ./src/betterCPP/low_level/*.c* ./src/betterCPP/math/*.c* ./src/betterCPP/text/*.c* ./src/betterCPP/simulation/*.c* ./src/betterCPP/mersenne_twister/*.c* ./src/*.c* -o ./bin/test.exe -Wall -Wextra -Wcomment -Wno-unknown-pragmas
```



Run :

```shell
./bin/test.exe
```

![Tex Avery, A Day at the Zoo de 1939](https://cdn.discordapp.com/attachments/751057885730963578/1165943546122092594/image.png)
"And here we come to a family of white rabbits. Of course you all know how fast they multiply" - Tex Avery, A Day at the Zoo de 1939 : https://www.youtube.com/watch?v=wFdmY1qMRQ8&t=201s

Output :

```c
Compiled at 18:25:11 
Verification : passed
sizeof(fmax  ) = 4 bytes
année  0, 5                                couples de lapins
année  1, 20                               couples de lapins
année  2, 35                               couples de lapins
année  3, 83                               couples de lapins
année  4, 210                              couples de lapins
année  5, 577                              couples de lapins
année  6, 1404                             couples de lapins
année  7, 3458                             couples de lapins
année  8, 8191                             couples de lapins
année  9, 20179                            couples de lapins
année 10, 49100                            couples de lapins
année 11, 119139                           couples de lapins
année 12, 289886                           couples de lapins
année 13, 707718                           couples de lapins
année 14, 1724671                          couples de lapins
année 15, 4203689                          couples de lapins
année 16, 10230255                         couples de lapins
année 17, 24971605                         couples de lapins
année 18, 60979557                         couples de lapins
année 19, 148715690                        couples de lapins
année 20, 362451292                        couples de lapins

année  0, 5                                couples de lapins
année  1, 23                               couples de lapins
année  2, 42                               couples de lapins
année  3, 99                               couples de lapins
année  4, 245                              couples de lapins
année  5, 638                              couples de lapins
année  6, 1550                             couples de lapins
année  7, 3742                             couples de lapins
année  8, 9199                             couples de lapins
année  9, 22429                            couples de lapins
année 10, 54373                            couples de lapins
année 11, 132444                           couples de lapins
année 12, 323373                           couples de lapins
année 13, 786528                           couples de lapins
année 14, 1915509                          couples de lapins
année 15, 4675696                          couples de lapins
année 16, 11433284                         couples de lapins
année 17, 27826759                         couples de lapins
année 18, 67728286                         couples de lapins
année 19, 165159462                        couples de lapins
année 20, 403564193                        couples de lapins

année  0, 5                                couples de lapins
année  1, 20                               couples de lapins
année  2, 36                               couples de lapins
année  3, 98                               couples de lapins
année  4, 234                              couples de lapins
année  5, 580                              couples de lapins
année  6, 1434                             couples de lapins
année  7, 3578                             couples de lapins
année  8, 8680                             couples de lapins
année  9, 21062                            couples de lapins
année 10, 51355                            couples de lapins
année 11, 124879                           couples de lapins
année 12, 305088                           couples de lapins
année 13, 744563                           couples de lapins
année 14, 1809644                          couples de lapins
année 15, 4412327                          couples de lapins
année 19, 156157437                        couples de lapins
année 20, 380013417                        couples de lapins

memory : 0 active malloc