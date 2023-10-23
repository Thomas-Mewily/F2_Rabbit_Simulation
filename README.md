
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


Output :

```c
Compiled at 11:39:12 
Verification : passed
sizeof(fmax  ) = 16 bytes
simPi(           1) = 4.0000000
simPi(          10) = 2.8000000
simPi(         100) = 3.2400000
simPi(        1000) = 3.1120000
simPi(       10000) = 3.1580000
simPi(      100000) = 3.1436000
simPi(     1000000) = 3.1443440
simPi(    10000000) = 3.1411216
simPi(   100000000) = 3.1412814

simPi_interval_confiance(    10000000 lancés,   1 repetitions n, 12.7060000 t_coef) => pi= 3.1424336 +/-       nan
simPi_interval_confiance(    10000000 lancés,   2 repetitions n, 4.3030000 t_coef) => pi= 3.1422224 +/- 0.0030637
simPi_interval_confiance(    10000000 lancés,  10 repetitions n, 2.2280000 t_coef) => pi= 3.1414216 +/- 0.0003632
simPi_interval_confiance(    10000000 lancés,  20 repetitions n, 2.0860000 t_coef) => pi= 3.1416833 +/- 0.0002582
simPi_interval_confiance(    10000000 lancés,  30 repetitions n, 2.0420000 t_coef) => pi= 3.1416286 +/- 0.0001839
simPi_interval_confiance(    10000000 lancés,  40 repetitions n, 2.0210000 t_coef) => pi= 3.1414813 +/- 0.0001389

moyenne(somme(10, simPi(        1000))) = 3.1612000 , différence absolue avec M_PI : 0.0196073
moyenne(somme(10, simPi(     1000000))) = 3.1420428 , différence absolue avec M_PI : 0.0004501
moyenne(somme(10, simPi(  1000000000))) = 3.1415698 , différence absolue avec M_PI : 0.0000228

memory : 0 active malloc
```