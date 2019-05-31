# Questions

## What's `stdint.h`?

The stdint.h header file specifies standard typedefs for fixed width integer types in the C99 ISO Standard.

## What's the point of using `uint8_t`, `uint32_t`, `int32_t`, and `uint16_t` in a program?

Signed and unsigned integer types aid in dynamic memory allocation as a program executes. Types that begin with
'u' are unsigned and the integer in the names specifies the exact number of bits each type must be represented by.

## How many bytes is a `BYTE`, a `DWORD`, a `LONG`, and a `WORD`, respectively?

A BYTE has one byte. A DWORD has four bytes. A LONG has four bytes. A WORD has two bytes.

## What (in ASCII, decimal, or hexadecimal) must the first two bytes of any BMP file be? Leading bytes used to identify file formats (with high probability) are generally called "magic numbers."

The BMP file header contains the first two bytes. These bytes identify the file as a BMP and ensure it is not damaged when it is read by a program. in ASCII encoding the characters are 'B' and 'M'.

## What's the difference between `bfSize` and `biSize`?

The bfSize is the size in bytes of the full BMP file including header and image.
The biSize is the size in bytes of the BITMAPINFOHEADER.

## What does it mean if `biHeight` is negative?

If the biHeight is negative, the device-independent bitmap (DIB) is a top-down file with the origin in the upper left corner. BMP is the image file format of a DIB.

## What field in `BITMAPINFOHEADER` specifies the BMP's color depth (i.e., bits per pixel)?

Offset 28, the biBitCount, specifies the BMP's color depth in bits per pixel.

## Why might `fopen` return `NULL` in `copy.c`?

No file specified in argument (argv[1]).

## Why is the third argument to `fread` always `1` in our code?

The third argument passed to the fread function specifies the number of elements to be read. We are only working with one file.

## What value does `copy.c` assign to `padding` if `bi.biWidth` is `3`?

Zero -- (4 - (3 * 24 % 4) % 4) = (4 - 0) % 4 = 0

## What does `fseek` do?

The fseek function sets a pointer to an offset specified in its second of three parameters. It returns a zero value if successful and a non zero value elsewise.

## What is `SEEK_CUR`?

The fseek function has 'whence' as its third parameter which is specified by one of three constants.
This argument sets the pointer to the position from where the offset is then added by fseek. SEEK_CUR
is the current pointer position in the file.
