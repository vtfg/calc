#ifndef utils_h
#define utils_h

#include <node.h>

using namespace v8;

void ThrowLengthError(const FunctionCallbackInfo<Value> &args, Isolate *isolate) {
  isolate->ThrowException(Exception::SyntaxError(
    String::NewFromUtf8(isolate, "You need to pass only two arguments")));

  return;
}

void ThrowNumberError(const FunctionCallbackInfo<Value> &args, Isolate *isolate) {
  isolate->ThrowException(Exception::SyntaxError(
    String::NewFromUtf8(isolate, "Wrong arguments, Calc only accepts numbers")));

  return;
}

void CheckArgs(const FunctionCallbackInfo<Value> &args, Isolate *isolate) {
  if (args.Length() != 2) {
    ThrowLengthError(args, isolate);
  }

  if (!args[0]->IsNumber() || !args[1]->IsNumber()) {
    ThrowNumberError(args, isolate);
  }
}

#endif /* utils.h */