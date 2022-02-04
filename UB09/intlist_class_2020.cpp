#include "fcpp.hh"
#include <iostream>

class IntList
{
public:
	// Konstruktor, erzeugt eine leere Liste
	IntList();

	// Copy-Konstruktor, erzeuge deep copy
	IntList(const IntList& other);

    // Destruktor, loescht gesamten Listeninhalt
    ~IntList();
    
	// Zuweisungsoperator
	IntList& operator=(const IntList& other);
 
    // Gibt die Liste aus
    void print();
    
    // Gibt zurueck, ob die Liste leer ist
    bool isEmpty();
    
    // Gibt Anzahl der Elemente zurueck
    int getCount();
    
    // Die folgenden Methoden sind Aufgabenteil a zu implementieren:
    // Gibt den Wert des Elements an der Position 'position' zurueck
    int getElement(int position);
    
    // Füge den Wert 'wert' nach der Position 'position' ein,
    // Position -1 steht für Einfügen am Listenanfang
	void insert(int wert, int position);

	// Löscht das Element an der Position 'position'
	void remove(int position);


private:
	// Ein Listenelement
	struct IntListElem {
	    IntListElem *next;
	    int value;
	};

	// Anzahl Elemente in der Liste
	int count;
	
    // Zeiger auf erstes Element der Liste
	IntListElem *first;
    
    void discard();
    
    IntListElem* copyList(IntListElem* otherFirst);
};


IntList::IntList (){
  first = 0;
  count = 0;
}


// Copy-Konstruktor, erzeuge deep copy
IntList::IntList(const IntList& other){
}

// Destruktor, loesche alle Elemente
IntList::~IntList (){
  discard();
}

// Zuweisungsoperator
IntList& IntList::operator=(const IntList& other){
}

void IntList::print(){
    std::cout << "Die Anzahl der Elemente ist " << count << ". Die Elemente sind: ( ";// << std::endl;
    int i=0;
    for (IntListElem* p=first; p!=0; p=p->next){
        std::cout << i << ": " << p->value << " ";// << std::endl;
        i++;
    }
    std::cout << ")" << std::endl;
}

bool IntList::isEmpty(){
    return (count == 0);
}

int IntList::getCount(){
  return count;
}

int IntList::getElement(int position){
    IntListElem* current = first;

    if (position < count){
        for (int i=0; i < position; i++){
            current = current -> next;
        }
        return current -> value;
    }
    else{
        return 0;
    }
}

void IntList::insert(int element, int position=0){

    IntListElem* e = new IntListElem;
    e -> value = element;
    IntListElem* current = first;

    if (position <= 0){
        e -> next = first ;
        first = e;
    }
    else if (position < count){

        for (int i = 1; i < position; i++){
            current = current -> next;
        }
        e -> next  = current -> next;
        current -> next = e;
    }
    else{
        for (int i = 1; i < (count); i++){
            current = current -> next;
        }
        e -> next = current -> next;
        current -> next = e;
    }
    count ++;

}

void IntList::remove(int position){
    IntListElem* current = first;

    if (position <= 0) {
        first = current -> next;
    }
    else if (position < count){
        for (int i=0; i < (position - 1); i++){
            current = current -> next;
        }
        current -> next = current -> next -> next;
    }
    else {
    }
    count --;
}

// erzeugt eine tiefe Kopie der internen Liste
IntList::IntListElem* IntList::copyList(IntListElem* otherFirst){

    IntListElem* e = new IntListElem;
    int v = otherFirst -> value;
    e -> value = v;

    IntListElem* current = e;
    IntListElem* iter = otherFirst;

    for(iter = iter -> next; iter != 0 ; iter =  iter -> next){
        current  = iter -> next;
        current -> value = iter -> value;
    }

    return e;
}

// leere die interne Liste
void IntList::discard(){
    IntListElem* current = first;
    IntListElem* nextElem = 0;

    for(int i = 0; i < count; i++){
        nextElem = current->next;
        delete(current);
        current = nextElem;
    }
    count = 0;
    first = 0;
}

int main(){
	IntList list;
	std::cout << "Liste empty? " << list.isEmpty() << std::endl;
	std::cout << "Anzahl Elemente: " << list.getCount() << std::endl;

    list.insert(30);
    list.insert(20);
    list.insert(10);
    list.print();


	int pos = 1;
	std::cout << "Element an Position " << pos << ": " << list.getElement(pos) << std::endl;

	list.remove(pos);
	list.print();
    
	list.insert(20,1);
	list.print();

	IntList copy(list);
	copy.print();

	copy.remove(0);
	copy.print();

	copy = list;
	copy.print();
	return 0;
}
