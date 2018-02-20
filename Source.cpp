#include <iostream>
using namespace std;

// Constants

// Structures and Enums
struct Item{
	int value;
	Item* next;
	Item* prev;
};

struct List {
	Item* head;
	Item* tail;
	unsigned int size;
};

// Function Prototypes
void AddItem(int val, List* list);
void RemoveItem(int val, List* list);
void ShowList(List* list);


int main() {
	List listOne = { nullptr, nullptr, 0 };

	ShowList(&listOne);
	AddItem(20, &listOne);
	ShowList(&listOne);
	
	AddItem(30, &listOne);
	ShowList(&listOne);

	AddItem(40, &listOne);
	ShowList(&listOne);

	RemoveItem(30, &listOne);
	ShowList(&listOne);

	system("pause");
	return 0;
}


// Function Definitions
void AddItem(int val, List* list) {
	Item* item = new Item;

	item->value = val;
	item->next = nullptr;
	
	if (list->head) { // if list is not empty
		item->prev = list->tail;
		list->tail->next = item;
		list->tail = item;
	}
	else { // if list is empty
		item->prev = nullptr;
		list->head = item;
		list->tail = item;
	}

	list->size++;
}

void RemoveItem(int val, List* list) {
	Item* item = list->head;
	
	while (item && val != item->value) {
		item = item->next;
	}

	if (item) {
		if (item == list->head) {
			list->head = item->next;
			item->next->prev = nullptr;
		}
		else if (item == list->tail) {
			list->tail = item->prev;
			item->prev->next = nullptr;
		}
		else {
			item->prev->next = item->next;
			item->next->prev = item->prev;
		}

		delete item;
		list->size--;
	}
}

void ShowList(List* list) {
	Item* item = list->head;

	while (item) {
		cout << item->value << endl;
		item = item->next;
	}

	cout << list->size << " items were found." << endl;
}