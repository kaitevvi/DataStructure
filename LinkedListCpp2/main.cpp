#include"LinkedList.hpp"

int main() {
    LinkedList<int> linkedList;
    linkedList.push_back(1);
    linkedList.push_back(2);
    linkedList.push_back(3);
    linkedList.insert(-1, 0);
    linkedList.remove(0);
    linkedList.remove(1);

    linkedList.print();
    std::cout << linkedList.size() << std::endl;

}