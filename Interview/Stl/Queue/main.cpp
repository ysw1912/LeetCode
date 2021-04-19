#include <stack>

#include <cassert>

template <class T>
class Queue {
 public:
  Queue() = default;

  void Push(T&& t) {
    stack_in_.push(t);
  }

  T Pop() {
    InToOut();
    T t = stack_out_.top();
    stack_out_.pop();
    return t;
  }

  T Top() {
    InToOut();
    return stack_out_.top();
  }

  bool Empty() {
    return stack_in_.empty() && stack_out_.empty();
  }

 private:
  void InToOut() {
    if (!stack_out_.empty()) {
      return;
    }
    while (!stack_in_.empty()) {
      stack_out_.push(stack_in_.top());
      stack_in_.pop();
    }
  }

  std::stack<T> stack_in_;
  std::stack<T> stack_out_;
};

int main() {
  Queue<int> q;
  assert(q.Empty());
  q.Push(1);
  q.Push(2);
  assert(q.Top() == 1);
  q.Pop();
  assert(q.Pop() == 2);
  q.Push(3);
  assert(!q.Empty());
}
