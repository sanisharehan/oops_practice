def isValid(s):
	brk_map = {'{':'}', '[':']', '(':')'}
	in_s = list(s)
	#return false for odd length string
	if ((len(in_s)%2) != 0):
		return False
	index = 0
	while(index < len(in_s)):
		ele = in_s[index]
		if ele in brk_map:
			if (in_s[index+1] == brk_map[ele]):
				index = index+2
			else:
				return False
	return True

print isValid("((")
print isValid("(){}[")
print isValid("((()))")
print isValid("[]{}{}()[]")			
