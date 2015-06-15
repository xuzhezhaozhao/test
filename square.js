module.exports = function(width) {
	return {
		area: function() {
			width++;
			return width * width;
		}
	};
}
