#include <algorithm>

#include <cassert>

template <class T>
class SharedPtr {
 public:
  explicit SharedPtr(T* ptr = nullptr)
  try
    : ptr_(ptr), count_(new int(1)) {}
  catch (...) {
    delete ptr;
    throw;
  }

  ~SharedPtr() {
    if (--*count_ == 0) {
      delete ptr_;
    }
  }

  SharedPtr(const SharedPtr& other) : ptr_(other.ptr_), count_(other.count_) {
    ++*count_;
  }

  SharedPtr& operator=(SharedPtr other) {
    other.Swap(*this);
    return *this;
  }

  void Swap(SharedPtr&& other) noexcept {
    std::swap(ptr_, other.ptr_);
    std::swap(count_, other.count_);
  }

  int UseCount() const { return *count_; }

  T* operator->() const { return ptr_; }
  T& operator*() const { return *ptr_; }

 private:
  T* ptr_;
  int* count_;
};

int main() {
  SharedPtr<int> p1(new int(151));
  assert(*p1 == 151);
  {
    SharedPtr<int> p2 = p1;
    *p2 = 100;
    assert(*p1 == 100);
    assert(p1.UseCount() == 2);
    {
      p1.Swap(SharedPtr<int>());
    }
    assert(p2.UseCount() == 1);
  }
  assert(p1.operator->() == nullptr);
  assert(p1.UseCount() == 1);
}
