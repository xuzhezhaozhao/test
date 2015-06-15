len = process.argv.length
argv = process.argv

var sum = 0
for (var i = 2; i < len; i++) {
	sum += Number(argv[i])
}
console.log(sum)
