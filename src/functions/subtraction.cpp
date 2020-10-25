#include <node.h>
#include "../utils/utils.h"

using namespace v8;

void Subtraction(const FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = args.GetIsolate();
  
  CheckArgs(args, isolate);

  float subtraction = args[0].As<Number>()->Value() - args[1].As<Number>()->Value();

  Local<Number> result = Number::New(isolate, subtraction);
  args.GetReturnValue().Set(result);
}