#include <algorithm>

#include <cstring>

class String {
 public:
  String() = default;
  String(const char* data, size_t size)
    : data_(size > 0 ? new char[size + 1] : nullptr), size_(size) {
    if (size_ > 0) {
      memcpy(data_, data, size_);
      data_[size_] = '\0';
    }
  }
  String(const char* data) : String(data, strlen(data)) {}
  String(const String& str) : String(str.data_, str.size_) {}
  String(String&& str) noexcept
    : data_(str.data_), size_(str.size_) {}
  ~String() { delete[] data_; }

  void Swap(String& str) {
    std::swap(data_, str.data_);
    std::swap(size_, str.size_);
  }

 private:
  char* data_ = nullptr;
  size_t size_ = 0;
};

int main() {
  String s = "hello world";
}
