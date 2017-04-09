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
 * File:   operations_test.cpp
 * Author: alex
 *
 * Created on November 25, 2015, 12:25 PM
 */

#include "staticlib/endian/operations.hpp"

#include <array>
#include <iostream>

#include "staticlib/io.hpp"

#include "staticlib/config/assert.hpp"

void test_read_16_le() {
    sl::io::string_source src{"42"};
    int16_t val = sl::endian::read_16_le<int16_t>(src);
    slassert(12852 == val);
}

void test_read_16_be() {
    sl::io::string_source src{"42"};
    int16_t val = sl::endian::read_16_be<int16_t>(src);
    slassert(13362 == val);
}

void test_read_32_le() {
    sl::io::string_source src{"4256"};
    int32_t val = sl::endian::read_32_le<int32_t>(src);
    slassert(909455924 == val);
}

void test_read_32_be() {
    sl::io::string_source src{"4256"};
    int32_t val = sl::endian::read_32_be<int32_t>(src);    
    slassert(875705654 == val);
}

void test_read_64_le() {
    sl::io::string_source src{"42563178"};
    int64_t val = sl::endian::read_64_le<int64_t>(src);
    slassert(4050760485865599540ll == val);
}

void test_read_64_be() {
    sl::io::string_source src{"42563178"};
    int64_t val = sl::endian::read_64_be<int64_t>(src);
    slassert(3761127145711155000ll == val);
}

void test_write_16_le() {
    sl::io::string_sink sink{};
    int16_t val = 12852;
    sl::endian::write_16_le(sink, val);
    slassert("42" == sink.get_string());
}

void test_write_16_be() {
    sl::io::string_sink sink{};
    int16_t val = 13362;
    sl::endian::write_16_be(sink, val);
    slassert("42" == sink.get_string());
}

void test_write_32_le() {
    sl::io::string_sink sink{};
    int32_t val = 909455924;
    sl::endian::write_32_le(sink, val);
    slassert("4256" == sink.get_string());
}

void test_write_32_be() {
    sl::io::string_sink sink{};
    int32_t val = 875705654;
    sl::endian::write_32_be(sink, val);
    slassert("4256" == sink.get_string());
}

void test_write_64_le() {
    sl::io::string_sink sink{};
    int64_t val = 4050760485865599540ll;
    sl::endian::write_64_le(sink, val);
    slassert("42563178" == sink.get_string());
}

void test_write_64_be() {
    sl::io::string_sink sink{};
    int64_t val = 3761127145711155000ll;
    sl::endian::write_64_be(sink, val);
    slassert("42563178" == sink.get_string());
}

int main() {
    try {
        test_read_16_le();
        test_read_16_be();
        test_read_32_le();
        test_read_32_be();
        test_read_64_le();
        test_read_64_be();
        test_write_16_le();
        test_write_16_be();
        test_write_32_le();
        test_write_32_be();
        test_write_64_le();
        test_write_64_be();
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
        return 1;
    }
    return 0;
}

