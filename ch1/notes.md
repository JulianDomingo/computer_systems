#### 1.1 - Information is bits & context
* All programs are stored as contiguous sequences of bytes in memory. 
    * Files are either text files (consisting entirely of ASCII characters), while all others are binary files.

#### 1.2 - Programs are translated by other programs into different forms
* In order for a program to be run on the system, it must ultimately be translated down into *machine-language instructions*. These instructions are packed into an **executable**. This translation of a source file into an object file (executable) is done by a program called a **compiler driver**. 
    * An example compiler driver: **gcc**
* The translation process (also called the **compilation system**) is completed in 4 phases - note that *each phase is a program in itself*:
    1. Preprocessing
        - Replaces all *#include* directives with the corresponding header file content (generates a *.i file) 
    2. Compilation
        - Translate the resultant *.i file into a *.s file, written in an **assembly-language program**. Useful because assembly-language provides a common output language* for different compilers and languages.
    3. Assembly
        - The assembler translates assembly files into machine-language instructions, packaging them into "**relocatable object programs**" and storing them into *.o files. 
    4. Linking
        - The linker links / merges the executable files of any standard C compiler functions (i.e. printf.o for printf) to the translated program.

#### 1.3 - It pays to understand how compilation systems work
* Despite how well the compilation system produces correct and efficient machine code, basic understanding of the compilation system allows for programmers to:
    1. Optimize program performance (i.e. is a **switch** statement or sequence of **if-else** statements more efficient?) 
    2. Understanding link-time errors
    3. Avoiding security holes (i.e. buffer overflow vulnerabilities)

#### 1.4 - Processors read and interpret instructions stored in memory
* HW organization of a computer system
    * Buses - electrical conduits designed to transfer fixed-sized chunks of bytes across HW components, called **words** and are either **4** or **8** bytes. 
    * I/O Devices - a system's external connections, which are connected to the I/O bus either through a **controller** or **adapter**:
        * Controller - chipsets on the computer's motherboard or I/O device themselves
        * Adapter - card that plugs into the motherboard
    * Main Memory - temporary storage device which holds both the programs and the data the programs manipulate *while* the processor is executing the program. 
        * Physically, memory consists of a collection of DRAM chips (dynamic random access memory)
        * Logically, memory is organized into a linear array of bytes, each with its own unique address starting at 0.
    * Processor - central processing unit which interprets / executes programs in main memory. 
        * At its core is a word-sized program counter (PC), which points to the some machine-language instruction in main memory. The processor executes whatever instruction the PC points to, then increments the PC to point to the subsequent instruction. 
        * The way the processor operates is according to the processor's **instruction set architecture** (ISA)
        * Register file - a small storage device consisting of a collection of word-size registers
        * Example CPU operations:
            * Load: load word from main memory into register
            * Store: store word from register into main memory
            * Operate: perform arithmetic operation (using ALU) of two registers, storing result in register 
            * Jump: copy word from instruction to PC 
    * Data output of a program travels directly from disk into main memory throgh **direct memory access** (DMA)
    * Dataflow of a "Hello World" program:
        1. User types in input to shell to execute the hello.o executable
        2. When user types enter, shell command travels from bus to the register, then to main memory where the processor interprets the command 
        3. The processor knows to read the "hello.o" program from disk and load it into main memory (DMA) 
        4. The process begins executing the program, eventually obtaining the "Hello, world!\n" output and moving it from main memory to the register file, where it eventually gets moved to the display I/O device (in this case the computer's display)

#### 1.5 - Caches Matter
* Want to reduce overhead from copy operations (i.e. data transfers from disk to main memory, main memory to I/O devices) 
* Increasing **processor-memory gap** as semiconductor technology advances:
    * Cheaper and easier to make processors faster as opposed to main memory 
    * Caches eases the processor-memory gap problem by serving as temporary staging areas for information the processor is likely to use in the near feature
    * In order for access speed and smallest size:
        * Register file
        * L1 cache (SRAM)
        * L2 cache (SRAM)
        * L3 cache (SRAM)
        * Main memory (DRAM)
* **Cache Locality**: the idea that a computer system can take advantage the benefits of a very large and a very fast memory devices

#### 1.6 - Storage Devices Form a Hierarchy
* Storage at one level of the memory hierarchy serves as a cache for the next lowest level (i.e. register file is a cache for an L1 cache) 

#### 1.7 - The OS Manages the HW
* 
