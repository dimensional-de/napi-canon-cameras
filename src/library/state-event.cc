#include "state-event.h"
#include "api-identifier.h"
#include "utility.h"
#include "labels.h"

namespace CameraApi {

    StateEvent::StateEvent(const Napi::CallbackInfo &info)
        : Napi::ObjectWrap<StateEvent>(info), ApiIdentifier(info, StateEvent::JSClassName, Labels::StateEventID)  {
    }

    Napi::Object StateEvent::NewInstance(Napi::Env env, EdsUInt32 identifier) {
        Napi::EscapableHandleScope scope(env);
        Napi::Object wrap = JSConstructor().New({Napi::Number::New(env, identifier)});
        return scope.Escape(napi_value(wrap)).ToObject();
    }

    void StateEvent::Init(Napi::Env env, Napi::Object exports) {
        Napi::HandleScope scope(env);

        Napi::Object IDs = Napi::Object::New(env);
        for (const auto &it : Labels::StateEventID) {
            IDs.DefineProperty(
                Napi::PropertyDescriptor::Value(
                    it.second.c_str(), Napi::Number::New(env, it.first), napi_enumerable
                )
            );
        }

        std::vector <PropertyDescriptor> properties = {
            InstanceAccessor("label", &StateEvent::GetLabel, nullptr),
            InstanceAccessor("identifier", &StateEvent::GetIdentifier, nullptr),
            InstanceMethod("toJSON", &StateEvent::ToJSON),
            InstanceMethod("equalTo", &StateEvent::EqualTo),

            InstanceMethod(Napi::Symbol::WellKnown(env, "toPrimitive"), &StateEvent::GetPrimitive),
            InstanceMethod(GetPublicSymbol(env, "nodejs.util.inspect.custom"), &StateEvent::Inspect),
            InstanceAccessor(Napi::Symbol::WellKnown(env, "toStringTag"), &StateEvent::ToStringTag, nullptr),

            StaticValue("ID", IDs, napi_enumerable)
        };

        Napi::Function func = DefineClass(env, StateEvent::JSClassName, properties);
        JSConstructor(&func);

        exports.Set(StateEvent::JSClassName, func);
    }
}
