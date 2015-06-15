function testClosure () 

	f = function ()
		print(x)
		x = x + 10
	end

	local x = 10
	return f
end
