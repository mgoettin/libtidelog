#include "tidelog.hpp"
#include "chunk.hpp"

#include <cstdint>

namespace tide {
namespace log {

/**
   The ChunkEntry
   Store the meta data of a single chunk
 */
ChunkEntry::ChunkEntry(const uint64_t timestamp, 
		       const Array& data) : timestamp(timestamp), 
					    length(sizeof(ENTRY) + 4 + data.length) {};

/**
   Get the timestamp

*/
uint64_t ChunkEntry::get_timestamp() const {
    return timestamp;
}

/** 
    Get the lenth of data in the entry
*/
uint64_t ChunkEntry::get_length() const {
    return length;
}

/**
   The Chunk constructor
*/    
Chunk::Chunk(const int id, const off_t start) : id(id), start_filepos(start),
						start_timestamp(UINT64_MAX), 
						end_timestamp(0), 
						chunk_length(sizeof(CHUNK)), 
						num_entries(0) {
}

/**
   Update the chunk meta data in ChunkEntry
*/
void Chunk::update(const ChunkEntry& entry) {
    if(entry.get_timestamp() < start_timestamp) {	
	start_timestamp = entry.get_timestamp();
    }
    if(entry.get_timestamp() > end_timestamp) {
	end_timestamp = entry.get_timestamp();
    }
    chunk_length += entry.get_length();
    ++num_entries;
}

/**
   Get the size of the chunk
*/
uint64_t Chunk::get_size() const {
    return this->chunk_length;
}

/**
   Get the starting file position of the chunk
*/
off_t Chunk::get_start() const {
    return this->start_filepos;
}

/**
   Get the CHUNK
*/
CHUNK Chunk::get_header() const {
    return CHUNK(id, num_entries, start_timestamp, end_timestamp, 0);
}


std::ostream& operator<<(std::ostream& out, const Chunk& c) {
    const CHUNK& chunk(c.get_header());
    out << chunk.id << ' ' << chunk.count << ' ' << chunk.start
	<< ' ' << chunk.end << ' ' << chunk.compression << ' ' 
	<< c.get_size() << std::endl;
    return out;
}

} //namespace log
} //namespace tide
