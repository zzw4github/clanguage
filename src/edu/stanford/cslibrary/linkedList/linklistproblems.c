#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// 1 — Count()
void CountTest() {
List myList = BuildOneTwoThree(); // build {1, 2, 3}
int count = Count(myList, 2); // returns 1 since there's 1 '2' in the list
}
/*
Given a list and an int, return the number of times that int occurs
in the list.
*/
int Count(struct node* head, int searchFor) {
	struct node* current = head;
	int count = 0;

	while(current != NULL)
	{
		if(current -> data == searchFor) count++;
		current = current -> next;
	}

	return count;
}

int Count2(struct node* head, int searchFor) {
	struct node* current ;
	int count = 0;

	for (current = head; current != NULL; current = current -> nexe) {
		if (current -> data == searchFor) count++;
	}

	return count;
}


// 2 — GetNth()

void GetNthTest() {
	struct node* myList = BuildOneTwoThree(); // build {1, 2, 3}
	int lastNode = GetNth(myList, 2); // returns the value 3
}

// Given a list and an index, return the data
// in the nth node of the list. The nodes are numbered from 0.
// Assert fails if the index is invalid (outside 0..lengh-1).
int GetNth(struct node* head, int index) {
// Your code
	struct node* current = head;
	int count = 0; //the index of the node we're currently looking as

	while (current != NULL) {
		if (count == index) return (current -> data);
		count++;
		current = current -> next;
	}

	asset(0);// if we get to this line ,the caller was asking
			 // for a non-existent element so we assert fail.
}

// 3 — DeleteList()

void DeleteListTest() {
	struct node* myList = BuildOneTwoThree(); // build {1, 2, 3}
	DeleteList(&myList); // deletes the three nodes and sets myList to NULL
}

void DeleteList(struct node** headRef) {
// Your code
	struct node* current = *headRef; // deref headRef to get the real head.
	struct node* next;

	while(current != null) {
		next = current -> next;  //note the next pointer
		free(current);			 //delete the node
		current = next;          //advance to the next node
	}

	*headRef = NULL; //Again, deref headRef to affect the read head back
					 //in the caller.
}

// 4 - Pop()
void PopTest() {
	struct node* head = BuildOneTwoThree(); // build {1, 2, 3}
	int a = Pop(&head); // deletes "1" node and returns 1
	int b = Pop(&head); // deletes "2" node and returns 2
	int c = Pop(&head); // deletes "3" node and returns 3
	int len = Length(head); // the list is now empty, so len == 0
}

/*
The opposite of Push(). Takes a non-empty list
and removes the front node, and returns the data
which was in that node.
*/
int Pop(struct node** headRef) {
// your code...
	struct node* head;
	int result;

	head = *headRef;
	assert(head != NULL);

	result = head -> data; // pull out hte data before the node is deleted

	*headRef = head -> next; // unlink the head node for the caller
							 // Note the * --uses a referenct-pointer
							 // just like Push() and DeleteList().

	free(head);			     // free the head node

	return(result);          // don't foget to return the data from the link
}

// 5 — InsertNth()
void InsertNthTest() {
	struct node* head = NULL; // start with the empty list
	InsertNth(&head, 0, 13); // build {13)
	InsertNth(&head, 1, 42); // build {13, 42}
	InsertNth(&head, 1, 5); // build {13, 5, 42}
	DeleteList(&head); // clean up after ourselves
}

/*
A more general version of Push().
Given a list, an index 'n' in the range 0..length,
and a data element, add a new node to the list so
that it has the given index.
*/
void InsertNth(struct node** headRef, int index, int data) {
  // position 0 is a special cas ...
	if (index == 0) Push(headRef, data);
	else {
		struct  node* current = *headRef;
		int i;

		for (i = 0; i < index -1; i++) {
			assert(current != NULL); // if this fails, index was to big
			current = current -> next;
		}

		assert(current != NULL); // tricky: you have to check one last time
		
		Push(&(current -> next), data); //tricky use of Push() --
										// The pointer being pushed on isn not
										// in the stack, But actually this works
										// fin -- Push() works for any node pointer
	}

}

