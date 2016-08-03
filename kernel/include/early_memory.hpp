//=======================================================================
// Copyright Baptiste Wicht 2013-2016.
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
//=======================================================================

/*
 * This header contains addresses where the init stage of the kernel writes information for the later stage
 */

#ifndef EARLY_MEMORY_H
#define EARLY_MEMORY_H

// The number of MiB used by the kernel
constexpr const uint32_t kernel_mib_address = 0x90000; //4 bytes (32 bits)

// The address of the kernel
constexpr const uint32_t kernel_address = 0x100000;  //1Mib aligned size (kernel_mib)

// Maximum number of early logs
constexpr const uint32_t MAX_EARLY_LOGGING = 128;

constexpr const uint32_t early_logs_count_address = 0x90004; // 4 bytes (32 bits)
constexpr const uint32_t early_logs_address = 0x90008; // 128 * 4 bytes (32 bits ) = 512

inline uint32_t kernel_mib(){
    return *reinterpret_cast<uint32_t*>(kernel_mib_address);
}

inline void kernel_mib(uint32_t value){
    *reinterpret_cast<uint32_t*>(kernel_mib_address) = value;
}

inline uint32_t early_logs_count(){
    return *reinterpret_cast<uint32_t*>(early_logs_count_address);
}

inline void early_logs_count(uint32_t value){
    *reinterpret_cast<uint32_t*>(early_logs_count_address) = value;
}

inline uint32_t* early_logs(){
    return *reinterpret_cast<uint32_t**>(early_logs_address);
}

#endif
