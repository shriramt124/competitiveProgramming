## concept 1   
###### let us say we have an array a = [a1,a2,a3,a4,.....an] of length n and we want to take l,r range and want to make the all elements of array to zero find by doing a1^a2^a3 i.e. al^al+1^al+2 .. ^ar so find the no of operations required to do that 

* if n is even i.e. length of array is even then performing xor operations from 1 to n twice all the elements will become zero `so no of operations needed is 2 if n is even`
* if n is odd then we can perform two operations from 1 to n-1 twice so the elements till n-1 will become zero and arr = [0,0,0,0,an] then at the end we can perform two operations on the array an-1^an twice so all the elements will become zero `so no of operations needed is  4 if n is odd `

https://codeforces.com/problemset/problem/1869/A



