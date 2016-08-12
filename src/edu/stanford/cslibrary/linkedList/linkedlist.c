#include <stdio.h>
#include <stdlib.h>

struct node 
{
	int data;
	struct node* next;
};

/*
Build the list {1, 2, 3} in the heap and store
its head pointer in a local stack variable.
Returns the head pointer to the caller.

*/

struct node* BuildOneTwoThree()
{
	struct node* head = NULL; //为什么要是一个指针呢？
	struct node* second = NULL;
	struct node* third = NULL;

	head = malloc(sizeof(struct node));
	second = malloc(sizeof(struct node));
	third = malloc(sizeof(struct node));

	head -> data = 1;
	head -> next = second;

	second -> data = 2;
	second -> next = third;

	third -> data = 3;
	third -> next = NULL;

	//At this point , the linked list referenced by "head"
	//matches the list in the drawing.
	return head;
};

/*
Given a linked list head pointer, compute 
and return the number of nodes in the list/
*/

int Length(struct node* head) 
{
	struct node* current = head;
	int count = 0;

	while(current != NULL)
	{
		count++;
		current = current -> next;
	}

	return count;
	
}

void LengthTest()
{
	struct node* myList = BuildOneTwoThree();
	int len = Length(myList);
	printf("%d\n", len);
		
}

/*
Takes a list and a data value.
Creates a new link with the given data and pushes
it onto the front of the list.
The list is not passed in by its head pointer.
Instead the list is passed in as a "reference" pointer
to the head pointer -- this allows us
to modify the caller's memory.
*/
void Push(struct node** headRef, int data) 
{
	struct node* newNode = malloc(sizeof(struct node));
	newNode->data = data;
	newNode->next = *headRef; // The '*' to dereferences back to the real head
	*headRef = newNode; // ditto
}

// Change the passed in head pointer to be NULL
// Uses a reference pointer to access the caller's memory
void ChangeToNull(struct node** headRef) { // Takes a pointer to
	// the value of interest
	*headRef = NULL; // use '*' to access the value of interest
}
void ChangeCaller() {
	struct node* head1;
	struct node* head2;
	ChangeToNull(&head1); // use '&' to compute and pass a pointer to
	ChangeToNull(&head2); // the value of interest
	// head1 and head2 are NULL at this point
}

// 3) Build — At Head With Push()
struct node* AddAtHead() {
	struct node* head = NULL;
	int i;
	for (i=1; i<6; i++) {
	Push(&head, i);
	}
	// head == {5, 4, 3, 2, 1};
	return(head);
}

// 5. Build — Special Case + Tail Pointer
struct node* BuildWithSpecialCase() {
	struct node* head = NULL;
	struct node* tail;
	int i;
	// Deal with the head node here, and set the tail pointer
	Push(&head, 1);
	tail = head;
	// Do all the other nodes using 'tail'
	for (i=2; i<6; i++) {
		Push(&(tail->next), i); // add node at tail->next
		tail = tail->next; // advance tail to point to last node
	}
	return(head); // head == {1, 2, 3, 4, 5};
}

// 6. Build — Temporary Dummy Node

struct node* BuildWithDummyNode() {
	struct node dummy; // Dummy node is temporarily the first node
	struct node* tail = &dummy; // Start the tail at the dummy.
	// Build the list on dummy.next (aka tail->next)
	int i;
	dummy.next = NULL;
	for (i=1; i<6; i++) {
		Push(&(tail->next), i);
		tail = tail->next;
	}
	// The real result list is now in dummy.next
	// dummy.next == {1, 2, 3, 4, 5};
	return(dummy.next);
}

// 7. Build — Local References
struct node* BuildWithLocalRef() {
struct node* head = NULL;
struct node** lastPtrRef= &head; // Start out pointing to the head pointer
int i;
for (i=1; i<6; i++) {
Push(lastPtrRef, i); // Add node at the last pointer in the list
lastPtrRef= &((*lastPtrRef)->next); // Advance to point to the
// new last pointer
}
// head == {1, 2, 3, 4, 5};
return(head);
}

void printData(struct node* head)
{
	printf("%d\n", *head);
	while(head != NULL)
	{
		printf("%d\n", head -> data);
		head = head -> next;
	}
}
void PushTest() {
	struct node* head = BuildOneTwoThree();// suppose this returns the list {2, 3}
	Push(&head, 1); // note the &
	Push(&head, 13);
	printData(head);
	// head is now the list {13, 1, 2, 3}
}



int main()
{
	LengthTest();
	PushTest();
}