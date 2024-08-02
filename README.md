## Source Code for the Course [ST0244 Programming Languages](http://www1.eafit.edu.co/asr/cursos/st0244-lenguajes-de-programacion/index.html)

* You can clone this repository by running

    ```bash
    $ git clone https://github.com/asr/st0244-pl.git
    ```

### Local compilation options

You can create the `.gitignored` file `mk/config.mk` for defining your
local compilation options. See `oop/Makefile`'s for details. An example of
this file is the following:

```bash
$ cat mk/config.mk
CXX_AUX      := g++-12
CXXFLAGS_AUX := -Wall -Wextra -Werror -std=c++23
```

### Tested with

* Assembler files were tested with

    ```bash
    $ nasm --version
    NASM version 2.16.01
    ```

* C++ files were tested with

    ```bash
    $ g++-13 --version
    g++-13 (Ubuntu 13.1.0-8ubuntu1~22.04) 13.1.0
    ```

* Haskell files were tested with

    ```bash
    $ ghc --version
    The Glorious Glasgow Haskell Compilation System, version 9.6.3
    ```

* Java files were tested with

    ```bash
    $ javac --version
    javac 21.0.1

    $ java --version
    openjdk 21.0.1 2023-10-17
    ```

* Pascal files were tested with Free Pascal Compiler

    ```bash
    $ fpc -iV
    3.2.2
    ```

* Prolog files were tested with

    ```bash
    $ swipl --version
    SWI-Prolog version 9.0.4 for x86_64-linux
    ```

* Python files were tested with

    ```bash
    $ python --version
    Python 3.10.12
    ```

* Scheme files were tested with

    ```bash
    $ mit-scheme --version
    MIT/GNU Scheme 12.1
    ```

* Standard ML files were tested with

    ```bash
    $ mlton
    MLton 20210117
    ```
