#include "object-event.h"
#include <unordered_map>
#include "utility.h"
#include "labels.h"

namespace CameraApi {

    Napi::FunctionReference ObjectEvent::constructor;

    ObjectEvent::ObjectEvent(const Napi::CallbackInfo &info)
        : Napi::ObjectWrap<ObjectEvent>(info), ApiIdentifier(info, "ObjectEvent", Labels::ObjectEventID) {
    }

    Napi::Object ObjectEvent::NewInstance(Napi::Env env, EdsUInt32 identifier) {
        Napi::EscapableHandleScope scope(env);
        Napi::Object wrap = constructor.New({Napi::Number::New(env, identifier)});
        return scope.Escape(napi_value(wrap)).ToObject();
    }

    void ObjectEvent::Init(Napi::Env env, Napi::Object exports) {
        Napi::HandleScope scope(env);

        Napi::Object IDs = Napi::Object::New(env);
        for (const auto &it : Labels::ObjectEventID) {
            IDs.DefineProperty(
                Napi::PropertyDescriptor::Value(
                    it.second.c_str(), Napi::Number::New(env, it.first), napi_enumerable
                )
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

        Napi::Function func = DefineClass(env, "ObjectEvent", properties);
        constructor = Napi::Persistent(func);
        constructor.SuppressDestruct();

        exports.Set("ObjectEvent", func);
    }
}