SORT: 11 2 17 0 16 8 6 15 10 3 21 1 18 9 14 19 12 5 4 20 25 24 23 22 13 7

// In this round we compare each pair and add them to their respective vectors

// After dividing the numbers into two groups, we call the sorting function again, but now only with the winners of the previous round,
// and we repeat the process until we have only 1 winner left, which is the biggest number in the original list.
// We also keep track of the comparissons made in each round, and we can roll back to any previous round to see how the sorting process evolved.

Round 0:
Input: 11 2 17 0 16 8 6 15 10 3 21 1 18 9 14 19 12 5 4 20 25 24 23 22 13 7

A: 11 17 16 15 10 21 18 19 12 20 25 23 13
B: 2  0  8  6  3  1  9  14 5  4  24 22 7
NP: --

// Total comparissons so far: 11
--> Calling recursive function with A: 11 17 16 15 10 21 18 19 12 20 25 23 13

		Round 1:
		Input: 11 17 16 15 10 21 18 19 12 20 25 23 13

		A: 17 16 21 19 20 25
		B: 11 15 10 18 12 23
		NP: 13

		// Total comparissons so far: 11 + 5 = 16
		--> Calling recursive function with A: 17 16 21 19 20 25

				Round 2:
				Input: 17 16 21 19 20 25

				A: 17 21 25
				B: 16 19 20
				NP: --
				newB: 16 19 20

				// Total comparissons so far: 16 + 2 = 18
				--> Calling recursive function with A: 17 21 25

						Round 3:
						Input: 17 21 25

						A: 21
						B: 17
						NP: 25
						newB: 17 25

						// Because we now have only 1 numbers left in A we don't call the recursive function again, instead we start the insertion process.
						// This is the escape condition for the recursion
						SortedA.push_back(A[0])

						// in this case we have (17 in B, 25 in NP).

							Group ---- J(k) ---- Indices in this group ---- Count
								1					J(2)=1			b1 only										1
								2					J(3)=3			b3 down to b2							2
								3					J(4)=5			b5 down to b4							2
								4					J(5)=11			b11 down to b6						6
								5					J(6)=21			b21 down to b12						10

						The Jacobsthal starts with J(1) = 1 => b1 to the SortedA
						SortedA = [17,21]

						Then J(2) = 2 (b3 then b2)
						if no b3, skip to next
						b2 = 25 => now binary-insert (bounds are 0 and SortedA.size())
						return SortedA = [17,21,25]

						// the function returns a vector with the input ordered from smallest to biggest
						// Total comparissons so far: 18 + 2 = 20

				Return to Round 2
				// previous
				A: 17 21 25
				B: 16 19 20
				NP: --

				// new data
				//A     = [a1,a2,a3]
				SortedA = [17,21,25]
				//B = [b1,b2,b3]
				newB = 16 19 20

				// We reorder the original vectors to match the exact pairs of numbers we received from the recursive fucntion. Let's name their items as A=[a1,a2,a3,etc...] and B=[b1,b2,b3,etc...]
				// We now have SortedA. We need to insert each B in the right spot.
				The Jacobsthal starts with J(1) = 1 => b1 to the SortedA
				SortedA = [16,17,21,25]

				Then J(2) = 2 (b3 then b2)
				b3 = 20 => now binary-insert

				--- BINARY SEARCH ---
				Find the limit indexes:
					lower_bound == 0;
					upper_bound should be the index of the A number corresponding the number you are looking for. In this example the upper bound is a3 (25), with index 3
						if no upper bound, upper_bound == SortedA.size() - 1

				While lower_bound ≤ upper_bound:
					Compute mid = floor((low + high) / 2).
					If mid+1 == high && mid==low ==> return mid + 1
					If array[mid] < target (for ascending) → discard left half by setting low = mid + 1.
					Else → discard right half by setting high = mid - 1.
				With the return value we know we need to insert the value on the specific index, pushing all the rest of the numbers to the right

				Now, with the index, we insert the number to SortedA:
				SortedA = [16,17,20,21,25]

				Still with J(2) = 2 (b3 then b2)
				now b2 = 19, same process
				Take a look that now the boundaries change. Lower_bound is still zero but upper_bound is now whenever a2 is. As we just added b3, this upper_bound will also be 2 for the number 21
				SortedA = [16,17,19,20,21,25]
				// With B empty we are ready to return to the previous round

		Return to Round 1

		// previous
		A: 17 16 21 19 20 25
		B: 11 15 10 18 12 23
		NP: 13

		// new data
		// A    = [a1,a2,a3,a4,a5,a6]
		SortedA = [16,17,19,20,21,25]
		// B = [b1,b2,b3,b4,b5,b6,b7]
		newB = [15,11,18,12,10,23,13]

		// #1 => J(1) = 1 => b1 to the SortedA (upperlimit = 0)
		SortedA = [15,16,17,19,20,21,25]
		// #2 => J(2) = 2 => b3 to the SortedA (upperlimit = 3)
		SortedA = [15,16,17,18,19,20,21,25]
		// #3 => J(2) = 2 => b2 to the SortedA (upperlimit = 2)
		SortedA = [11,15,16,17,18,19,20,21,25]
		// #4 => J(3) = 5 => b5 to the SortedA (upperlimit = 7)
		SortedA = [10,11,15,16,17,18,19,20,21,25]
		// #5 => J(3) = 5 => b4 to the SortedA (upperlimit = 7)
		SortedA = [10,11,12,15,16,17,18,19,20,21,25]
		// #6 => J(4) = 11 => b11 to the SortedA
		no b11, skip
		// #7 => J(4) = 11 => b10 to the SortedA
		no b10, skip
		// #8 => J(4) = 11 => b9 to the SortedA
		no b9, skip
		// #9 => J(4) = 11 => b8 to the SortedA
		no b8, skip
		// #10 => J(4) = 11 => b7 to the SortedA  (upperlimit = SortedA.size())
		SortedA = [10,11,12,13,15,16,17,18,19,20,21,25]
		// #11 => J(4) = 11 => b6 to the SortedA  (upperlimit = 11)
		SortedA = [10,11,12,13,15,16,17,18,19,20,21,23,25]
		// With B empty we are ready to return to the previous round (we don't remove the items from the vector to maintain its structure and sequence, so we probably just count how many numbers we are adding and compare to the size of B)


