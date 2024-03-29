## Source Code for the Course [ST0244 Programming Languages](http://www1.eafit.edu.co/asr/cursos/st0244-lenguajes-de-programacion/index.html)

* You can clone this repository by running

    ```bash
    $ git clone https://github.com/asr/st0244-pl.git
    ```

* The source code examples are from the book: Kent D. Lee
(2017). [Foundations of Programming
Languages](https://kentdlee.github.io/PL/build/html/index.html). 2nd
ed. Springer.

### The JCoCo virtual machine

* Install the JCoCo virtual machine following the instructions
  [here](https://kentdlee.github.io/JCoCoPages/_build/html/index.html).

* For generating the `.casm` (CoCo assembly) files it is required
Python 3.2.6. You can use the
[pyenv](https://realpython.com/intro-to-pyenv) tool for managing
multiple Python versions in your system.

* For installing the [pyenv](https://realpython.com/intro-to-pyenv)
  tool in Ubuntu 20.04.5 LTS, I used the following
  [instructions](https://github.com/pyenv/pyenv/issues/945#issuecomment-695777331):

  + To append `deb http://security.ubuntu.com/ubuntu bionic-security
  main` to the `/etc/apt/sources.list` file.

  + To run `sudo apt update && apt-cache policy libssl1.0-dev`.

  + To run `sudo apt-get install libssl1.0-dev`.

* For installing Python 3.2.6 with the
  [pyenv](https://realpython.com/intro-to-pyenv) tool in Ubuntu
  22.04.1 LTS, in addition to the instructions for installing the tool
  in Ubuntu 20.04.5 LTS (see above), I used the following
  [instructions](https://github.com/pyenv/pyenv/issues/2239#issuecomment-1079275184):

  + `$ sudo apt install clang`

  + `$ CC=clang pyenv install 3.2.6`

* The `.casm` files are generated by redirecting the standard output
  to a file, e.g.

    ```bash
    $ python3.2 file.py 1 > file.casm
    ```

* The `coco` command is used for running the JCoCo virtual machine on
  the `.casm` files, e.g.

    ```bash
    $ coco file.casm
    ```

* The `.cpasm` (CoCo post-processed assembly) files are obtained from
JCoCo output when using the `-v` option, e.g.

    ```bash
    $ coco -v file.casm
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
    $ g++-12 --version
    g++-12 (Ubuntu 12.1.0-2ubuntu1~22.04) 12.1.0
    ```

* Haskell files were tested with

    ```bash
    $ ghc --version
    The Glorious Glasgow Haskell Compilation System, version 9.6.3
    ```

* JCoCo and Java files were tested with

    ```bash
    $ javac --version
    javac 21.0.1

    $ java --version
    openjdk 21.0.1 2023-10-17
    ```

* Prolog files were tested with

    ```bash
    $ swipl --version
    SWI-Prolog version 9.0.4 for x86_64-linux
    ```

* Python files were tested with

    ```bash
    $ python --version
    Python 3.2.6
    ```

* Standard ML files were tested with

    ```bash
    $ mlton
    MLton 20210117
    ```
