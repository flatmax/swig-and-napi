#include <napi.h>

Napi::ThreadSafeFunction tsfn; ///< The node api's threadsafe function

Napi::Value Start( const Napi::CallbackInfo& info ){
  Napi::Env env = info.Env();

  if ( info.Length() < 2 )
    throw Napi::TypeError::New( env, "Expected two arguments" );
  if ( !info[0].IsFunction() )
    throw Napi::TypeError::New( env, "Expected first arg to be function" );

  // Create a ThreadSafeFunction
  tsfn = Napi::ThreadSafeFunction::New(
    env,
    info[0].As<Napi::Function>(),  // JavaScript function called asynchronously
    "Resource Name",         // Name
    0,                       // Unlimited queue
    1);                       // Only one thread will use this initially

  // return the tsfn as a pointer in a string
  char addr[24];
  sprintf(addr,"%p",&tsfn);
  return Napi::String::New(env, addr);
}

Napi::Object InitNapi( Napi::Env env, Napi::Object exports ) {
  exports.Set( "start", Napi::Function::New( env, Start ) );
  return exports;
}

NODE_API_MODULE( libNapiNodejs, InitNapi )
