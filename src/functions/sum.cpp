#include <node.h>

using v8::Exception;
using v8::FunctionCallbackInfo;
using v8::Isolate;
using v8::Local;
using v8::Number;
using v8::Object;
using v8::String;
using v8::Value;

void Sum(const v8::FunctionCallbackInfo<v8::Value>& args) {
    v8::Isolate* isolate = args.GetIsolate();
    
    if (args.Length() < 2) {
        isolate->ThrowException(Exception::TypeError(
            String::NewFromUtf8(isolate, 
            "You need to pass 2 arguments")));

        return;
    }

    if (!args[0]->IsNumber() || !args[1]->IsNumber()) {
        isolate->ThrowException(Exception::TypeError(
            String::NewFromUtf8(isolate, 
            "Wrong arguments")));

        return;
    }

    float sum = 0;

    for (int i = 0; i < args.Length(); i++) {
        sum += args[i].As<Number>()->Value();
    }

    Local<Number> result = Number::New(isolate, sum);

    args.GetReturnValue().Set(result);
}