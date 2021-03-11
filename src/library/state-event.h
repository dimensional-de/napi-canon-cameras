#ifndef NAPI_CANON_API_STATE_EVENT_ID_H
#define NAPI_CANON_API_STATE_EVENT_ID_H

#include "types.h"
#include "api-identifier.h"
#include <unordered_map>

namespace CameraApi {

    class StateEvent : public Napi::ObjectWrap<StateEvent>, public ApiIdentifier {
        public:
            explicit StateEvent(const Napi::CallbackInfo &info);

            static void Init(Napi::Env env, Napi::Object exports);

            static Napi::Object NewInstance(Napi::Env env, EdsUInt32 identifier);
        private:
            static Napi::FunctionReference constructor;
            static constexpr const char JSClassName[] = "StateEvent";
    };
}

#endif //NAPI_CANON_API_STATE_EVENT_ID_H
