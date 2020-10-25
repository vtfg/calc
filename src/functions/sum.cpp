#include <node.h>
#include "../utils/utils.h"

using namespace v8;

void Sum(const FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = args.GetIsolate();
  
  CheckArgs(args, isolate);

  float sum = args[0].As<Number>()->Value() + args[1].As<Number>()->Value();

  Local<Number> result = Number::New(isolate, sum);
  args.GetReturnValue().Set(result);
}