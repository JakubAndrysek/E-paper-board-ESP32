

class GetRequestException(Exception):
	def __init__(self, message="Get Request Exception"):
		self.message = message
		super().__init__(self.message)