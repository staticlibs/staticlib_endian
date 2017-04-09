Staticlibs Endian library
=========================

This project is a part of [Staticlibs](http://staticlibs.net/).

This project provides cross-platform endian-specific macros based on this Public Domain 
[code](https://gist.github.com/panzi/6856583) and also implements endian-specific templated
operations for reading/writing integers from/to `Source`/`Sink` instances.

This library is header-only and depends on [staticlib_io](https://github.com/staticlibs/staticlib_io.git).

Link to the [API documentation](http://staticlibs.github.io/staticlib_endian/docs/html/namespacestaticlib_1_1endian.html).

Endian macros
-------------

The following provided macros should work on all supported platforms (`XX` means `16`, `32` or `64`):

 - `htobeXX(uintXX_t)`: converts specified integer from host to big endianness
 - `htoleXX(uintXX_t)`: converts specified integer from host to little endianness
 - `beXXtoh(uintXX_t)`: converts specified integer from big to host endianness
 - `leXXtoh(uintXX_t)`: converts specified integer from little to host endianness

Operations on Sources/Sinks
---------------------------

Reading integers from `Source`:

 - `read_XX_le(Source&)`: reads little-endian integer
 - `read_XX_be(Source&)`: reads big-endian integer

Writing integers to `Sink`:

 - `write_16_le(Sink&, uintXX_t)`: writes integer in little-endian
 - `write_16_be(Sink&, uintXX_t)`: writes integer in big-endian

License information
-------------------

This project is released under the [Apache License 2.0](http://www.apache.org/licenses/LICENSE-2.0).

Changelog
---------

**2017-04-08**
 * version 1.0.2
 * minor deps changes

**2016-01-22**

 * version 1.0.1
 * minor CMake changes

**2015-11-25**

 * version 1.0.0
 * initial public version
