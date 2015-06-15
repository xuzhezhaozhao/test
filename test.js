
var circle = require('./circle.js')

console.log(circle.area(4));
console.log(circle.PI);

var square = require('./square.js');
var mySquare = square(2);
console.log('The area of my square is ' + mySquare.area());
console.log('The area of my square is ' + mySquare.area());
console.log('The area of my square is ' + mySquare.area());
console.log( require.resolve('./square.js') );

console.log(require.main === module);
