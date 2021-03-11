#ifndef NAPI_CANON_API_PROPERTY_OPTION_H
#define NAPI_CANON_API_PROPERTY_OPTION_H

#include "types.h"
#include <unordered_map>

namespace CameraApi {

    class PropertyOption : public Napi::ObjectWrap<PropertyOption> {
        public:
            explicit PropertyOption(const Napi::CallbackInfo &info);

            static void Init(Napi::Env env, Napi::Object exports);

            static Napi::Object NewInstance(Napi::Env env, EdsInt32 identifier, EdsInt32 value);

            static bool IsClassOf(Napi::Value value);

            static bool IsOptionsProperty(EdsPropertyID propertyID);

        private:
            static constexpr const char JSClassName[] = "PropertyOption";

            static inline Napi::Function JSConstructor(Napi::Function *func = nullptr) {
                static Napi::FunctionReference constructor;

                if (func != nullptr) {
                    constructor = Napi::Persistent(*func);
                    constructor.SuppressDestruct();
                }
                return constructor.Value();
            }

            EdsPropertyID propertyIdentifier_ = 0;
            EdsInt32 value_ = 0;
            std::string label_;
            bool isNamedValue_ = false;

            Napi::Value GetLabel(const Napi::CallbackInfo &info);

            Napi::Value GetValue(const Napi::CallbackInfo &info);

            Napi::Value GetPropertyID(const Napi::CallbackInfo &info);

            Napi::Value GetPrimitive(const Napi::CallbackInfo &info);

            Napi::Value ToJSON(const Napi::CallbackInfo &info);

            Napi::Value ToStringTag(const Napi::CallbackInfo &info);

            Napi::Value Inspect(const Napi::CallbackInfo &info);

            static Napi::Value ForLabel(const Napi::CallbackInfo &info);

            static Napi::Object CreateOptionGroup(Napi::Env env, const LabelMap &labels);
    };
}

#endif //NAPI_CANON_API_PROPERTY_OPTION_H
