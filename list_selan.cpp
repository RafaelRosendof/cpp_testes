#include <iostream>
#include <sstream>
#include <exception>

namespace sc {
template <typename T> class stack {
private:
  T* m_data;          // Storage area.
  size_t m_top;       // Points to the element at top.
  size_t m_capacity;  // Current stack capacity.
public:
  stack(size_t cp = 0) : m_data{ new T[cp] }, m_top{ 0 }, m_capacity{ cp } {
    /* empty */
    // m_data = new T[cp];
    // m_top = 0;
    // m_capacity = cp;
  }
  ~stack() { delete[] m_data; }
  // stack<int> x;
  // stack<int> y(x);
  stack(const stack& clone)
      : m_data{ new T[clone.m_capacity] }, m_top{ clone.m_top }, m_capacity{ clone.m_capacity } {
    // Copy all elements from clone.
    std::copy(clone.m_data, clone.m_data + clone.m_top, m_data);
  }

  [[nodiscard]] size_t size() const { return m_top; }
  [[nodiscard]] size_t capacity() const { return m_capacity; }
  [[nodiscard]] bool empty() const { return m_top == 0; }

  void push(const T& value) {
    // Check wheter there is enough space.
    if (m_top == m_capacity) {
      m_capacity = m_capacity == 0 ? 1 : 2 * m_capacity;
      // Create the new expanded memory
      T* new_mem = new T[m_capacity];
      // Copy original elements to the new data storage.
      std::copy(m_data, m_data + m_top, new_mem);
      // Free old memory to avoid memory leaks.
      delete [] m_data;
      // reassign new memory area.
      m_data = new_mem;
    }
    // Insert the new value.
    m_data[m_top++] = value;
  }

  [[nodiscard]] const T& top() const{
    if(empty()){
      throw std::out_of_range("top(): Stack is empty!");
    }
    return m_data[m_top-1];
  }

  void pop() {
    if(empty()){
      throw std::out_of_range("pop(): Stack is empty!");
    }
    --m_top;
  }
  void pop( T& remove_value) {
    if(empty()){
      throw std::out_of_range("pop(T&): Stack is empty!");
    }
    --m_top;
    remove_value = m_data[m_top];
  }

  std::string to_string() {
    std::ostringstream oss;

    oss << "[ ";
    for (size_t idx{ 0 }; idx < m_top; ++idx) {
      oss << m_data[idx] << ' ';
    }
    oss << ">, top index = " << m_top;

    return oss.str();
  }
};
}  // namespace sc

int main(int argc, char* argv[]) {
  sc::stack<int> s;
  sc::stack<int> t(100);  // Reserver 100 elements in a stack.

  std::cout << "Stack = " << s.to_string() << "\n";

  s.push(1);
  s.push(2);
  s.push(3);
  std::cout << "Stack, after pushes = " << s.to_string() << "\n";

  std::cout << "At the top of s we have: " << s.top() << '\n';
  // std::cout << "At the top of t we have: " << t.top() << '\n';
  //
  int x{ 0 };
  s.pop(x);
  std::cout << "x = " << x << "\n";


  for(short i{0}; i < 10; ++i){
    s.push(i+1);
  }

  std::cout << ">>> Stack content: ";
  while(not s.empty()){
    std::cout << s.top() << " - ";
    s.pop();
  }
  std::cout << "\n";

  return 0;
}