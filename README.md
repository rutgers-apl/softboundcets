# SoftBoundCETS for LLVM-9
[WIP] Not ready yet for use with applications

## How to build

1. Get llvm and clang version 9
```

  wget http://releases.llvm.org/9.0.0/llvm-9.0.0.src.tar.xz

  wget http://releases.llvm.org/9.0.0/cfe-9.0.0.src.tar.xz
```

2. Build llvm and clang

```
      tar -xvf llvm-9.0.0.src.tar.xz
      mv llvm-9.0.0.src/ llvm
      tar -xvf cfe-9.0.0.src.tar.xz
      mv cfe-9.0.0.src/* clang
      mkdir build
      cd build
      cmake -DLLVM_ENABLE_PROJECTS=clang -G "Unix Makefiles" ../llvm
      make -j8

```

3. Set env variable LLVM_HOME to the LLVM build directory
```
  export LLVM_HOME=<path to LLVM build>
```

4. Clone softboundcets git repo.
```
  git clone https://github.com/rutgers-apl/softboundcets.git

```

5. If your compiler does not support C++11 by default, add the following line to softboundcets_pass/sbcets/CMakefile

```
  target_compile_feature(SoftBoundCETS PRIVATE cxx_range_for cxx_auto_type)

```

otherwise, use the followng line

```
        target_compile_features(SoftBoundCETS PRIVATE )

```

6. Build the SoftBoundCETS pass. In the softboundcets_pass folder,
execute the following commands

```
  mkdir build
  cd build
  cmake -DCMAKE_BUILD_TYPE="Debug" ../
  make

```

7. Try out the tests in regression_tests directory. Set the following environment variables

```
  export LLVM_HOME=<LLVM build directory>

  export SOFTBOUNDCETS_HOME=<path to the SoftBoundCETS github checkout>

  export LD_LIBRARY_PATH=$SOFTBOUNDCETS_HOME/runtime/obj/

```

and then,
```
  make


```

It should print out the LLVM IR of the test.c file
      
