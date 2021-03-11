#ifndef NAPI_CANON_API_OBJECT_EVENT_ID_H
#define NAPI_CANON_API_OBJECT_EVENT_ID_H

#include "types.h"
#include "api-identifier.h"

namespace CameraApi {

    class ObjectEvent : public Napi::ObjectWrap<ObjectEvent>, public ApiIdentifier {
        public:
            explicit ObjectEvent(const Napi::CallbackInfo &info);

            static void Init(Napi::Env env, Napi::Object exports);

            static Napi::Object NewInstance(Napi::Env env, EdsUInt32 identifier);

        private:
            static constexpr const char JSClassName[] = "ObjectEvent";

            static inline Napi::Function JSConstructor(Napi::Function *func = nullptr) {
                static Napi::FunctionReference constructor;

                if (func != nullptr) {
                    constructor = Napi::Persistent(*func);
                    constructor.SuppressDestruct();
                }
                return constructor.Value();
            }
    };
}

#endif //NAPI_CANON_API_OBJECT_EVENT_ID_H
