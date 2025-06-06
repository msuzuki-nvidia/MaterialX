//
// Copyright Contributors to the MaterialX Project
// SPDX-License-Identifier: Apache-2.0
//

#ifndef MATERIALX_LIBRARY_H
#define MATERIALX_LIBRARY_H

/// @file
/// Library-wide includes and types.  This file should be the first include for
/// any public header in the MaterialX library.

#include <algorithm>
#include <cstdint>
#include <cstdlib>
#include <functional>
#include <memory>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>

#include <MaterialXCore/Generated.h>

#define MATERIALX_GENERATE_INDEX(major, minor, build) (((major) << 22U) | ((minor) << 12U) | (build))

#define MATERIALX_VERSION_INDEX \
    MATERIALX_GENERATE_INDEX(MATERIALX_MAJOR_VERSION, MATERIALX_MINOR_VERSION, MATERIALX_BUILD_VERSION)

/// Platform-specific macros for declaring imported and exported symbols.
#if defined(MATERIALX_BUILD_SHARED_LIBS)
    #if defined(_WIN32)
        #pragma warning(disable : 4251)
        #pragma warning(disable : 4275)
        #pragma warning(disable : 4661)
        #define MATERIALX_SYMBOL_EXPORT __declspec(dllexport)
        #define MATERIALX_SYMBOL_IMPORT __declspec(dllimport)
        #define MATERIALX_EXPORT_EXTERN_TEMPLATE(...) template class MATERIALX_SYMBOL_EXPORT __VA_ARGS__
        #define MATERIALX_IMPORT_EXTERN_TEMPLATE(...) extern template class MATERIALX_SYMBOL_IMPORT __VA_ARGS__
    #else
        #define MATERIALX_SYMBOL_EXPORT __attribute__((__visibility__("default")))
        #define MATERIALX_SYMBOL_IMPORT __attribute__((__visibility__("default")))
        #define MATERIALX_EXPORT_EXTERN_TEMPLATE(...) template class MATERIALX_SYMBOL_EXPORT __VA_ARGS__
        #define MATERIALX_IMPORT_EXTERN_TEMPLATE(...) extern template class MATERIALX_SYMBOL_IMPORT __VA_ARGS__
    #endif
#else
    #define MATERIALX_SYMBOL_EXPORT
    #define MATERIALX_SYMBOL_IMPORT
    #define MATERIALX_EXPORT_EXTERN_TEMPLATE(...)
    #define MATERIALX_IMPORT_EXTERN_TEMPLATE(...)
#endif

MATERIALX_NAMESPACE_BEGIN

using std::string;
using std::vector;
using std::shared_ptr;
using std::weak_ptr;

/// A vector of strings.
using StringVec = vector<string>;
/// An unordered map with strings as both keys and values.
using StringMap = std::unordered_map<string, string>;
/// A set of strings.
using StringSet = std::set<string>;

MATERIALX_NAMESPACE_END

#endif
