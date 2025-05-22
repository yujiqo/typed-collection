#include <iostream>
#include <memory>

#include "TypedCollection.hpp"

using std::shared_ptr, std::cout, std::endl;
using tc::TypedCollection, tc::Copyable;

template<Copyable T>
struct TypedCollectionPrinter {
    static void print(TypedCollection<T> collection) {
        collection.forEach([](shared_ptr<T> item) {
            cout << *item << " ";
        });
        cout << endl;
    }
};

int main() {
    TypedCollection<int> MyCollection;
    TypedCollectionPrinter<int> printer;

    MyCollection.add(1);
    MyCollection.add(3);
    MyCollection.add(7);

    cout << MyCollection.count() << endl;

    printer.print(MyCollection);

    MyCollection.add(5);

    printer.print(MyCollection);

    return 0;
}
