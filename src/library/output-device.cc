#include "output-device.h"
#include "utility.h"

namespace CameraApi {

    LabelMap OutputDeviceLabels = {
        {kEdsEvfOutputDevice_TFT, "TFT"},
        {kEdsEvfOutputDevice_PC, "PC"},
        {kEdsEvfOutputDevice_PC_Small, "PCSmall"},
    };

    OutputDevice::OutputDevice(const Napi::CallbackInfo &info) : ObjectWrap(info) {
        Napi::Env env = info.Env();
        Napi::HandleScope scope(env);

        if (info.Length() > 0 && info[0].IsNumber()) {
            value_ = info[0].As<Napi::Number>().Int32Value();
        } else {
            throw Napi::TypeError::New(
                info.Env(), "Argument 0 must be a output device bitmask."
            );
        }

    }

    Napi::Value OutputDevice::GetLabel(const Napi::CallbackInfo &info) {
        std::string label;
        for (const auto& it : OutputDeviceLabels) {
            auto deviceID = it.first;
            if (IsEnabled(deviceID)) {
                label.append(", ");
                label.append(it.second);
            }
        }
        if (label.empty()) {
            label = ", None";
        }
        return Napi::String::New(info.Env(), label.substr(2));
    }

    Napi::Value OutputDevice::GetValue(const Napi::CallbackInfo &info) {
        return Napi::Number::New(info.Env(), value_);
    }

    EdsInt32 OutputDevice::GetValueForDeviceName(const std::string& deviceName) {
        for (const auto& it : OutputDeviceLabels) {
            if (it.second == deviceName) {
                return it.first;
            }
        }
        return 0;
    }

    Napi::Value OutputDevice::GetPrimitive(const Napi::CallbackInfo &info) {
        if (info.Length() > 0 && info[0].IsString()) {
            std::string hint = info[0].As<Napi::String>().Utf8Value();
            if (hint == "number") {
                return GetValue(info);
            }
            if (hint == "string") {
                return GetLabel(info);
            }
        }
        return info.Env().Null();
    }

    Napi::Value OutputDevice::ToJSON(const Napi::CallbackInfo &info) {
        auto env = info.Env();
        auto json = Napi::Object::New(env);
        json.Set("label", GetLabel(info));
        json.Set("value", GetValue(info));
        auto status = Napi::Object::New(env);
        for (const auto& it : OutputDeviceLabels) {
            status.Set(it.second, Napi::Boolean::New(env, IsEnabled(it.first)));
        }
        json.Set("devices", status);
        return json;
    }

    Napi::Value OutputDevice::ToStringTag(const Napi::CallbackInfo &info) {
        return Napi::String::New(info.Env(), OutputDevice::JSClassName);
    }

    Napi::Value OutputDevice::Inspect(const Napi::CallbackInfo &info) {
        auto env = info.Env();
        auto stylize = info[1].As<Napi::Object>().Get("stylize").As<Napi::Function>();
        std::string output = stylize.Call(
            {Napi::String::New(env, OutputDevice::JSClassName), Napi::String::New(env, "special")}
        ).As<Napi::String>().Utf8Value();
        output.append(" <");
        bool needsSeparator = false;
        for (auto it : OutputDeviceLabels) {
            auto deviceID = it.first;
            if (IsEnabled(deviceID)) {
                if (needsSeparator) {
                    output.append("|");
                }
                output.append(
                    stylize.Call(
                        {Napi::String::New(env, it.second), Napi::String::New(env, "symbol")}
                    ).As<Napi::String>().Utf8Value()
                );
                needsSeparator = true;
            }
        }
        if (!needsSeparator) {
            output.append(
                stylize.Call(
                    {Napi::String::New(env, "None"), Napi::String::New(env, "symbol")}
                ).As<Napi::String>().Utf8Value()
            );
        }
        output.append(">");
        return Napi::String::New(env, output);
    }

    Napi::Value OutputDevice::GetDevices(const Napi::CallbackInfo &info) {
        auto devices = Napi::Array::New(info.Env());
        int index = 0;
        for (auto it : OutputDeviceLabels) {
            auto deviceID = it.first;
            if (IsEnabled(deviceID)) {
                devices.Set(index, deviceID);
                index++;
            }
        }
        return devices;
    }

    bool OutputDevice::IsEnabled(EdsInt32 deviceID) const {
        return (value_ & deviceID) == deviceID;
    }

    Napi::Value OutputDevice::IsEnabled(const Napi::CallbackInfo &info) {
        if (!(info.Length() > 0 && info[0].IsNumber())) { ;
            throw Napi::TypeError::New(
                info.Env(), "Argument 0 must be a output device id."
            );
        }
        return Napi::Boolean::New(
            info.Env(), IsEnabled(info[0].As<Napi::Number>().Int32Value())
        );
    }

    Napi::Value OutputDevice::ForLabel(const Napi::CallbackInfo &info) {
        if (!(info.Length() > 0 && info[0].IsString())) { ;
            throw Napi::TypeError::New(
                info.Env(), "Argument 0 must be a label string."
            );
        }
        std::string separator = ",";
        std::string label = info[0].As<Napi::String>().Utf8Value();
        size_t separatorOffset = 0;
        EdsInt32 value = 0;
        while ((separatorOffset = label.find(separator)) != std::string::npos) {
            std::string deviceName = trim_copy(label.substr(0, separatorOffset));
            value |= GetValueForDeviceName(deviceName);
            label.erase(0, separatorOffset + 1);
        }
        trim(label);
        value |= GetValueForDeviceName(label);
        return NewInstance(info.Env(), value);
    }

    Napi::Object OutputDevice::NewInstance(Napi::Env env, EdsInt32 value) {
        Napi::EscapableHandleScope scope(env);
        Napi::Object wrap = JSConstructor().New(
            {
                Napi::Number::New(env, value)
            }
        );
        return scope.Escape(napi_value(wrap)).ToObject();
    }

    void OutputDevice::Init(Napi::Env env, Napi::Object exports) {
        Napi::Object IDs = Napi::Object::New(env);
        IDs.Set("None", Napi::Number::New(env, 0));
        for (const auto &it : OutputDeviceLabels) {
            IDs.Set(
                it.second, Napi::Number::New(env, it.first)
            );
        }

        std::vector<PropertyDescriptor> properties = {
            InstanceAccessor<&OutputDevice::GetLabel>("label"),
            InstanceAccessor<&OutputDevice::GetValue>("value"),
            InstanceMethod<&OutputDevice::IsEnabled>("isEnabled"),
            InstanceMethod<&OutputDevice::GetDevices>("getDevices"),

            InstanceMethod(Napi::Symbol::WellKnown(env, "toPrimitive"), &OutputDevice::GetPrimitive),
            InstanceMethod("toJSON", &OutputDevice::ToJSON),

            InstanceAccessor<&OutputDevice::ToStringTag>(Napi::Symbol::WellKnown(env, "toStringTag")),
            InstanceMethod(GetPublicSymbol(env, "nodejs.util.inspect.custom"), &OutputDevice::Inspect),

            StaticMethod<&OutputDevice::ForLabel>("forLabel"),
            StaticValue("ID", IDs, napi_enumerable)
        };

        Napi::Function func = DefineClass(env, OutputDevice::JSClassName, properties);
        JSConstructor(&func);

        exports.Set(OutputDevice::JSClassName, func);
    }
}