// 6 — SortedInsert()
// Uses special case code for the head end
void SortedInsert(struct node** headRef, struct node* newNode) {
// Special case for the head end
	if (*headRef == NULL || (*headRef)->data >= newNode->data) {
		newNode->next = *headRef;
		*headRef = newNode;
	}
	else {
		// Locate the node before the point of insertion
		struct node* current = *headRef;
		while (current->next!=NULL && current->next->data<newNode->data) {
			current = current->next;
		}
		newNode->next = current->next;
		current->next = newNode;
	}
}

// Dummy node strategy for the head end
void SortedInsert2(struct node** headRef, struct node* newNode) {
	struct node dummy;
	struct node* current = &dummy;
	dummy.next = *headRef;
	while (current->next!=NULL && current->next->data<newNode->data) {
		current = current->next;
	}
	newNode->next = current->next;
	current->next = newNode;
	*headRef = dummy.next;
}

// Local references strategy for the head end
void SortedInsert3(struct node** headRef, struct node* newNode) {
	struct node** currentRef = headRef;
	while (*currentRef!=NULL && (*currentRef)->data<newNode->data) {
		currentRef = &((*currentRef)->next);
	}
	newNode->next = *currentRef; // Bug: this line used to have
	// an incorrect (*currRef)->next
	*currentRef = newNode;
}

// 7 — InsertSort()
// Given a list, change it to be in sorted order (using SortedInsert()).
void InsertSort(struct node** headRef) {
	struct node* result = NULL; // build the answer here
	struct node* current = *headRef; // iterate over the original list
	struct node* next;
	while (current!=NULL) {
		next = current->next; // tricky - note the next pointer before we change it
		SortedInsert(&result, current);
		current = next;
	}
	*headRef = result;
}


// 8 - Append()
// Append 'b' onto the end of 'a', and then set 'b' to NULL.
void Append(struct node** aRef, struct node** bRef) {
	struct node* current;
	if (*aRef == NULL) { // Special case if a is empty
		*aRef = *bRef;
	}
	else { // Otherwise, find the end of a, and append b there
		current = *aRef;
		while (current->next != NULL) { // find the last node
			current = current->next;
		}
		current->next = *bRef; // hang the b list off the last node
	}
	*bRef=NULL; // NULL the original b, since it has been appended above
}

void AppendTest() {
	struct node* a;
	struct node* b;
	// set a to {1, 2}
	// set b to {3, 4}
	Append(&a, &b);
}

// 9 — FrontBackSplit()
/*
Split the nodes of the given list into front and back halves,
and return the two lists using the reference parameters.
If the length is odd, the extra node should go in the front list.
*/
// Uses the "count the nodes" strategy
void FrontBackSplit(struct node* source,
struct node** frontRef, struct node** backRef) {
	int len = Length(source);
	int i;
	struct node* current = source;
	25
	if (len < 2) {
		*frontRef = source;
		*backRef = NULL;
	}
	else {
		int hopCount = (len-1)/2; //(figured these with a few drawings)
		for (i = 0; i<hopCount; i++) {
			current = current->next;
		}
		// Now cut at current
		*frontRef = source;
		*backRef = current->next;
		current->next = NULL;
	}
}

// Uses the fast/slow pointer strategy
void FrontBackSplit2(struct node* source,
	struct node** frontRef, struct node** backRef) {
	struct node* fast;
	struct node* slow;
	if (source==NULL || source->next==NULL) { // length < 2 cases
		*frontRef = source;
		*backRef = NULL;
	}
	else {
		slow = source;
		fast = source->next;
		// Advance 'fast' two nodes, and advance 'slow' one node
		while (fast != NULL) {
			fast = fast->next;
			if (fast != NULL) {
				slow = slow->next;
			fast = fast->next;
			}
		}
		// 'slow' is before the midpoint in the list, so split it in two
		// at that point.
		*frontRef = source;
		*backRef = slow->next;
		slow->next = NULL;
	}
}

// 10 RemoveDuplicates()
// Remove duplicates from a sorted list
void RemoveDuplicates(struct node* head) {
	struct node* current = head;
	if (current == NULL) return; // do nothing if the list is empty
	// Compare current node with next node
	while(current->next!=NULL) {
		if (current->data == current->next->data) {
			struct node* nextNext = current->next->next;
			free(current->next);
			current->next = nextNext;
		}
		else {
			current = current->next; // only advance if no deletion
		}
	}
}

