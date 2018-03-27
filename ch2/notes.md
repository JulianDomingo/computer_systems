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
* **Logical Shifts**
    * Logical: fills the left end with *k* zeros
    * Arithmetic: fills the left end with *k* repetitions of the most significant bit before the shift (i.e. [x<sub>w - 1</sub>, ..., x<sub>w - 2</sub> ..., x<sub>k</sub>])
* **Operator Precendence**: always place parentheses when writing a long mathematical expression with multiple operator types.
#### 2.2 - Integer Representations
* **Conversion between signed and unsigned** 
    * C keeps the underlying bit representation the same.
        * I.e. for a 32-bit machine, unsigned max (4294967295) is -1 when casted to an int. 
    * All numbers are **signed by default**.
        * Must specify **u** during initialization to make unsigned (i.e. int x = 12u;)
    * Conversion can happen **both implicitly and explicitly**:
        * Implicit: data type x is converted to data type y when x is assigned to a variable of data type y
        * Explicit: casting
* **Bit Extension**
    * Add leading zeros to unsigned values
    * Add leading MSB values to 2's-complement values
* Benefit of shifting right *k* times, then shifting left *k* times:
    * Logical shifts: acts as an **in-place mask**
    * Arithmetic shifts: same as logical, but includes sign extension.
* **Bit Truncation**
    * **Truncation can cause overflow for signed integers** 
        * Pay attention to the numerical size of the un-truncated value, and ensure overflow doesn't occur if the value were to be truncated somewhere in the application code. 
* **Avoid use of unsigned numbers when possible for mathematical operations**.
    * Unsigned values are useful when we want to think of words as just collections of bits *with no numeric interpretation*, or implementing mathematical packages.
