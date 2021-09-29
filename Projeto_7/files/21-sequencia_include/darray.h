/**
  darray.h
  Declarations for a sequence of floats stored in an array that swells and
  shrinks by a factor of 2 as needed.
**/


#ifndef DARRAY_H
#define DARRAY_H


typedef struct darray {

  float* data; // The array of floats.

  int first; // The index of the first element in the sequence.
  int size;  // The sequence size.

  int capacity; // The array size.
  int min_cap;  // The minimum array size.

} darray;



/**
   Create a darray.

   capacity is the initial array size.  It is also the minimum array size.

   It returns the address of a new darray.  On failure it returns NULL.
**/
darray* da_alloc(int capacity);



/**
  Release a darray and its data.
**/
void da_free(darray* A);



/**
   Add a float to the end of the sequence.

   If the array is full, it tries to double its capacity and then adds x.

   On success it returns 1.  Whenever resizing the array is not possible it
   doesn't push and returns 0.
**/
int da_push(darray* A, float x);



/**
   Remove a float from the end of the sequence and return it.

   If the array is 1/4 full, this function halves its capacity and then removes
   the float.  The capacity will never be smaller than the initial capacity.

   If it is not possible to resize then the capacity will remain unchanged.

   If A is empty then the value returned by this function is meaningless.
**/
float da_pop(darray* A);



/**
   Add a float to the beginning of the sequence.

   If the array is full, it tries to double its capacity and then adds x.

   On success it returns 1.  Whenever resizing the array is not possible it
   doesn't inject and returns 0.
**/
int da_inject(darray* A, float x);



/**
   Remove a float from the beginning of the sequence and return it.

   If the array is 1/4 full, this function halves its capacity and then removes
   the float.  The capacity will never be smaller than the initial capacity.

   If it is not possible to resize then the capacity will remain unchanged.

   If A is empty then the value returned by this function is meaningless.
**/
float da_eject(darray* A);



/**
   Return the first float in the sequence.
**/
float da_first(darray* A);



/**
   Return the last float in the sequence.
**/
float da_last(darray* A);



/**
   Return 1 if the sequence is empty, otherwise return 0.
**/
int da_is_empty(darray* A);


#endif
