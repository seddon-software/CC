Thread operations include thread creation, termination, 
  synchronization (joins,blocking), scheduling, data management 
  and process interaction.  A thread does not maintain a list of 
  created threads, nor does it know the thread that created it.

All threads within a process share the same address space.
Threads in the same process also share:
    User Area:
        Text (Process instructions and constants)
        Static (Globals)
        Heap (Dynamic variables)
        Hole (Memory mapped structures)
    Sys Area:
        open files (descriptors)
        signals and signal handlers
        current working directory
        User and group id
Each thread has a unique:
        Thread ID
        set of registers, stack pointer
        stack for local variables, return addresses
        signal mask
        priority
        Return value: errno
pthread functions return "0" if OK.
