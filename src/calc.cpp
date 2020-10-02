// nodejs library
#include <node.h>

// functions
#include "functions/sum.cpp"

namespace calc {
    using v8::Exception;
    using v8::FunctionCallbackInfo;
    using v8::Isolate;
    using v8::Local;
    using v8::Number;
    using v8::Object;
    using v8::String;
    using v8::Value;    

    void Initialize(v8::Local<v8::Object> exports) {
        NODE_SET_METHOD(exports, "sum", Sum);
    }

    NODE_MODULE(addon, Initialize)
}