#ifndef NAPI_CANON_API_OPTION_H
#define NAPI_CANON_API_OPTION_H

#include "types.h"

namespace CameraApi {

    class ApiIdentifier {
        public:
            ApiIdentifier(const Napi::CallbackInfo &info, const std::string &name, const LabelMap &labels);

            Napi::Value GetLabel(const Napi::CallbackInfo &info);

            Napi::Value GetIdentifier(const Napi::CallbackInfo &info);

            Napi::Value EqualTo(const Napi::CallbackInfo &info);

            Napi::Value GetPrimitive(const Napi::CallbackInfo &info);

            virtual Napi::Value ToJSON(const Napi::CallbackInfo &info);

            virtual Napi::Value Inspect(const Napi::CallbackInfo &info);

            virtual Napi::Value ToStringTag(const Napi::CallbackInfo &info);

        protected:
            std::string name_ = "ApiIdentifier";
            int identifier_ = 0;
            LabelMap labels_;
    };
}

#endif //NAPI_CANON_API_OPTION_H
