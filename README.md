Correctness test plan:

Test 1:
Requirement tested: malloc() only reserves unallocated memory 
Allocates the entire memory and then attempts to call malloc with a pointer again.
Expected result: NULL is assigned to the pointer:
Not enough space, NULL pointer returned.
(nil)

Test 2:
Requirement tested: malloc() correctly allocates space when there is enough.
Allocates an int pointer and assigns the value 5 to the allocated object and then prints the dereferenced pointer.
Expected result: prints 5:
5

Test 3:
Reuirement tested: free() deallocates memory
Allocates the entire array with a pointer d and then attempts to allocate more space, failing like in Test 2. Then frees the pointer d and attempts to allocate space again with a new pointer and writes a value to the object.
Expected result: The space isn't able to be allocated at first, but then it is after d is freed:
Not enough space, NULL pointer returned.
3.300000

Test 4:
Requirement tested: malloc() and free() arrange so that adjacent free blocks are coalesced.
Allocates 7 pointers l, m, n, o, p, q, r and s each of size 576 such that the entire 4096 byte array is filled (as the headers of each allocated chunk are 8 bytes each). Then frees pointers m and o and attempts to allocate 1744 bytes of space, which should fail. It then frees the pointer n, which pointed to the chunk in between m and o. myfree is expected to coalesce all three of the now adjacent free chunks into one. When malloc is called for 1744 bytes again, it should now have enough space and succeed. It will assign the integer 777 to the space allocated and print the dereferenced pointer.
Expected output: Error message "not enough space, NULL pointer returned" followed by 777:
Not enough space, NULL pointer returned.
777

Test 5: 
Requirement tested: free() cannot be called with an address not obtained from malloc().
Creates a local variable and calls free on it.
Expected result: An error is printed explaining that free() cannot be called with an address not obtained from malloc():
Error in testcode.c on line 105: Called free() with an address not obtained from malloc().

Test 6:
Requirement tested: free() cannot be called with an address not at the start of a chunk.
Allocates a pointer p1 with malloc and then calls free on an address in memory not allocated with malloc by performing pointer arithmetic on p1.
Expected result: An error is printed explaining that free() cannot be called with an address not at the start of a chunk:
Error in testcode.c on line 110: Called free() with an address not at the start of a chunk.

Test 7:
Requirement tested: free() cannot be called a second time on the same pointer.
Allocates a pointer p2, creates a pointer q2 of the same address, calls free on p2 and then on q2.
Expected result: An error is printed explaining that free() cannot be called a second time on the same pointer:
Error in testcode.c on line 118: Called free() a second time on the same pointer.
