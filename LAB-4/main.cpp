#include <iostream>

using namespace std;

struct Package
{
    string packageID;
    string destinationCity;
    int dimensions[3];
    Package* next;
};

struct Courier
{
    string courierName;
    string vehicleType;
};

struct CourierQueue
{
    Courier array[5];
    int front = 0;
    int rear = -1;
    int size = 0;
    int capacity = 5;
};

void pushPackage(Package** top, string ID, string city, int l, int w, int h)
{
    Package* newNode = new Package;
    newNode -> packageID = ID;
    newNode -> destinationCity = city;
    newNode -> dimensions[0] = l; newNode -> dimensions[1] = w; newNode -> dimensions[2] = h;
    newNode -> next = *top;
    *top = newNode;
    cout << "Package" << ID << "added.\n";
}

Package* popPackage(Package** top) {
    if (*top == nullptr) return nullptr;
    Package* temp = *top;
    *top = (*top)->next;
    return temp;
}

void enqueueCourier(CourierQueue* q, string name, string vehicle)
{
    if (q -> size == q -> capacity)
    {
        cout << "Queue is full.\n";
        return;
    }
    q -> rear = (q -> rear + 1) % q -> capacity;
    q->array[q->rear].courierName = name;
    q->array[q->rear].vehicleType = vehicle;
    q->size++;
    cout << "Courier registered\n";
}

void dispatch(Package** top, CourierQueue* q)
{
    if (q->size == 0 || *top == nullptr)
    {
        cout << "\nERROR: Package or courier missing.\n";
        return;
    }
    Package* p = popPackage(top);
    Courier c = q->array[q->front];
    q->front = (q->front + 1) % q->capacity;
    q->size--;

    cout << "\n>>> DISPATCH: Courier " << c.courierName << " (" << c.vehicleType << ") is delivering ";
    cout << "Package " << p->packageID << " to " << p->destinationCity << ".\n";

    delete p;
}

void displayStatus(Package* top, CourierQueue q) {
    cout << "\n--- WAREHOUSE STATUS ---" << endl;
    if (top == nullptr) {
        cout << "Warehouse is empty." << endl;
    }
    while (top != nullptr) {
        cout << "Package: " << top->packageID << " (Destination: " << top->destinationCity << ")" << endl;
        top = top->next;
    }

    cout << "\n--- COURIER QUEUE ---" << endl;
    if (q.size == 0) {
        cout << "No couriers waiting." << endl;
    }
    for (int i = 0; i < q.size; i++) {
        int idx = (q.front + i) % q.capacity;
        cout << i + 1 << ". " << q.array[idx].courierName << " [" << q.array[idx].vehicleType << "]" << endl;
    }
}

int main() {
    Package* stackTop = nullptr;
    CourierQueue q;
    int c = -1;

    while (c != 0) {
        cout << "\n1.Add Pkg | 2.Add Courier | 3.Dispatch | 4.Show | 0.Exit\nChoice: ";
        cin >> c;

        switch(c) {
            case 1: {
                string id, city; int l, w, h;
                cin >> id >> city >> l >> w >> h;
                pushPackage(&stackTop, id, city, l, w, h);
                break;
            }
            case 2: {
                string n, v; cin >> n >> v;
                enqueueCourier(&q, n, v);
                break;
            }
            case 3: dispatch(&stackTop, &q); break;
            case 4: displayStatus(stackTop, q); break;
        }
    }
    return 0;
}
