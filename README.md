
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
Compiled at 11:23:12 
Verification : passed
sizeof(fmax  ) = 4 bytes
année  0, 5                                couples de lapins
année  1, 43                               couples de lapins
année  2, 198                              couples de lapins
année  3, 767                              couples de lapins
année  4, 3467                             couples de lapins
année  5, 14747                            couples de lapins
année  6, 62173                            couples de lapins
année  7, 263738                           couples de lapins
année  8, 1129385                          couples de lapins
année  9, 4828245                          couples de lapins
année 10, 20604857                         couples de lapins
année 11, 88044439                         couples de lapins
année 12, 375759064                        couples de lapins
année 13, 1607131777                       couples de lapins
année 14, 6867772003                       couples de lapins
année 15, 29312038802                      couples de lapins
année 16, 125064866411                     couples de lapins
année 17, 534566168010                     couples de lapins
année 18, 2279300060568                    couples de lapins
année 19, 9729615113035                    couples de lapins
année 20, 41523264687092                   couples de lapins

année  0, 5                                couples de lapins
année  1, 58                               couples de lapins
année  2, 291                              couples de lapins
année  3, 1269                             couples de lapins
année  4, 5659                             couples de lapins
année  5, 23479                            couples de lapins
année  6, 100405                           couples de lapins
année  7, 428179                           couples de lapins
année  8, 1824700                          couples de lapins
année  9, 7781082                          couples de lapins
année 10, 33225138                         couples de lapins
année 11, 141951927                        couples de lapins
année 12, 605969799                        couples de lapins
année 13, 2588386228                       couples de lapins
année 14, 11048101909                      couples de lapins
année 15, 47124785789                      couples de lapins
année 16, 201141146217                     couples de lapins
année 17, 858314334674                     couples de lapins
année 18, 3662365287576                    couples de lapins
année 19, 15587581319585                   couples de lapins
année 20, 66577762743763                   couples de lapins

année  0, 5                                couples de lapins
année  1, 58                               couples de lapins
année  2, 196                              couples de lapins
année  3, 1037                             couples de lapins
année  4, 4796                             couples de lapins
année  5, 20254                            couples de lapins
année  6, 86980                            couples de lapins
année  7, 370272                           couples de lapins
année  8, 1573768                          couples de lapins
année  9, 6706728                          couples de lapins
année 10, 28616566                         couples de lapins
année 11, 121932434                        couples de lapins
année 12, 520582880                        couples de lapins
année 13, 2219448500                       couples de lapins
année 14, 9478103902                       couples de lapins
année 15, 40410517375                      couples de lapins
année 16, 172615879603                     couples de lapins
année 17, 736958157130                     couples de lapins
année 18, 3145091883281                    couples de lapins
année 19, 13403762061694                   couples de lapins
année 20, 57174565322057                   couples de lapins

memory : 0 active malloc
```