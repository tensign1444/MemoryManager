
# Memory Manager

Operating Systems provide a heaps for the kernel and processes to allocate and free large blocks of memory. These heaps are controlled by an operating system component called the Memory Manager. There may be multiple memory managers running simultaneously, some that run as privileged code for the operating system itself and others that manage heaps that individual processes can use. Depending on where the memory manager is running, it may deal with virtual addresses or with physical addresses. It may have to perform address translation itself, or rely on some other software/hardware component.


## Documentation

[Documentation](https://github.com/tensign1444/MemoryManager/blob/v2.0.0/Documentation.pdf)


## Installation

There are two ways to install this onto your machine.

1.)If you would like to use it as a library, add the include folder to your directory and include the .h files. Then add the static library file to your bin folder. 

2.)The other installation process would be cloning the repository and then building it with cmake.

    
## Authors

- [@tensign1444](https://github.com/tensign1444)
- [@michaelVaquilar](https://github.com/michaelVaquilar)
- [@Masa-dotcom](https://github.com/Masa-dotcom)


## Feedback

If you have any feedback, please create an [Issue](https://github.com/tensign1444/CDataStructures/issues).

