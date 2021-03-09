#ifndef NAPI_CANON_API_OBJECT_EVENT_ID_H
#define NAPI_CANON_API_OBJECT_EVENT_ID_H

#include "types.h"
#include "api-identifier.h"

namespace CameraApi {

    class ObjectEvent : public Napi::ObjectWrap<ObjectEvent>, public ApiIdentifier {
        public:
            ObjectEvent(const Napi::CallbackInfo &info);

            static void Init(Napi::Env env, Napi::Object exports);

            static Napi::Object NewInstance(Napi::Env env, EdsUInt32 identifier);
        private:
            static Napi::FunctionReference constructor;
            static constexpr const char JSClassName[] = "ObjectEvent";
    };
}

#endif //NAPI_CANON_API_OBJECT_EVENT_ID_H
