#include <iostream>
#include <cassert>
#include <stdexcept>

//o incercare...

class Container {
public:
    Container(int size) : size(size), elements(new int[size]) {}

    ~Container() {
        delete[] elements;
    }

    int getSize() const {
        return size;
    }

    void addElement(int value) {
        if (currentIndex < size) {
            elements[currentIndex++] = value;
        } else {
            throw std::overflow_error("Container is full");
        }
    }

    int getElement(int index) const {
        if (index >= 0 && index < currentIndex) {
            return elements[index];
        } else {
            throw std::out_of_range("Invalid index");
        }
    }

private:
    int* elements;          // Pointer to the array of elements
    int size;               // Capacity of the container
    int currentIndex = 0;   // Current index for adding elements
};

void testAddingElements() {
    Container container(3);                // Create a container with capacity 3
    container.addElement(10);              // Add element 10
    container.addElement(20);              // Add element 20
    container.addElement(30);              // Add element 30
    assert(container.getSize() == 3);      // Check the size of the container
}

void testAccessingElements() {
    Container container(2);                // Create a container with capacity 2
    container.addElement(10);              // Add element 10
    container.addElement(20);              // Add element 20
    assert(container.getElement(0) == 10); // Check the element at index 0
    assert(container.getElement(1) == 20); // Check the element at index 1
}

void testAccessingInvalidIndexThrowsException() {
    Container container(1);                // Create a container with capacity 1
    container.addElement(10);              // Add element 10
    try {
        container.getElement(1);           // Try to access element at index 1
        assert(false);                     // This line should not be reached
    } catch (const std::out_of_range& e) {
        assert(std::string(e.what()) == "Invalid index"); // Check the exception message
    }
}

void testAddingMoreElementsThanCapacityThrowsException() {
    Container container(2);                // Create a container with capacity 2
    container.addElement(10);              // Add element 10
    container.addElement(20);              // Add element 20
    try {
        container.addElement(30);          // Try to add element 30 (exceeds capacity)
        assert(false);                     // This line should not be reached
    } catch (const std::overflow_error& e) {
        assert(std::string(e.what()) == "Container is full"); // Check the exception message
    }
}

void testAccessingElementsAfterAddingMoreThanCapacity() {
    Container container(2);                // Create a container with capacity 2
    container.addElement(10);              // Add element 10
    container.addElement(20);              // Add element 20
    try {
        container.getElement(2);           // Try to access element at index 2
        assert(false);                     // This line should not be reached
    } catch (const std::out_of_range& e) {
        assert(std::string(e.what()) == "Invalid index"); // Check the exception message
    }
}

void testEmptyContainerSize() {
    Container container(0);                // Create an empty container
    assert(container.getSize() == 0);      // Check the size of the container
}

void testAccessingElementInEmptyContainerThrowsException() {
    Container container(0);                // Create an empty container
    try {
        container.getElement(0);           // Try to access element at index 0
        assert(false);                     // This line should not be reached
    } catch (const std::out_of_range& e) {
        assert(std::string(e.what()) == "Invalid index"); // Check the exception message
    }
}

int main() {
    testAddingElements();
    testAccessingElements();
    testAccessingInvalidIndexThrowsException();
    testAddingMoreElementsThanCapacityThrowsException();
    testAccessingElementsAfterAddingMoreThanCapacity();
    testEmptyContainerSize();
    testAccessingElementInEmptyContainerThrowsException();

    std::cout << "All tests passed!" << std::endl;

    return 0;
}
