#include <iostream>
#include <memory>  //unique_ptr

#include "ap_error.h"
//we want to implement also the iterators
enum class method { push_back, push_front };

template <class T>
class List {
  struct node {
    std::unique_ptr<node> next; //pointer to next node
    //since it points to a node it can see both is pointer to the next
    //and its value
    T value; //value stored in the node
    node(const T& v, node* p) : next{p}, value{v} {
      std::cout << "copy ctor" << std::endl;
    }
    node(T&& v, node* p) : next{p}, value{std::move(v)} {
      std::cout << "move ctor" << std::endl;
    }
    explicit node(const std::unique_ptr<node>& p) : value{p->value} {
      //this is a ctor
      //want to construct a node from a unique_optr to a node
      if (p->next) //if this is different from the nullptr
	//p->next access the element next of p
	//p points to a node
        next = std::make_unique<node>(p->next);
      //make_unique returns an object of type std::unique_ptr
    }
  }; //end of node 

  std::unique_ptr<node> head; //first the node of the list

  template <class OT>
  void push_back(OT&& v); //append a node at the end of the list

  template <class OT>
  void push_front(OT&& v) { //append a node in front of the list
    //want v to be the first of the list
    //need to pass rvalue reference because we want to use forward

    // auto h = head.release();
    // auto new_node = new node {v,h};
    // head.reset(new_node);

    // head.reset(new node{v, head.release()});

    head = std::make_unique<node>(std::forward<OT>(v), head.release());
    //as value it takes v
    //previous head now is the second of the list
    //so the new head has to the point to the old head
    //this is done realising head
    
    //the list is templated on T
    //T is the type of the values stored in the nodes
    
  }
  // void push_front(T&& v);

  node* tail() noexcept; //returns a pointer to the last node of the list

 public:
  List() noexcept = default;
  List(List&& l) noexcept = default;
  List& operator=(List&& l) noexcept = default;

  List(const List& l);
  List& operator=(const List& l);

  template <class OT>
  void insert(OT&& v, const method m);

  template <class O>
  friend std::ostream& operator<<(std::ostream&, const List<O>&);
}; //end of list

template<typename O>
class __iterator;
using iterator = __iterator<T>;
using const_iterator = __iterator<const T>;
				 
  iterator begin() {}
  iteator end() {}
  const_iterator begin() const {} //const iterator returns const reference
  const_iterator end() const {}
  const_iterator cbegin() {}
  const_iterator cend() {}

  //all the standard libraries are headers that are in our computer
  //we can see them to take inspiration
};


template<typename T>
template<typename O>


template <class T>
typename List<T>::node* List<T>::tail() noexcept {
  auto tmp = head.get(); //.get() returns a pointer to head

  while (tmp->next) //until it is the nullptr
    tmp = tmp->next.get();

  return tmp;
}

template <class T>
template <class OT>
void List<T>::insert(OT&& v, const method m) { //or at the beginning or at the end
  if (!head) {
    // head.reset(new node{v,nullptr});
    head = std::make_unique<node>(std::forward<OT>(v), nullptr);
    return;
  }
  switch (m) {
    case method::push_back:
      push_back(std::forward<OT>(v));
      break;

    case method::push_front:
      push_front(std::forward<OT>(v));
      break;
    default:
      AP_ERROR(false) << "Unknown insertion method";
      break;
  };
}

template <class T>
template <class OT>
void List<T>::push_back(OT&& v) {
  node* last = tail();
  // last->next.reset(new node{v, nullptr});
  last->next = std::make_unique<node>(std::forward<OT>(v), nullptr);
}

template <class T>
std::ostream& operator<<(std::ostream& os, const List<T>& l) {
  auto tmp = l.head.get();
  while (tmp) {
    os << tmp->value << " ";
    tmp = tmp->next.get();
  }
  return os;
}

template <class T>
List<T>::List(const List& l) {
  // auto tmp = l.head.get();
  // while(tmp){
  //   insert(tmp->value,method::push_back);
  //   tmp=tmp->next.get();
  // }
  head = std::make_unique<node>(l.head);
}

int main() {
  try {
    List<int> l{};

    l.insert(4, method::push_back);
    l.insert(5, method::push_back);
    l.insert(3, method::push_front);

    std::cout << l << std::endl;

    auto ol = l;
    int a = 9;
    l.insert(14, method::push_front);
    l.insert(a, method::push_front);

    std::cout << l << std::endl;
    std::cout << ol << std::endl;

  } catch (std::exception& e) {
    std::cerr << e.what() << std::endl;
  } catch (...) {
    std::cerr << "Unknown exception" << std::endl;
  }

  return 0;
}
