# Polynomial distinguishers - CPP version

Polynomial randomness detectors, bruteforce, first phase.

## Compilation

CMake 3.2+ is required.

```
mkdir -p build && cd build
CC=gcc CXX=g++ cmake ..
make
```

## Compilation - Aura

At first - you need to install GCC 5.2 for C++ 11. Tutorial outlined here:
http://bakeronit.com/2015/11/04/install_gcc/

```
wget http://ftp.gnu.org/gnu/gcc/gcc-5.2.0/gcc-5.2.0.tar.bz2
tar -xjvf gcc-5.2.0.tar.bz2

module add mpc-0.8.2
module add gmp-4.3.2
module add mpfr-3.0.0

mkdir -p ~/local/gcc-5.2.0
cd local
mkdir gcc-build  # objdir
cd gcc-build
../../gcc-5.2.0/configure --prefix=~/local/gcc-5.2.0/ --enable-languages=c,c++,fortran,go --disable-multilib
make -j4 # spend a long time
make install

# Add either to ~/.bashrc or just invoke on shell
module add mpc-0.8.2
module add gmp-4.3.2
module add mpfr-3.0.0
export PATH=~/local/gcc-5.2.0/bin:$PATH
export LD_LIBRARY_PATH=~/local/gcc-5.2.0/lib:$LD_LIBRARY_PATH
export LD_LIBRARY_PATH=~/local/gcc-5.2.0/lib64:$LD_LIBRARY_PATH
```


Then compile Polynomials distinguishers:
```
module add mpc-0.8.2
module add gmp-4.3.2
module add mpfr-3.0.0
module add cmake-3.6.2
export PATH=~/local/gcc-5.2.0/bin:$PATH
export LD_LIBRARY_PATH=~/local/gcc-5.2.0/lib:$LD_LIBRARY_PATH
export LD_LIBRARY_PATH=~/local/gcc-5.2.0/lib64:$LD_LIBRARY_PATH

mkdir -p build && cd build
CC=gcc CXX=g++ cmake ..
make
```
