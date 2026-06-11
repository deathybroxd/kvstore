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

    std::cout << "=== Search ===" << std::endl;
    std::cout << tree.Search(7) << std::endl;   // should print "seven"
    std::cout << tree.Search(99) << std::endl;  // should print ""

    std::cout << "=== RangeQuery [5, 12] ===" << std::endl;
    auto results = tree.RangeQuery(5, 12);
    for (auto& pair : results) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }
    // should print 5, 7, 10, 12 in order

    std::cout << "=== Size ===" << std::endl;
    std::cout << tree.Size() << std::endl; // should print 7

    std::cout << "=== IsEmpty ===" << std::endl;
    std::cout << tree.IsEmpty() << std::endl; // should print 0

    return 0;
}