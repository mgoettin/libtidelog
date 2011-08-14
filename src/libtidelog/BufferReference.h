/* ============================================================
 *
 * This file is a part of the RSB project
 *
 * Copyright (C) 2011 by Ingo Lütkebohle <iluetkeb.techfak.uni-bielefeld.de>                                      
 *
 * This program is free software; you can redistribute it
 * and/or modify it under the terms of the GNU General
 * Public License as published by the Free Software Foundation;
 * either version 2, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * ============================================================ */

# pragma once

#inlcude <ctsring>

namespace tide {
namespace log {

/**
   Data container format
*/

template<typename T>
class BufferReference {
public:
    BufferReference(const char* bytes, const T length) : bytes(bytes), length(length) {};
    BufferReference(const char* null_terminated_string) : bytes(null_terminated_string), 
							  length(strlen(null_terminated_string)) {};
  
    const void* bytes;
    const T length;
};

typedef BufferReference<uint8_t> SArray;
typedef BufferReference<uint32_t> Array;

} //namespace log
} //namespace tide
