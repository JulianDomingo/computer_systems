#### Introduction
* Arithmetic overflow is a common source of programming errors and security vulnerabilities.
    * Asymmetric range of negative and positive values in 2's-complement representation
* Floating-point arithmetic is not associative due to the finite precision of the representation.

#### 2.1 - Information Storage
* Most modern computers use blocks of bytes as the **smallest** addressable unit of memory
* All programs view memory as an array of bytes, known as **virtual memory**, and the set of all possible addresses is the **virtual address space**. This is of course abstracted - actual implementation of memory is a combination of many different types of memory.
* **Hexadecimal Notation**
    * Skipped
* **Data Sizes**
    * Every computer has a **word size**, indicating the nominal size of pointer data. For a given machine with a **w**-bit word size, the virtual address space can range from 0 to 2<sup>w</sup> - 1, giving the program access to at most 2<sup>w</sup> bytes.
    * C supports multiple data formats, allocating a varying number of bytes for each type dependent on the machine's bit size for words (32 or 64 bit). 
        * Data types like **int32_t* and **int64_t** are fixed-sized; using these are the best way for programmers to have close control over data representations.
    * C supports floating-point formats for:
        * Single precision -> **float** (32-bit systems)
        * Double precision -> **double** (64-bit systems)
    * With the transition from 32-bit systems to 64-bit systems, C programs **should be written with portability in mind**:
        * Insensitive to the exact sizes of the different data types.
            * Example: can't assume a variable declared as type **int** can *always* be used to store a pointer; this works fine for 32-bit programs, but not for 64-bit programs.
* **Addressing and Byte Ordering**
    * Ordering of bytes:
        * *Little Endian*: least significant byte is stored first in memory
            * For value 0x01234567: 0x100 -> 67, 0x101 -> 45, etc.
        * *Big Endian*: most significant byte is stored first in memory 
            * For value 0x01234567: 0x100 -> 01, 0x101 -> 23, etc.
        * Ordering of bytes becomes a problem / important to be aware of when:
            1. Binary data is communicated over a network between a machine using little endian and a machine using big endian. To avoid the issue of reversed words being received, networking applications must follow establish conventions for byte ordering to preserve the transmitted data's internal representation. 
            2. Looking at the byte sequences representing integer data (when looking at machine code) 
            3. Casting / union of objects 
                * *Strongly* discouraged for application programming, but can be useful for system-level programming
                * Using **sizeof()** is one way to ensure code portability, rather than the known number of bytes used by a certain object.
* **Representing Strings**
    * Text data are more platform independent than binary data (i.e. all characters are encoding using the same ASCII standard). 
* **Representing Code**
    * Code is **not** binary compatible; different machines and different OS have differences in their coding conventions.
* **Bit Level Operations**
    * Masking: a mask is a bit pattern that indicates a selected set of bits within a word.
    *     
