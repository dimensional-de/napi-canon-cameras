#include "time-zone.h"
#include "utility.h"

namespace CameraApi {

    LabelMap TimeZoneLabels = {
        {0x0000, "None"},
        {0x0001, "Chatham Islands"},
        {0x0002, "Wellington"},
        {0x0003, "Solomon Island"},
        {0x0004, "Sydney"},
        {0x0005, "Adeladie"},
        {0x0006, "Tokyo"},
        {0x0007, "Hong Kong"},
        {0x0008, "Bangkok"},
        {0x0009, "Yangon"},
        {0x000A, "Dacca"},
        {0x000B, "Kathmandu"},
        {0x000C, "Delhi"},
        {0x000D, "Karachi"},
        {0x000E, "Kabul"},
        {0x000F, "Dubai"},
        {0x0010, "Tehran"},
        {0x0011, "Moscow"},
        {0x0012, "Cairo"},
        {0x0013, "Paris"},
        {0x0014, "London"},
        {0x0015, "Azores"},
        {0x0016, "Fernando de Noronha"},
        {0x0017, "São Paulo"},
        {0x0018, "Newfoundland"},
        {0x0019, "Santiago"},
        {0x001A, "Caracas"},
        {0x001B, "New York"},
        {0x001C, "Chicago"},
        {0x001D, "Denver"},
        {0x001E, "Los Angeles"},
        {0x001F, "Anchorage"},
        {0x0020, "Honolulu"},
        {0x0021, "Samoa"},
        {0x0022, "Riyadh"},
        {0x0023, "Manaus"},
        {0x0100, "UTC"},
        {0xFFFF, "UTC"}
    };

    TimeZone::TimeZone(const Napi::CallbackInfo &info)
        : Napi::ObjectWrap<TimeZone>(info) {

        Napi::Env env = info.Env();
        Napi::HandleScope scope(env);

        EdsUInt32 value;

        if (info.Length() > 0 && info[0].IsNumber()) {
            value = info[0].As<Napi::Number>().Uint32Value();
        } else {
            throw Napi::TypeError::New(
                info.Env(), "Argument 0 must be a property value."
            );
        }

        value_ = value;
        difference_ = (((1 << 16) - 1) & (value >> (0)));
        zone_ = (((1 << 16) - 1) & (value >> (16)));
    }

    std::string TimeZone::GetDifferenceAsOffset(EdsInt32 differenceInMinutes) {
        auto hours = (int)std::floor(differenceInMinutes / 60);
        auto minutes = (int)std::abs(differenceInMinutes - (hours * 60));
        return stringFormat(
            "%s%02d:%02d",
            hours < 0 ? "-" : "+",
            (int)std::abs(hours),
            minutes
        );
    }

    Napi::Value TimeZone::GetLabel(const Napi::CallbackInfo &info) {
        if (TimeZoneLabels.find(zone_) != TimeZoneLabels.end()) {
            auto label = GetDifferenceAsOffset(difference_);
            label.append(" ");
            label.append(TimeZoneLabels[zone_]);
            return Napi::String::New(info.Env(), label);
        }
        return Napi::String::New(info.Env(), CodeToHexLabel(zone_));
    }

    Napi::Value TimeZone::GetValue(const Napi::CallbackInfo &info) {
        return Napi::Number::New(info.Env(), value_);
    }

    Napi::Value TimeZone::GetZone(const Napi::CallbackInfo &info) {
        return Napi::Number::New(info.Env(), zone_);
    }

    Napi::Value TimeZone::GetDifference(const Napi::CallbackInfo &info) {
        return Napi::Number::New(info.Env(), difference_);
    }

    Napi::Value TimeZone::GetPrimitive(const Napi::CallbackInfo &info) {
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

    Napi::Value TimeZone::ToJSON(const Napi::CallbackInfo &info) {
        auto env = info.Env();
        auto json = Napi::Object::New(env);
        json.Set("label", GetLabel(info));
        json.Set("value", GetValue(info));
        json.Set("zone", GetZone(info));
        json.Set("difference", GetDifference(info));
        return json;
    }

    Napi::Value TimeZone::ToStringTag(const Napi::CallbackInfo &info) {
        return Napi::String::New(info.Env(), TimeZone::JSClassName);
    }

    Napi::Value TimeZone::Inspect(const Napi::CallbackInfo &info) {
        bool existingZone = false;
        std::string label;
        if (TimeZoneLabels.find(zone_) != TimeZoneLabels.end()) {
            existingZone = true;
            label = GetDifferenceAsOffset(difference_);
            label.append(" ");
            label.append(TimeZoneLabels[zone_]);
        } else {
            label = CodeToHexLabel(value_);
        }
        auto env = info.Env();
        auto stylize = info[1].As<Napi::Object>().Get("stylize").As<Napi::Function>();
        std::string output = stylize.Call(
            {Napi::String::New(env, TimeZone::JSClassName), Napi::String::New(env, "special")}
        ).As<Napi::String>().Utf8Value();
        output.append(" <");
        output.append(
            stylize.Call(
                {
                    Napi::String::New(env, label),
                    Napi::String::New(env, existingZone ? "symbol" : "number")
                }
            ).As<Napi::String>().Utf8Value()
        );
        output.append(">");
        return Napi::String::New(env, output);
    }

    Napi::Object TimeZone::NewInstance(Napi::Env env, EdsUInt32 value) {
        Napi::EscapableHandleScope scope(env);
        Napi::Object wrap = JSConstructor().New(
            {
                Napi::Number::New(env, value)
            }
        );
        return scope.Escape(napi_value(wrap)).ToObject();
    }

    void TimeZone::Init(Napi::Env env, Napi::Object exports) {

        Napi::HandleScope scope(env);

        Napi::Object Zones = Napi::Object::New(env);
        for (const auto &it : TimeZoneLabels) {
            Zones.Set(it.first, Napi::String::New(env, it.second));
        }

        std::vector <PropertyDescriptor> properties = {
            InstanceAccessor<&TimeZone::GetLabel>("label"),
            InstanceAccessor<&TimeZone::GetValue>("value"),
            InstanceAccessor<&TimeZone::GetZone>("zone"),
            InstanceAccessor<&TimeZone::GetDifference>("difference"),

            InstanceMethod(Napi::Symbol::WellKnown(env, "toPrimitive"), &TimeZone::GetPrimitive),
            InstanceMethod("toJSON", &TimeZone::ToJSON),

            InstanceAccessor<&TimeZone::ToStringTag>(Napi::Symbol::WellKnown(env, "toStringTag")),
            InstanceMethod(GetPublicSymbol(env, "nodejs.util.inspect.custom"), &TimeZone::Inspect),

            StaticValue("Zones", Zones, napi_enumerable)
        };

        Napi::Function func = DefineClass(env, TimeZone::JSClassName, properties);
        JSConstructor(&func);

        exports.Set(TimeZone::JSClassName, func);
    }
}
