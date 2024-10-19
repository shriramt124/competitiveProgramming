## concept 1   
###### let us say we have an array a = [a1,a2,a3,a4,.....an] of length n and we want to take l,r range and want to make the all elements of array to zero find by doing a1^a2^a3 i.e. al^al+1^al+2 .. ^ar so find the no of operations required to do that 

* if n is even i.e. length of array is even then performing xor operations from 1 to n twice all the elements will become zero `so no of operations needed is 2 if n is even`
* if n is odd then we can perform two operations from 1 to n-1 twice so the elements till n-1 will become zero and arr = [0,0,0,0,an] then at the end we can perform two operations on the array an-1^an twice so all the elements will become zero `so no of operations needed is  4 if n is odd `

https://codeforces.com/problemset/problem/1869/A



## concept 2

Yes, in an array of length 
𝑛
n, the maximum bitwise OR you can obtain by applying the OR operator to any subset of the array elements is equal to the OR of all the elements of the array.

Why is this true?
Bitwise OR sets each bit to 1 if any of the bits in the corresponding position of the operands is 1.

When you OR all the elements of the array together, you include every bit that is set to 1 across all elements of the array. Therefore, the result will have all the bits set that could possibly be set by OR'ing any subset of the array.

OR'ing fewer than all elements will only consider some of the bits (those present in the selected subset), so it can never produce more 1-bits than OR'ing all the elements together.

Thus, the OR of all elements in the array is the largest possible value you can obtain using the bitwise OR operation on any subset of the array.