// 11 — MoveNode()
void MoveNodeTest() {
	struct node* a = BuildOneTwoThree(); // the list {1, 2, 3}
	struct node* b = BuildOneTwoThree();
	MoveNode(&a, &b);
	// a == {1, 1, 2, 3}
	// b == {2, 3}
}
/*
Take the node from the front of the source, and move it to
the front of the dest.
It is an error to call this with the source list empty.
*/
void MoveNode(struct node** destRef, struct node** sourceRef) {
	struct node* newNode = *sourceRef; // the front source node
	assert(newNode != NULL);
	*sourceRef = newNode->next; // Advance the source pointer
	newNode->next = *destRef; // Link the old dest off the new node
	*destRef = newNode; // Move dest to point to the new node
}

// 12 — AlternatingSplit()
/*
Given the source list, split its nodes into two shorter lists.
If we number the elements 0, 1, 2, ... then all the even elements
should go in the first list, and all the odd elements in the second.
The elements in the new lists may be in any order.
*/
void AlternatingSplit(struct node* source,
struct node** aRef, struct node** bRef) {
	struct node* a = NULL; // Split the nodes to these 'a' and 'b' lists
	struct node* b = NULL;
	struct node* current = source;
	while (current != NULL) {
		MoveNode(&a, &current); // Move a node to 'a'
		if (current != NULL) {
			MoveNode(&b, &current); // Move a node to 'b'
		}
	}
	*aRef = a;
	*bRef = b;
}

void AlternatingSplit2(struct node* source,
struct node** aRef, struct node** bRef) {
	struct node aDummy;
	struct node* aTail = &aDummy; // points to the last node in 'a'
	struct node bDummy;
	struct node* bTail = &bDummy; // points to the last node in 'b'
	struct node* current = source;
	aDummy.next = NULL;
	bDummy.next = NULL;
	while (current != NULL) {
		MoveNode(&(aTail->next), &current); // add at 'a' tail
		aTail = aTail->next; // advance the 'a' tail
		if (current != NULL) {
			MoveNode(&(bTail->next), &current);
			bTail = bTail->next;
		}
	}
	*aRef = aDummy.next;
	*bRef = bDummy.next;
}

// 13— ShuffleMerge()
/*
Merge the nodes of the two lists into a single list taking a node
alternately from each list, and return the new list.
*/
struct node* ShuffleMerge(struct node* a, struct node* b) {
	struct node dummy;
	struct node* tail = &dummy;
	dummy.next = NULL;
	while (1) {
		if (a==NULL) { // empty list cases
			tail->next = b;
			break;
		}
		else if (b==NULL) {
			tail->next = a;
			break;
		}
		else { // common case: move two nodes to tail
			tail->next = a;
			tail = a;
			a = a->next;
			tail->next = b;
			tail = b;
			b = b->next;
		}
	}
	return(dummy.next);
}

// SuffleMerge() — Dummy Node Using MoveNode()
// Basically the same as above, but use MoveNode().
struct node* ShuffleMerge2(struct node* a, struct node* b) {
	struct node dummy;
	struct node* tail = &dummy;
	dummy.next = NULL;
	while (1) {
		if (a==NULL) {
			tail->next = b;
			break;
		}
		else if (b==NULL) {
			tail->next = a;
			break;
		}
		else {
			MoveNode(&(tail->next), &a);
			tail = tail->next;
			MoveNode(&(tail->next), &b);
			tail = tail->next;
		}
	}
	return(dummy.next);
}

// SuffleMerge() — Local References
// Uses a local reference to get rid of the dummy nodes entirely.
struct node* ShuffleMerge3(struct node* a, struct node* b) {
	struct node* result = NULL;
	struct node** lastPtrRef = &result;
	while (1) {
		if (a==NULL) {
			*lastPtrRef = b;
			break;
		}
		else if (b==NULL) {
			*lastPtrRef = a;
			break;
		}
		else {
			MoveNode(lastPtrRef, &a);
			lastPtrRef = &((*lastPtrRef)->next);
			MoveNode(lastPtrRef, &b);
			lastPtrRef = &((*lastPtrRef)->next);
		}
	}
	return(result);
}

