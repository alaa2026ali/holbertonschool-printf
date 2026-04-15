# Team printf Project

## Description

This project is a custom implementation of the C standard library function `printf`.
It prints formatted output to the standard output.

Supported conversion specifiers:

* %c : character
* %s : string
* %% : percent sign
* %d : integer
* %i : integer

## Installation

Clone the repository:

```bash
git clone https://github.com/alaa2026ali/holbertonschool-printf
cd holbertonschool-printf
```

Compile the code:

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -Wno-format *.c
```

---

## Requirements

* Ubuntu 20.04 LTS
* gcc compiler

Allowed functions:

* write
* malloc
* free
* va_start
* va_end
* va_arg

Note: `malloc` and `free` are allowed but not used in this implementation.

---

## Examples

```c
_printf("Hello %s\n", "World");
_printf("Number: %d\n", 123);
_printf("Char: %c\n", 'A');
_printf("Percent: %%\n");
```

---

## Testing

Create a temporary test file:

```c
#include "main.h"

int main(void)
{
    _printf("Test: %s\n", "OK");
    _printf("Number: %d\n", 42);
    return (0);
}
```

Compile and run:

```bash
gcc *.c
./a.out
```
