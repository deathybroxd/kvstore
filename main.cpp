#include "REPL.h"

int main() {
    // REPL repl;
    // repl.Run();
    RBTree<int, std::string> tree;

    tree.Insert(10, "ten");
    tree.Insert(5, "five");
    tree.Insert(15, "fifteen");
    tree.Insert(3, "three");
    tree.Insert(7, "seven");
    tree.Insert(12, "twelve");
    tree.Insert(20, "twenty");

    std::cout << "=== InOrder ===" << std::endl;
    tree.InOrder();

    std::cout << "\n=== Search ===" << std::endl;
    auto found = tree.Search(7);
    std::cout << (found.has_value() ? found.value() : "not found") << std::endl; // seven
    auto notFound = tree.Search(99);
    std::cout << (notFound.has_value() ? notFound.value() : "not found") << std::endl; // not found

    std::cout << "\n=== RangeQuery [5, 12] ===" << std::endl;
    auto results = tree.RangeQuery(5, 12);
    for (auto& pair : results) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    } // should print 5, 7, 10, 12

    std::cout << "\n=== Remove ===" << std::endl;
    auto removed = tree.Remove(10); // two children case
    std::cout << (removed.has_value() ? removed.value() : "not found") << std::endl; // ten
    tree.InOrder(); // 10 should be gone

    auto removed2 = tree.Remove(3); // no left child case
    tree.InOrder(); // 3 should be gone

    auto removed3 = tree.Remove(99); // not found case
    std::cout << (removed3.has_value() ? "found" : "not found") << std::endl; // not found

    std::cout << "\n=== Size ===" << std::endl;
    std::cout << tree.Size() << std::endl; // should print 5

    std::cout << "\n=== Clear ===" << std::endl;
    tree.Clear();
    std::cout << tree.IsEmpty() << std::endl; // should print 1
    std::cout << tree.Size() << std::endl; // should print 0

    return 0;
}