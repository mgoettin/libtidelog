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

#include <string>
#include <cstring>
#include <vector>

#include <BufferReference.h>

namespace tide {
namespace log {

/**
   The Channel
   A channel stores a set of data entries of a single type, indexed by time.
   @param id Channel identification, used to link entries to the channel.
   @param name Name of the channel, as a character string.
   @param type String describing the type of the format.
   @param source_name Human-readable source description.
   @param source_spec Raw data describing the source of this channel's data.
   @param fmt_spec Raw data describing the format of the channel's data.
*/
class Channel {
public:
    const int id;
    const std::string name, source_name, type;
    
private:
    std::vector<uint8_t> source_config, format;
    
public:
    
    Channel(int id, const std::string& name, const std::string& type,
	    const std::string& source_name, const Array& source_spec,
	    const Array& fmt_spec) : id(id), name(name), 
				     source_name(source_name), 
				     type(type) {
	source_config.reserve(source_spec.length);
	memcpy(&(source_config[0]), source_spec.bytes, source_spec.length);
	format.reserve(fmt_spec.length);
	memcpy(&(format[0]), fmt_spec.bytes, fmt_spec.length);                
    };
            
    const std::vector<uint8_t>& get_source_config() const {
	return source_config;
    }
    const std::vector<uint8_t>& get_format() const {
	return format;
    }
};


} //namespace log
} //namespace tide
