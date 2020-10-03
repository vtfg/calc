// external library
#include <node.h>

// functions
#include "functions/sum.cpp"
#include "functions/subtraction.cpp"
#include "functions/multiply.cpp"
#include "functions/division.cpp"

namespace calc {
  using v8::Local;
  using v8::Object;

  void Initialize(Local<Object> exports) {
      NODE_SET_METHOD(exports, "sum", Sum);
      NODE_SET_METHOD(exports, "sub", Subtraction);
      NODE_SET_METHOD(exports, "mult", Multiply);
      NODE_SET_METHOD(exports, "div", Division);
  }

  NODE_MODULE(addon, Initialize)
}