// SuffleMerge() — Recursive
// The recursive solution is the most compact of all, but is probably not appropriate for
// production code since it uses stack space proportionate to the lengths of the lists.
struct node* ShuffleMerge4(struct node* a, struct node* b) {
	struct node* result;
	struct node* recur;
	if (a==NULL) return(b); // see if either list is empty
	else if (b==NULL) return(a);
	else {
		// it turns out to be convenient to do the recursive call first --
		// otherwise a->next and b->next need temporary storage.
		recur = ShuffleMerge(a->next, b->next);
		result = a; // one node from a
		a->next = b; // one from b
		b->next = recur; // then the rest
		return(result);
	}
}
// 14 — SortedMerge()
/*
Takes two lists sorted in increasing order, and
splices their nodes together to make one big
sorted list which is returned.
*/
struct node* SortedMerge(struct node* a, struct node* b) {
	struct node dummy; // a dummy first node to hang the result on
	struct node* tail = &dummy; // Points to the last result node --
	// so tail->next is the place to add
	// new nodes to the result.
	dummy.next = NULL;
	while (1) {
		if (a == NULL) { // if either list runs out, use the other list
			tail->next = b;
			break;
		}
		else if (b == NULL) {
			tail->next = a;
			break;
		}

		if (a->data <= b->data) {
			MoveNode(&(tail->next), &a);
		}
		else {
			MoveNode(&(tail->next), &b);
		}
		tail = tail->next;
	}
return(dummy.next);
}

// SortedMerge() Using Local References

struct node* SortedMerge2(struct node* a, struct node* b) {
	struct node* result = NULL;
	struct node** lastPtrRef = &result; // point to the last result pointer
	while (1) {
		if (a==NULL) {
			*lastPtrRef = b;
			break;
		}
		else if (b==NULL) {
			*lastPtrRef = a;
			break;
		}
		if (a->data <= b->data) {
			MoveNode(lastPtrRef, &a);
		}
		else {
			MoveNode(lastPtrRef, &b);
		}
		lastPtrRef = &((*lastPtrRef)->next); // tricky: advance to point to
		// the next ".next" field
	}
	return(result);
}

// SortedMerge() Using Recursion

struct node* SortedMerge3(struct node* a, struct node* b) {
	struct node* result = NULL;
	// Base cases
	if (a==NULL) return(b);
	else if (b==NULL) return(a);
	// Pick either a or b, and recur
	if (a->data <= b->data) {
		result = a;
		result->next = SortedMerge3(a->next, b);
	}
	else {
		result = b;
		result->next = SortedMerge3(a, b->next);
	}
	return(result);
}

// 15 — MergeSort()
void MergeSort(struct node** headRef) {
	struct node* head = *headRef;
	struct node* a;
	struct node* b;
	// Base case -- length 0 or 1
	if ((head == NULL) || (head->next == NULL)) {
		return;
	}
	FrontBackSplit(head, &a, &b); // Split head into 'a' and 'b' sublists
	// We could just as well use AlternatingSplit()
	MergeSort(&a); // Recursively sort the sublists
	MergeSort(&b);
	*headRef = SortedMerge(a, b); // answer = merge the two sorted lists together
}
// 16 — SortedIntersect()
/*
Compute a new sorted list that represents the intersection
of the two given sorted lists.
*/

// This solution uses the temporary dummy to build up the result list
struct node* SortedIntersect(struct node* a, struct node* b) {
	struct node dummy;
	struct node* tail = &dummy;
	dummy.next = NULL;
	// Once one or the other list runs out -- we're done
	while (a!=NULL && b!=NULL) {
		if (a->data == b->data) {
			Push((&tail->next), a->data);
			tail = tail->next;
			a = a->next;
			b = b->next;
		}
		else if (a->data < b->data) { // advance the smaller list
			a = a->next;
		}
		else {
			b = b->next;
		}
	}
	return(dummy.next);
}

