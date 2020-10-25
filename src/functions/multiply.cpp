#include <node.h>
#include "../utils/utils.h"

using namespace v8;

void Multiply(const FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = args.GetIsolate();
  
  CheckArgs(args, isolate);

  float multiply = args[0].As<Number>()->Value() * args[1].As<Number>()->Value();

  Local<Number> result = Number::New(isolate, multiply);
  args.GetReturnValue().Set(result);
}