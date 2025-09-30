#include <iostream>
#include <string>
using namespace std;

class Staff {
public:
    int id;
    string name;
    string birthDate;
    string phone;
    string homeAddress;
    Staff* next;

    Staff(int i, string n, string b, string p, string h) {
        id = i;
        name = n;
        birthDate = b;
        phone = p;
        homeAddress = h;
        next = NULL;
    }
};

class StaffList {
private:
    Staff* head;
public:
    StaffList() { head = NULL; }

    bool IsEmpty() {
        return head == NULL;
    }

    Staff* Front() { return head; }

    Staff* Back() {
        if (IsEmpty()) return NULL;
        Staff* temp = head;
        while (temp->next != NULL) temp = temp->next;
        return temp;
    }

    void Print_List() {
        if (IsEmpty()) {
            cout << "List has no staff.\n";
            return;
        }
        Staff* temp = head;
        while (temp != NULL) {
            cout << temp->id << " " << temp->name << " " << temp->birthDate
                 << " " << temp->phone << " " << temp->homeAddress << endl;
            temp = temp->next;
        }
    }

    void AddFront(int id, string n, string b, string p, string h) {
        Staff* s = new Staff(id,n,b,p,h);
        s->next = head;
        head = s;
    }

    void InsertBack(int id, string n, string b, string p, string h) {
        Staff* s = new Staff(id,n,b,p,h);
        if (IsEmpty()) { head = s; return; }
        Staff* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = s;
    }

    void RemoveFront() {
        if (IsEmpty()) { cout << "Nothing to remove\n"; return; }
        Staff* t = head;
        head = head->next;
        delete t;
    }

    void RemoveBack() {
        if (IsEmpty()) { cout << "Nothing to remove\n"; return; }
        if (head->next == NULL) { delete head; head = NULL; return; }
        Staff* temp = head;
        while (temp->next->next) temp = temp->next;
        delete temp->next;
        temp->next = NULL;
    }

    Staff* SearchByID(int id) {
        Staff* temp = head;
        while (temp) {
            if (temp->id == id) return temp;
            temp = temp->next;
        }
        return NULL;
    }

    void UpdateInfo(int id) {
        Staff* s = SearchByID(id);
        if (!s) { cout << "Staff not found.\n"; return; }
        cout << "Type new Name, BirthDate, Phone, Address: ";
        cin >> s->name >> s->birthDate >> s->phone >> s->homeAddress;
    }

    void InsertByID(int id, string n, string b, string p, string h) {
        Staff* s = new Staff(id,n,b,p,h);
        if (IsEmpty() || id < head->id) {
            s->next = head;
            head = s;
            return;
        }
        Staff* temp = head;
        while (temp->next && temp->next->id < id) temp = temp->next;
        s->next = temp->next;
        temp->next = s;
    }

    void Delete(int id) {
        if (IsEmpty()) return;
        if (head->id == id) {
            Staff* t = head;
            head = head->next;
            delete t;
            return;
        }
        Staff* temp = head;
        while (temp->next && temp->next->id != id) temp = temp->next;
        if (temp->next) {
            Staff* t = temp->next;
            temp->next = t->next;
            delete t;
        }
    }

    int TotalStaff() {
        int cnt = 0;
        Staff* t = head;
        while (t) { cnt++; t = t->next; }
        return cnt;
    }
};

int main() {
    StaffList list;
    int choice;

    do {
        cout << "\n------ Staff Menu ------\n";
        cout << "1. Show first staff\n";
        cout << "2. Show last staff\n";
        cout << "3. Show all staff\n";
        cout << "4. Add staff to front\n";
        cout << "5. Add staff to back\n";
        cout << "6. Remove first staff\n";
        cout << "7. Remove last staff\n";
        cout << "8. Search staff by ID\n";
        cout << "9. Update staff info\n";
        cout << "10. Add staff by ID order\n";
        cout << "11. Delete staff by ID\n";
        cout << "12. Count all staff\n";
        cout << "0. Exit\n";
        cout << "Choose: ";
        cin >> choice;

        if (choice == 1) {
            Staff* f = list.Front();
            if (f) cout << "First: " << f->id << " " << f->name << endl;
            else cout << "List empty.\n";
        }
        else if (choice == 2) {
            Staff* b = list.Back();
            if (b) cout << "Last: " << b->id << " " << b->name << endl;
            else cout << "List empty.\n";
        }
        else if (choice == 3) {
            list.Print_List();
        }
        else if (choice == 4) {
            int id; string n,b,p,h;
            cout << "Enter ID Name BirthDate Phone Address: ";
            cin >> id >> n >> b >> p >> h;
            list.AddFront(id,n,b,p,h);
        }
        else if (choice == 5) {
            int id; string n,b,p,h;
            cout << "Enter ID Name BirthDate Phone Address: ";
            cin >> id >> n >> b >> p >> h;
            list.InsertBack(id,n,b,p,h);
        }
        else if (choice == 6) {
            list.RemoveFront();
        }
        else if (choice == 7) {
            list.RemoveBack();
        }
        else if (choice == 8) {
            int id; cout << "Type ID: "; cin >> id;
            Staff* f = list.SearchByID(id);
            if (f) cout << "Found: " << f->name << " " << f->birthDate << " " << f->phone << " " << f->homeAddress << endl;
            else cout << "Not found.\n";
        }
        else if (choice == 9) {
            int id; cout << "Enter ID to update: "; cin >> id;
            list.UpdateInfo(id);
        }
        else if (choice == 10) {
            int id; string n,b,p,h;
            cout << "Enter ID Name BirthDate Phone Address: ";
            cin >> id >> n >> b >> p >> h;
            list.InsertByID(id,n,b,p,h);
        }
        else if (choice == 11) {
            int id; cout << "Enter ID to delete: "; cin >> id;
            list.Delete(id);
        }
        else if (choice == 12) {
            cout << "Total staff: " << list.TotalStaff() << endl;
        }
        else if (choice != 0) {
            cout << "Wrong option, try again!\n";
        }

    } while (choice != 0);

    return 0;
}
