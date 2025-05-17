#include<iostream>
#include<fstream>
using namespace std;

class Book
{
    friend class BookList;

private:
    int id;          /** ID of a book. */
    string title;    /** Name of a book. */
    float price;     /** Price of a book. */
    Book* next;      /** Address of the next node. */
    Book* pre;       /** Address of the previous node. */

public:
    /** Constructor */
    Book(int id, string title, float price, Book* next = nullptr, Book* pre = nullptr)
    {
        this->id = id;
        this->title = title;
        this->price = price;
        this->next = next;
        this->pre = pre;
    }

    /** Displays the book information */
    void bookDetails()
    {
        cout << "Book id: " << id << " Title: " << title << " price :" << price << " " << endl;
    }

};

class BookList
{
private:
    Book* head;      /** Pointer to the first node in the list. */
    Book* cursor;    /** Pointer to the current node in the list. */
    Book* last;      /** Pointer to the last node in the list. */

public:
    /** Constructor */
    BookList()
    {
        head = nullptr;
        cursor = nullptr;
        last = nullptr;
    }

    /** Destructor */
    ~BookList()
    {
        Book* temp = head;
        while (temp != nullptr)
        {
            temp = temp->next;
            delete head;
            head = temp;
        }
    }

    /** Insert a new book. */
    void insert(const Book& newItem)
    {
        Book* nb = new Book(newItem.id, newItem.title, newItem.price, nullptr, nullptr);
        if (head == nullptr)
        {
            head = nb;
            cursor = nb;
            last = nb;
        }
        else
        {
            nb->pre = last;            // Connect the new book to the last node
            last->next = nb;           // The last node's next points to the new book
            last = nb;                 // Update the last pointer to the new book
        }
    }

    /** Remove the book at the cursor. */
    void remove()
    {
        if (cursor == nullptr)
        {
            cout << "List is already empty, no book available" << endl;
        }
        else if (cursor->next != nullptr)
        {
            // Case when cursor is not at the last node
            Book* temp = cursor;
            cursor->pre->next = cursor->next;  // Update previous node's next
            cursor->next->pre = cursor->pre;  // Update next node's previous
            cursor = cursor->next;            // Move cursor to next node
            delete temp;
        }
        else
        {
            // Case when cursor is at the last node
            if (cursor->pre != nullptr)
            {
                // Update last pointer to the previous node
                last = cursor->pre;
                last->next = nullptr;
            }
            else
            {
                // Only one node in the list
                head = nullptr;
                last = nullptr;
            }
            Book* temp = cursor;
            cursor = cursor->pre;  // Move cursor to previous node
            delete temp;
        }
    }

    /** Search for a book by title. */
    void search(string title)
    {
        if (head == nullptr)
        {
            cout << "List is empty so I can't search" << endl;
            return;
        }
        else
        {
            Book* temp = head;
            do {
                if (temp->title == title)
                {
                    cout << "Yes I found the required book" << endl;
                    temp->bookDetails();
                    return;
                }
                else
                {
                    temp = temp->next;
                }
            } while (temp != head); // Loop until we come back to the head
        }
        cout << "There is no book according to your title " << title << " Sorry for it" << endl;
    }

    /** Replace the book at the cursor. */
    void replace(const Book& newItem)
    {
        if (!isEmpty() && cursor != nullptr)
        {
            cursor->id = newItem.id;
            cursor->title = newItem.title;
            cursor->price = newItem.price;
            cout << "Book details replaced successfully." << endl;
        }
        else
        {
            cout << "Error: No book to replace, either list is empty or cursor is invalid." << endl;
        }
    }

    /** Check if the list is empty. */
    bool isEmpty() const
    {
        return head == nullptr;
    }

    /** Move the cursor to the beginning. */
    void gotoBeginning()
    {
        if (!isEmpty())
        {
            cursor = head;
            cout << "Book Detail at current cursor" << endl;
            cursor->bookDetails();
        }
        else
        {
            cout << "There is a problem at goto beginning" << endl;
        }
    }

    /** Move the cursor to the end. */
    void gotoEnd()
    {
        if (!isEmpty())
        {
            cursor = last;
            cout << "Cursor moved to the last" << endl;
            cursor->bookDetails();
        }
        else
        {
            cout << "No last from gotoEnd" << endl;
        }
    }

    /** Move the cursor to the next node. */
    bool gotoNext()
    {
        if (!isEmpty() && cursor->next != nullptr)
        {
            cursor = cursor->next;
            return true;
        }
        return false;
    }

    /** Move the cursor to the previous node. */
    bool gotoPrior()
    {
        if (!isEmpty() && cursor->pre != nullptr)
        {
            cursor = cursor->pre;
            return true;
        }
        return false;
    }

    /** Get a copy of the book at the cursor. */
    Book getCursor() const
    {
        if (!isEmpty())
        {
            return *cursor;
        }
        else
        {
            cout << "List is empty from get cursor" << endl;
            return Book(0, "", 0); // Return a default Book if the list is empty
        }
    }

    /** Display all books from head to tail. */
    void showStructureForward() const
    {
        Book* temp = head;
        while (temp != nullptr)
        {
            temp->bookDetails();
            temp = temp->next;
        }
    }

    /** Display all books from tail to head. */
    void showStructureReverse() const
    {
        if (!isEmpty())
        {
            Book* temp = last;
            cout << "Reverse order data in linked list" << endl;
            while (temp != nullptr)
            {
                temp->bookDetails();
                temp = temp->pre;
            }
        }
        else
        {
            cout << "There are no available books in reverse order" << endl;
        }
    }
};

int main()
{
    ifstream r("input.txt");

    if (!r)
    {
        cout << "Error in file opening" << endl;
    }

    BookList l1;

    int id;
    string title;
    float price;

    while (r >> id)
    {
        r.ignore();
        getline(r, title);
        r >> price;
        r.ignore();
        Book nb(id, title, price, nullptr, nullptr);
        l1.insert(nb);
    }

    // Adding books manually
    Book nB(21, "AQIB", 2500, nullptr, nullptr);
    Book rb(22, "Hassan", 2500, nullptr, nullptr);
    Book rj(23, "Umer", 2500, nullptr, nullptr);
    l1.insert(nB);
    l1.insert(rb);
    l1.insert(rj);

    l1.showStructureForward();

    r.close();
}
