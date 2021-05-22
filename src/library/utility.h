#ifndef CANON_API_UTILITY_H
#define CANON_API_UTILITY_H

#include <napi.h>
#include <EDSDKTypes.h>
#include <cctype>

namespace CameraApi {

    std::string CodeToHexLabel(int code);

    int ReadBitsValue(EdsInt32 buffer, int offset, int length);

    Napi::Symbol GetPublicSymbol(const Napi::Env &env, const std::string &name);

    /**
     * Convert all std::strings to const char* using constexpr if (C++17)
     */
    template<typename T>
    auto convert(T &&t) {
        if constexpr (std::is_same<std::remove_cv_t<std::remove_reference_t<T>>, std::string>::value) {
            return std::forward<T>(t).c_str();
        } else {
            return std::forward<T>(t);
        }
    }

    /**
     * printf like formatting for C++ with std::string
     * Original source: https://stackoverflow.com/a/26221725/11722
     */
    template<typename ... Args>
    std::string stringFormatInternal(const std::string &format, Args &&... args) {
        size_t size = snprintf(nullptr, 0, format.c_str(), std::forward<Args>(args) ...) + 1;
        if (size <= 0) { throw std::runtime_error("Error during formatting."); }
        std::unique_ptr<char[]> buf(new char[size]);
        snprintf(buf.get(), size, format.c_str(), args ...);
        return std::string(buf.get(), buf.get() + size - 1);
    }

    template<typename ... Args>
    std::string stringFormat(std::string fmt, Args &&... args) {
        return stringFormatInternal(fmt, convert(std::forward<Args>(args))...);
    }

    static inline void ltrim(std::string &s) {
        s.erase(
            s.begin(), std::find_if(
                s.begin(), s.end(), [](unsigned char ch) {
                    return !std::isspace(ch);
                }
            ));
    }

    // trim from end (in place)
    static inline void rtrim(std::string &s) {
        s.erase(
            std::find_if(
                s.rbegin(), s.rend(), [](unsigned char ch) {
                    return !std::isspace(ch);
                }
            ).base(), s.end());
    }

    // trim from both ends (in place)
    static inline void trim(std::string &s) {
        ltrim(s);
        rtrim(s);
    }

    // trim from start (copying)
    static inline std::string ltrim_copy(std::string s) {
        ltrim(s);
        return s;
    }

    // trim from end (copying)
    static inline std::string rtrim_copy(std::string s) {
        rtrim(s);
        return s;
    }

    // trim from both ends (copying)
    static inline std::string trim_copy(std::string s) {
        trim(s);
        return s;
    }
}

#endif
