#include <stdio.h>
#include <string.h>

// Casts byte_pointer to an unsigned char pointer to circumvent the type system.
typedef unsigned char *byte_pointer;

void 
show_bytes(byte_pointer start, size_t len)
{
    printf("Length: %zu\n", len);

    int i;
    for (i = 0; i < len; i++)
    {
        printf("%.2x", start[i]);
    }

    printf("\n");
}

// The cast to a byte_pointer indicates to the compiler that the program should consider the pointer as a sequence of bytes rather than to an object of the original data type.
void
show_int(int x)
{
    show_bytes((byte_pointer) &x, sizeof(int));
}

void
show_float(float x)
{
    show_bytes((byte_pointer) &x, sizeof(float));
}

void
show_pointer(void *x)
{
    show_bytes((byte_pointer) &x, sizeof(void *));
}

int
main(int argc, char *argv[])
{
    // Example code
    int x_i = 12345;
    float x_f = (float) x_i; 
    int *x_p = &x_i;

    show_int(x_i);
    show_float(x_f);
    show_pointer(x_p);

    // Practice problem 2.7
    const char *s = "abcdef";
    show_bytes((byte_pointer) s, strlen(s));
}
