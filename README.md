careercup150
============

Problems in CareerCup 150

Solving problems every day.

Enjoy!

Something to remember:
---

**1.2**

	1. strlen() returns the length of the string, exclude '\0'.

	2. void swap(a, b) {a = a^b; b = a^b; a = a^b;} has bug in swap(a, a).
	  
**1.4:**

	Is the size of given string just enough to store the final string?
	Or the size is larger than what we need? 
	(count the number of spaces first, then j = length + spaces * 2 - 1)

**1.6:**

	1. Use a picture to figure the rotating index.

	2. Do NOT use special case as the example.

**1.7:**

	No need to check row[] and col[] separately.
	for i -> for j -> if(row[i] || col[j]) {Mat[i][j] = 0;}

**2.1:**

	After remove a node, remember to deallocate this node space (use a temperary pointer).

**2.2:**
	
	Check with interviewers the given values in the questions.
	(Will it execced ...? Will it be negative? ...)