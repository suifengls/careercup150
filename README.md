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

**2.4:**

	Remember to move forward after assignment of a new node.

**2.5:**
	
	Reference: http://hawstein.com/posts/add-singly-linked-list.html

**3.1:**

	1. Member data and member function can NOT use the same name.

	2. In class/struct, use -> for pointers, and use . for objects.

**3.3:**
	
	Remember the ; in the end of a class definition.

**3.4:**

	A classical example for recursive and OOP.

	Reference: http://hawstein.com/posts/3.4.html

**3.7:**
	
	A example to learn inheritance.

	Reference: https://github.com/xperzy/careerup150/blob/master/3-7.cpp

**4.4:**

	Need to how many nodes in each level.

**4.9:**

	1. The path does not cross a node.

	2. Each node has a vector that contains all the values from its ancestors.

	Reference: http://hawstein.com/posts/4.8.html

**5.1:**

	1. INT_MAX = ~(1 << 31), INT_MIN = (1 << 31)

	2. Get sign-bit, if it is 1 (negative integer), other bis negate, then add 1.

**5.3:**

	In countone(int), while(n > 0) does NOT work for negative numbers to count the number of 1s.