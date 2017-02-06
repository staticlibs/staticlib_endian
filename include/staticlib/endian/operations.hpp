/*
 * Copyright 2015, alex at staticlibs.net
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/* 
 * File:   operations.hpp
 * Author: alex
 *
 * Created on November 21, 2015, 9:09 PM
 */

#ifndef STATICLIB_ENDIAN_OPERATIONS_HPP
#define	STATICLIB_ENDIAN_OPERATIONS_HPP

#include <cstdint>

#include "staticlib/io/operations.hpp"

#include "staticlib/endian/config.hpp"

namespace staticlib {
namespace endian {

/**
 * Reads 2-byte little-endian integer from the specified source
 * 
 * @param src source
 * @return integer read
 */
template<typename IntType, typename Source>
IntType read_16_le(Source& src) {
    namespace si = staticlib::io;
    uint16_t res = 0;
    si::read_exact(src, {reinterpret_cast<char*> (std::addressof(res)), 2});
    return static_cast<IntType> (le16toh(res));
}

/**
 * Reads 2-byte big-endian integer from the specified source
 * 
 * @param src source
 * @return integer read
 */
template<typename IntType, typename Source>
IntType read_16_be(Source& src) {
    namespace si = staticlib::io;
    uint16_t res = 0;
    si::read_exact(src, {reinterpret_cast<char*> (std::addressof(res)), 2});
    return static_cast<IntType> (be16toh(res));
}

/**
 * Reads 4-byte little-endian integer from the specified source
 * 
 * @param src source
 * @return integer read
 */
template<typename IntType, typename Source>
IntType read_32_le(Source& src) {
    namespace si = staticlib::io;
    uint32_t res = 0;
    si::read_exact(src, {reinterpret_cast<char*> (std::addressof(res)), 4});
    return static_cast<IntType> (le32toh(res));
}

/**
 * Reads 4-byte big-endian integer from the specified source
 * 
 * @param src source
 * @return integer read
 */
template<typename IntType, typename Source>
IntType read_32_be(Source& src) {
    namespace si = staticlib::io;
    uint32_t res = 0;
    si::read_exact(src, {reinterpret_cast<char*> (std::addressof(res)), 4});
    return static_cast<IntType> (be32toh(res));
}

/**
 * Reads 8-byte little-endian integer from the specified source
 * 
 * @param src source
 * @return integer read
 */
template<typename IntType, typename Source>
IntType read_64_le(Source& src) {
    namespace si = staticlib::io;
    uint64_t res = 0;
    si::read_exact(src, {reinterpret_cast<char*> (std::addressof(res)), 8});
    return static_cast<IntType> (le64toh(res));
}

/**
 * Reads 8-byte big-endian integer from the specified source
 * 
 * @param src source
 * @return integer read
 */
template<typename IntType, typename Source>
IntType read_64_be(Source& src) {
    namespace si = staticlib::io;
    uint64_t res = 0;
    si::read_exact(src, {reinterpret_cast<char*> (std::addressof(res)), 8});
    return static_cast<IntType> (be64toh(res));
}

/**
 * Writes specified 2-byte integer to the specified sink in little-endian
 * 
 * @param sink destination sink
 * @param val integer to write
 */
template<typename IntType, typename Sink>
void write_16_le(Sink& sink, IntType val) {
    namespace si = staticlib::io;
    uint16_t val16 = le16toh(static_cast<uint16_t> (val));
    si::write_all(sink, {reinterpret_cast<char*> (std::addressof(val16)), 2});
}

/**
 * Writes specified 2-byte integer to the specified sink in big-endian
 * 
 * @param sink destination sink
 * @param val integer to write
 */
template<typename IntType, typename Sink>
void write_16_be(Sink& sink, IntType val) {
    namespace si = staticlib::io;
    uint16_t val16 = be16toh(static_cast<uint16_t> (val));
    si::write_all(sink, {reinterpret_cast<char*> (std::addressof(val16)), 2});
}

/**
 * Writes specified 4-byte integer to the specified sink in little-endian
 * 
 * @param sink destination sink
 * @param val integer to write
 */
template<typename IntType, typename Sink>
void write_32_le(Sink& sink, IntType val) {
    namespace si = staticlib::io;
    uint32_t val32 = le32toh(static_cast<uint32_t> (val));
    si::write_all(sink, {reinterpret_cast<char*> (std::addressof(val32)), 4});
}

/**
 * Writes specified 4-byte integer to the specified sink in big-endian
 * 
 * @param sink destination sink
 * @param val integer to write
 */
template<typename IntType, typename Sink>
void write_32_be(Sink& sink, IntType val) {
    namespace si = staticlib::io;
    uint32_t val32 = be32toh(static_cast<uint32_t> (val));
    si::write_all(sink, {reinterpret_cast<char*> (std::addressof(val32)), 4});
}

/**
 * Writes specified 8-byte integer to the specified sink in little-endian
 * 
 * @param sink destination sink
 * @param val integer to write
 */
template<typename IntType, typename Sink>
void write_64_le(Sink& sink, IntType val) {
    namespace si = staticlib::io;
    uint64_t val64 = le64toh(static_cast<uint64_t> (val));
    si::write_all(sink, {reinterpret_cast<char*> (std::addressof(val64)), 8});
}

/**
 * Writes specified 8-byte integer to the specified sink in big-endian
 * 
 * @param sink destination sink
 * @param val integer to write
 */
template<typename IntType, typename Sink>
void write_64_be(Sink& sink, IntType val) {
    namespace si = staticlib::io;
    uint64_t val64 = be64toh(static_cast<uint64_t> (val));
    si::write_all(sink, {reinterpret_cast<char*> (std::addressof(val64)), 8});
}

} // namespace
}

#endif	/* STATICLIB_ENDIAN_OPERATIONS_HPP */

