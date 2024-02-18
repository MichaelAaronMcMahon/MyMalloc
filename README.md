Correctness test plan:

Test 1:
Requirement tested: malloc() returns pointers that do not overlap with any others, overwriting them.
The allocates the entire memory with objects and fills each one with a distinct byte pattern. It then checks that each object has preserved its byte pattern despite all subsequent writes. 
Expected: 0 errors

Test 2: 
Requirement tested: malloc() only reserves unallocated memory 
Allocates the entire memory and then attempts to call malloc with a pointer again.
Expected result: NULL is assigned to the pointer

Test 3:
Requirement tested: malloc() correctly allocates space when there is enough.
Allocates an int pointer and assigns the value 5 to the allocated object and then prints the dereferenced pointer.
Expected result: prints 5

Test 4:
Reuirement tested: free() deallocates memory
Allocates the entire array with a pointer d and then attempts to allocate more space, failing like in Test 2. Then frees the pointer d and attempts to allocate space again with a new pointer and writes a value to the object.
Expected result: The space isn't able to be allocated at first, but then it is after d is freed. 

Test 5:
Requirement tested: malloc() and free() arrange so that adjacent free blocks are coalesced.
Allocates 5 pointers and prints the sizes and allocated status of each chunk using the helper method printArray(). Then frees the middle 3 pointers and calls printArray() again.
Expected result: printArray() shows an allocated chunk at the beginning, a larger unallocated chunk formed by coalescing the three adjacent freed chunks in the middle, an allocated chunk at the end and a large unallocated chunk which represents the rest of the memory.

Test 6: 
Requirement tested: free() cannot be called with an address not obtained from malloc().
Creates a local variable and calls free on it.
Expected result: An error is printed explaining that free() cannot be called with an address not obtained from malloc().

Test 7:
Requirement tested: free() cannot be called with an address not at the start of a chunk.
Allocates a pointer p1 with malloc and then calls free on an address in memory not allocated with malloc by performing pointer arithmetic on p1.
Expected result: An error is printed explaining that free() cannot be called with an address not at the start of a chunk.

Test 8:
Requirement tested: free() cannot be called a second time on the same pointer.
Allocates a pointer p2, creates a pointer q2 of the same address, calls free on p2 and then on q2.
Expected result: An error is printed explaining that free() cannot be called a second time on the same pointer.