Return to Round 0

// previous
A: 11 17 16 15 10 21 18 19 12 20 25 23 13
B: 2  0  8  6  3  1  9  14 5  4  24 22 7
NP: --

// new data
// A    = [a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13]
SortedA = [10,11,12,13,15,16,17,18,19,20, 21, 23, 25]
// B = [b1,b2,b3,b4,b5,b6,b7,b8,b9,b10,b11,b12,b13]
newB = [3, 2, 5, 7, 6, 8, 0, 9, 14, 4, 1,  22, 24]

// #1 => J(1) = 1 => b1 to the SortedA (upperlimit = 0)
SortedA = [3,10,11,12,13,15,16,17,18,19,20, 21, 23, 25]
// #2 => J(2) = 2 => b3 to the SortedA (upperlimit = 3)
SortedA = [3,5,10,11,12,13,15,16,17,18,19,20, 21, 23, 25]
// #3 => J(2) = 2 => b2 to the SortedA (upperlimit = 3)
SortedA = [2,3,5,10,11,12,13,15,16,17,18,19,20, 21, 23, 25]
// #4 => J(3) = 5 => b5 to the SortedA (upperlimit = 7)
SortedA = [2,3,5,6,10,11,12,13,15,16,17,18,19,20, 21, 23, 25]
// #5 => J(3) = 5 => b4 to the SortedA (upperlimit = 7)
SortedA = [2,3,5,6,7,10,11,12,13,15,16,17,18,19,20, 21, 23, 25]
// #6 => J(4) = 11 => b11 to the SortedA (upperlimit = 15)
SortedA = [1,2,3,5,6,7,10,11,12,13,15,16,17,18,19,20, 21, 23, 25]
// #7 => J(4) = 11 => b10 to the SortedA (upperlimit = 15)
SortedA = [1,2,3,4,5,6,7,10,11,12,13,15,16,17,18,19,20, 21, 23, 25]
// #8 => J(4) = 11 => b9 to the SortedA (upperlimit = 15)
SortedA = [1,2,3,4,5,6,7,10,11,12,13,14,15,16,17,18,19,20, 21, 23, 25]
// #9 => J(4) = 11 => b8 to the SortedA (upperlimit = 15)
SortedA = [1,2,3,4,5,6,7,9,10,11,12,13,14,15,16,17,18,19,20, 21, 23, 25]
// #10 => J(4) = 11 => b7 to the SortedA  (upperlimit = 15)
SortedA = [0,1,2,3,4,5,6,7,9,10,11,12,13,14,15,16,17,18,19,20, 21, 23, 25]
// #11 => J(4) = 11 => b6 to the SortedA  (upperlimit = 15)
SortedA = [0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20, 21, 23, 25]
// #12 => J(5) = 21 => b21 to the SortedA
no b21, skip
...
// #19 => J(5) = 21 => b14 to the SortedA
no b14, skip
// #20 => J(5) = 21 => b13 to the SortedA (upperlimit = 24)
SortedA = [0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,23,24,25]
// #21 => J(5) = 21 => b12 to the SortedA (upperlimit = 23)
SortedA = [0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25]
