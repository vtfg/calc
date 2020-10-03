#include <node.h>

using namespace v8;

void Division(const FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = args.GetIsolate();
  
  if (args.Length() < 2 || args.Length() > 2) {
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

  float division = args[0].As<Number>()->Value() / args[1].As<Number>()->Value();
  Local<Number> result = Number::New(isolate, division);

  args.GetReturnValue().Set(result);
}