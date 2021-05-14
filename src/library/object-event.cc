#include "object-event.h"
#include <unordered_map>
#include "utility.h"
#include "labels.h"

namespace CameraApi {

    ObjectEvent::ObjectEvent(const Napi::CallbackInfo &info)
        : Napi::ObjectWrap<ObjectEvent>(info), ApiIdentifier(info, ObjectEvent::JSClassName, Labels::ObjectEventID) {
    }

    Napi::Object ObjectEvent::NewInstance(Napi::Env env, EdsUInt32 identifier) {
        Napi::EscapableHandleScope scope(env);
        Napi::Object wrap = JSConstructor().New({Napi::Number::New(env, identifier)});
        return scope.Escape(napi_value(wrap)).ToObject();
    }

    void ObjectEvent::Init(Napi::Env env, Napi::Object exports) {
        Napi::HandleScope scope(env);

        Napi::Object IDs = Napi::Object::New(env);
        for (const auto &it : Labels::ObjectEventID) {
            IDs.Set(
                it.second, Napi::Number::New(env, it.first)
            );
        }

        std::vector <PropertyDescriptor> properties = {
            InstanceAccessor("label", &ObjectEvent::GetLabel, nullptr),
            InstanceAccessor("identifier", &ObjectEvent::GetIdentifier, nullptr),
            InstanceMethod("toJSON", &ObjectEvent::ToJSON),
            InstanceMethod("equalTo", &ObjectEvent::EqualTo),

            InstanceMethod(Napi::Symbol::WellKnown(env, "toPrimitive"), &ObjectEvent::GetPrimitive),
            InstanceMethod(GetPublicSymbol(env, "nodejs.util.inspect.custom"), &ObjectEvent::Inspect),
            InstanceAccessor(Napi::Symbol::WellKnown(env, "toStringTag"), &ObjectEvent::ToStringTag, nullptr),

            StaticValue("ID", IDs, napi_enumerable)
        };

        Napi::Function func = DefineClass(env, ObjectEvent::JSClassName, properties);
        JSConstructor(&func);

        exports.Set(ObjectEvent::JSClassName, func);
    }
}
