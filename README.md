# ft_printf

A minimal, 42-school–style reimplementation of the C standard `printf` function.

This project provides:
- A `ft_printf` function that writes formatted output to standard output using only low-level syscalls (write).
- A static library `libftprintf.a` that you can link against in your C projects.

Supported conversions:
- Characters: `%c`
- Strings: `%s`
- Pointers: `%p` (printed as `0x...`)
- Signed decimal: `%d`, `%i`
- Unsigned decimal: `%u`
- Hexadecimal (lowercase): `%x`
- Hexadecimal (uppercase): `%X`
- Percent sign: `%%`

Limitations:
- Width, precision, flags, and length modifiers are not implemented.
- Output goes to `stdout` (file descriptor 1).
- The function returns the number of characters written, or `-1` on error.

---

## Build

The project ships with a simple Makefile.

Targets:
- `make` or `make all` — builds `libftprintf.a`
- `make clean` — removes object files
- `make fclean` — removes object files and the library
- `make re` — full rebuild

Resulting artifact:
- `libftprintf.a`

---

## Usage

1) Build the library:
```bash
make
```

2) Include the header in your source:
```c
#include "ft_printf.h"
```

3) Compile and link:
```bash
cc -Wall -Wextra -Werror your_main.c libftprintf.a -o your_program
# or using -L/-l:
cc -Wall -Wextra -Werror your_main.c -L. -lftprintf -o your_program
```

---

## API

```c
int ft_printf(const char *s, ...);
```

Behavior:
- Parses the format string `s` and consumes variadic arguments.
- Writes to standard output.
- Returns the total number of characters written, or `-1` if a write error occurs.

Note:
- Internal helper functions are declared in `ft_printf.h` for compilation but are not intended to be used directly by external code.

---

## Examples

Basic usage:
```c
#include "ft_printf.h"

int main(void)
{
    int n = 42;
    char *str = "hello";
    void *ptr = str;

    ft_printf("Char: %c\n", 'A');
    ft_printf("String: %s\n", str);
    ft_printf("Signed: %d, %i\n", n, -n);
    ft_printf("Unsigned: %u\n", 3000000000u);
    ft_printf("Hex low: %x\n", 48879);     // beef
    ft_printf("Hex up : %X\n", 48879);     // BEEF
    ft_printf("Pointer: %p\n", ptr);
    ft_printf("Percent: %%\n");

    return 0;
}
```

Expected output (example):
```
Char: A
String: hello
Signed: 42, -42
Unsigned: 3000000000
Hex low: beef
Hex up : BEEF
Pointer: 0x...
Percent: %
```

---

## Repository structure

- `Makefile` — builds the static library
- `ft_printf.h` — public header (API)
- `ft_printf.c` — main formatter and dispatcher
- `ft_putc.c` — character output
- `ft_putstr.c` — string output
- `ft_int.c` — signed integer output (decimal)
- `ft_llu.c` — unsigned integer output (decimal)
- `ft_putlew.c` — lowercase hexadecimal output
- `ft_putup.c` — uppercase hexadecimal output
- `ft_voidx0.c` — pointer output (`0x` prefix + hex)

Library name:
- `libftprintf.a`

Compiler flags (from Makefile):
- `-Wall -Wextra -Werror`

---

## Testing quickly

Create a small test file:
```c
// main.c
#include "ft_printf.h"

int main(void)
{
    int ret = ft_printf("Hello %s (%d) 0x%x %%\n", "world", 42, 0xBEEF);
    ft_printf("Printed %d chars\n", ret);
    return 0;
}
```

Build and run:
```bash
cc -Wall -Wextra -Werror main.c libftprintf.a -o test && ./test
```

---

## Notes

- The project focuses on correctness for the supported conversions and simplicity of implementation.
- Error handling: the function checks write availability early and returns `-1` on error.

---

## Author

- [@otmansabir](https://github.com/otmansabir)
