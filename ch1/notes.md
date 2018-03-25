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
        * Disk 
* **Cache Locality**: the idea that a computer system can take advantage the benefits of a very large and a very fast memory devices

#### 1.6 - Storage Devices Form a Hierarchy
* Storage at one level of the memory hierarchy serves as a cache for the next lowest level (i.e. register file is a cache for an L1 cache) 

#### 1.7 - The OS Manages the HW
* Operating System: layer of SW between the application program and the HW 
    * All attempts for an application program to access the HW must first go through the OS
* OS has two main goals:
    1. Protect the HW from misuse by faulty application programs
    2. Provide application programs with simple / uniform mechanisms for manipulating often complicated and wildly different low-level HW devices
* OS can accomplish both goals through the following **abstractions**:
    * Processes
    * Virtual Memory
    * Files
* **Process**: the OS's abstraction for a running program
    * OS provides the illusion that the program is the only one running on the system, and has full access to the processor, main memory, and IO devices.
    * Multicore CPUs can execute several programs simultaneously through **context switches**; the OS keeps track of all state information (a **context**), containing information like the register file, current PC value, and contents of main memory.
* **Kernel**: the portion of the OS code that is always resident in memory, and handles the transitions from one process to another 
    * Control is transferred to the kernel when an application program requires action from the OS (i.e. file read/writes) 
    * The kernel is **NOT** a separate process; rather, it is a collection of code and data structures the OS uses to manage all running processes
* **Threads**: an execution unit of a process which run in the context of the process and share the same code and global data 
    * It's easier to share data between multiple threads compared to multiple processes.
    * Threads are typically more efficient than processes
* **Virtual Memory**: provides each process with the illusion that it has exclusive use of the main memory. 
    * Each process has the same uniform view of memory, known as its **virtual address space**.
    * Virtual Address Space Layout:
        * Program Code and Data: code begins at the same fixed address for all processes, followed by data locations corresponding to global C variables. This is a fixed size.
        * Heap: dynamically sized at run-time as a result of calls to std functions like *malloc* and *free*.
        * Shared Libraries: Code and data for external libraries like std* or math.
        * Stack (user stack): at the top of the virtual address space; compiler uses this to implement function calls
        * Kernel Virtual Memory: topmost region, restricted from R/W from application programs and contains kernel code
* For VM to work, the basic idea is to store the contents of a process's VM on disk and use main memory as a cache for the disk.
* **Files**: a sequence of bytes. **Every** I/O device is modeled as a file. All I/O in the OS is performed by r/w to files using a set of system calls known as **Unix I/O**.
    * Provides application programs with a **uniform view** of all the varied I/O devices

#### 1.8 - Systems Communicate with Other Systems Using Networks
* A network can be viewed as just another I/O device
    * For example, when the computer system copies a sequence of bytes (a word) from main memory to the network adapter, data flows across the network to another machine *instead of a local disk*. 

#### 1.9 - Important Themes
* Amdahl's Law:
    * Consider an application requiring time $T_old$ to execute, requiring some part of the computer a fraction $\alpha$ of this time, and that we improve its performance by a factor of **k**. Thus:
$$
T_new = (1 - \alpha)T_old + \frac{(\alphaT_old)}{k}
$$

And can compute the speedup **S** as $\frac{T_old}{T_new}$, or:
$$
S = \frac{1}{(1 - \alpha) + \frac{\alpha}{k}}
$$
