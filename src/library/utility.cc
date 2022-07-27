#include "utility.h"
#include <stdexcept>

namespace CameraApi {

    std::string CodeToHexLabel(EdsUInt32 code) {
        char label[11];
#ifdef __MACOS__
        snprintf(label, 11, "0x%08x", code);
#else
        sprintf_s(label, "0x%08x", code);
#endif
        return label;
    }

    int ReadBitsValue(EdsInt32 buffer, int offset, int length) {
        return (((1 << length) - 1) & (buffer >> (offset)));
    }

    Napi::Symbol GetPublicSymbol(const Napi::Env &env, const std::string &name) {
        auto Symbol = env.Global().Get("Symbol").As<Napi::Object>();
        auto forSymbol = Symbol.Get("for").As<Napi::Function>().Call(
            Symbol, {Napi::String::New(env, name)}
        );
        return forSymbol.As<Napi::Symbol>();
    }
}
