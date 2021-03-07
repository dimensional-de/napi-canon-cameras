#ifndef NAPI_CANON_API_ERROR_H
#define NAPI_CANON_API_ERROR_H

#include "types.h"
#include "api-identifier.h"
#include <unordered_map>

namespace CameraApi {

    class ApiErrorWrap : public Napi::ObjectWrap<ApiErrorWrap>, public ApiIdentifier {
        public:
            ApiErrorWrap(const Napi::CallbackInfo &info);

            static void Init(Napi::Env env, Napi::Object exports);

            static Napi::Object NewInstance(Napi::Env env, EdsError errorCode);

            static Napi::Value ThrowIfFailed(Napi::Env env, EdsError errorCode);

            static Napi::Value ThrowIfFailed(Napi::Env env, EdsError errorCode, Napi::Value defaultValue);

            static Napi::Value Throw(Napi::Env env, EdsError errorCode);

        private:
            static Napi::FunctionReference constructor;
    };
}

#endif //NAPI_CANON_API_ERROR_H
