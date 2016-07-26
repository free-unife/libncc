# libncc
Null Cons Cdr C library. This static ANSI C99 library handles lists, stack and 
queues using a functional programming approach whenever possible.

## Usage
```
$ make libncc TYPE=<typedef struct or native C type>
```
This builds the static library into the `libncc.a` file.

## Example
```
$ make example
$ ./example.out
```

## Full documentation

### TexInfo PDF generation
```
# pacman -S texlive-most
$ make doc
```

The file `libncc.pdf` will be generated on the root directory of this 
repository.

## License and Copyright
Do What The Fuck You Want To Public License, Version 2.
Copyright © 2016 Franco Masotti <franco.masotti@student.unife.it>