// This solution uses the local reference
struct node* SortedIntersect2(struct node* a, struct node* b) {
	struct node* result = NULL;
	struct node** lastPtrRef = &result;
	// Advance comparing the first nodes in both lists.
	// When one or the other list runs out, we're done.
	while (a!=NULL && b!=NULL) {
		if (a->data == b->data) { // found a node for the intersection
			Push(lastPtrRef, a->data);
			lastPtrRef = &((*lastPtrRef)->next);
			a=a->next;
			b=b->next;
		}
		else if (a->data < b->data) { // advance the smaller list
			a=a->next;
		}
		else {
			b=b->next;
		}
	}
	return(result);
}

// 17 — Reverse()
void ReverseTest() {
	struct node* head;
	head = BuildOneTwoThree();
	Reverse(&head);
	// head now points to the list {3, 2, 1}
	DeleteList(&head); // clean up after ourselves
}

/*
Reverse the given linked list by changing its .next pointers and
its head pointer. Takes a pointer (reference) to the head pointer.
*/

/*
Iterative list reverse.
Iterate through the list left-right.
Move/insert each node to the front of the result list --
like a Push of the node.
*/
static void Reverse(struct node** headRef) {
	struct node* result = NULL;
	struct node* current = *headRef;
	struct node* next;
	while (current != NULL) {
		next = current->next; // tricky: note the next node
		current->next = result; // move the node onto the result
		result = current;
		current = next;
	}
	*headRef = result;
}

static void Reverse2(struct node** headRef) {
	struct node* result = NULL;
	struct node* current = *headRef;
	while (current != NULL) {
		MoveNode(&result, &current);
	}
	*headRef = result;
}

// Finally, here's the back-middle-front strategy...
// Reverses the given linked list by changing its .next pointers and
// its head pointer. Takes a pointer (reference) to the head pointer.
void Reverse(struct node** headRef) {
	if (*headRef != NULL) { // special case: skip the empty list
		/*
		Plan for this loop: move three pointers: front, middle, back
		down the list in order. Middle is the main pointer running
		down the list. Front leads it and Back trails it.
		For each step, reverse the middle pointer and then advance all
		three to get the next node.
		*/
		struct node* middle = *headRef; // the main pointer
		struct node* front = middle->next; // the two other pointers (NULL ok)
		struct node* back = NULL;
		while (1) {
			middle->next = back; // fix the middle node
			if (front == NULL) break; // test if done
			back = middle; // advance the three pointers
			middle = front;
			front = front->next;
		}
		*headRef = middle; // fix the head pointer to point to the new front
	}
}

// 18 — RecursiveReverse()
/*
Recursively reverses the given linked list by changing its .next
pointers and its head pointer in one pass of the list.
*/
void RecursiveReverse(struct node** headRef) {
	struct node* first;
	struct node* rest;
	if (*headRef == NULL) return; // empty list base case
	first = *headRef; // suppose first = {1, 2, 3}
	rest = first->next; // rest = {2, 3}
	if (rest == NULL) return; // empty rest base case
	RecursiveReverse(&rest); // Recursively reverse the smaller {2, 3} case
	// after: rest = {3, 2}
	first->next->next = first; // put the first elem on the end of the list
	first->next = NULL; // (tricky step -- make a drawing)
	*headRef = rest; // fix the head pointer
}

/*
 Basic Utility Function Implementations
 Here is the source code for the basic utility functions.
 */

// Length()

// Return the number of nodes in a list
int Length(struct node* head) {
	int count = 0;
	struct node* current = head;
	while (current != NULL) {
		count++;
		current=current->next;
	}
	return(count);
}

// Push()

// Given a reference (pointer to pointer) to the head
// of a list and an int, push a new node on the front of the list.
// Creates a new node with the int, links the list off the .next of the
// new node, and finally changes the head to point to the new node.
void Push(struct node** headRef, int newData) {
	struct node* newNode =
	(struct node*) malloc(sizeof(struct node)); // allocate node
	newNode->data = newData; // put in the data
	newNode->next = (*headRef); // link the old list off the new node
	(*headRef) = newNode; // move the head to point to the new node
}

// BuildOneTwoThree()

// Build and return the list {1, 2, 3}
struct node* BuildOneTwoThree() {
	struct node* head = NULL; // Start with the empty list
	Push(&head, 3); // Use Push() to add all the data
	Push(&head, 2);
	Push(&head, 1);
	return(head);
}

int main()
{
	struct node* node = BuildWith
}