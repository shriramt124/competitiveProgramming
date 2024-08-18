let arr = [1,2,3,4];
 
// arr.push(a1);
//  //[ 1, 2, 3, 4, [ 5, 6, 7 ] ]
//  let res = arr.flat(Infinity);

//  console.log(res);
 //push arr
 //[ 1, 2, 3, 4, [ 5, 6, 7 ] ]
 //flat 
 //[
//   1, 2, 3, 4,
//   5, 6, 7
// ]

//har element me jao 
//  let newarr = arr.map((ele)=>{
//     if(ele === 4){
//         return [ele,6,7,8];
//     }else{
//       return  ele;
//     }
//  });
//  console.log(newarr);
 //ele --> 4
 //4 ki jagar []--> 
//  let newarr = arr.flatMap((ele)=>{
//     return [ele,9].flatMap((el)=>{
//         return [el*3];
//     });
//  })
//  console.log(newarr);

 //
//  let newarr = arr.map((ele)=>{
//     return [ele*2];
//  }) 
//  console.log(newarr);


