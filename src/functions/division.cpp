#include <node.h>
#include "../utils/utils.h"

using namespace v8;

void Division(const FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = args.GetIsolate();
  
  CheckArgs(args, isolate);

  float division = args[0].As<Number>()->Value() / args[1].As<Number>()->Value();
  
  Local<Number> result = Number::New(isolate, division);
  args.GetReturnValue().Set(result);
}