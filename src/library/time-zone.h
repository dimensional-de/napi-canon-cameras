#ifndef NAPI_CANON_CAMERAS_TIMEZONE_H
#define NAPI_CANON_CAMERAS_TIMEZONE_H

#include "types.h"

namespace CameraApi {
    class TimeZone : public Napi::ObjectWrap<TimeZone> {
        public:
            explicit TimeZone(const Napi::CallbackInfo &info);

            static void Init(Napi::Env env, Napi::Object exports);

            static Napi::Object NewInstance(Napi::Env env, EdsUInt32 value);

        private:
            static constexpr const char JSClassName[] = "TimeZone";

            static inline Napi::Function JSConstructor(Napi::Function *func = nullptr) {
                static Napi::FunctionReference constructor;

                if (func != nullptr) {
                    constructor = Napi::Persistent(*func);
                    constructor.SuppressDestruct();
                }
                return constructor.Value();
            }

            EdsUInt32 value_ = 0;
            EdsInt32 difference_ = 0;
            EdsInt32 zone_ = 0;

            Napi::Value GetLabel(const Napi::CallbackInfo &info);

            Napi::Value GetValue(const Napi::CallbackInfo &info);

            Napi::Value GetZone(const Napi::CallbackInfo &info);

            Napi::Value GetDifference(const Napi::CallbackInfo &info);

            Napi::Value GetPrimitive(const Napi::CallbackInfo &info);

            Napi::Value ToJSON(const Napi::CallbackInfo &info);

            Napi::Value ToStringTag(const Napi::CallbackInfo &info);

            Napi::Value Inspect(const Napi::CallbackInfo &info);
    };
}

#endif //NAPI_CANON_CAMERAS_TIMEZONE_H
