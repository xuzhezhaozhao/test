function foo (a)
	print("foo", a)
	return coroutine.yield(2 * a)
end

co = coroutine.create( function (a, b)
	print("co-body", a, b)
	local r = foo(a + 1)
	print("co-body", r)
	local r, s = coroutine.yield(a + b, a - b)
	print("co-body", r, s)
	return b, "end"
	end
	)

--print("main", coroutine.resume(co, 1, 10))

--print("main", coroutine.resume(co, 'xr'))

--print("main", coroutine.resume(co, 'x', 'y'))

--print("main", coroutine.resume(co, 'x', 'y'))

function testClosure()
	local a = 1

	function c1()
		a = a + 1
		print(a)
	end

	function c2()
		a = a + 1
		print(a)
	end

	return c1, c2
end

c1, c2 = testClosure()
c3, c4 = testClosure()
c5, c6 = testClosure()
c7, c8 = testClosure()
