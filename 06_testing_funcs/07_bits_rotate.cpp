
#include <iostream>
#include <type_traits>
#include <cstdint>
#include <limits>
#include <typeinfo>

template <typename INT> 
constexpr uint8_t rotate_accumulator(INT val) {
    uint8_t ret = 0;
    // static_assert(std::is_unsigned<INT>::val,
    //              "Rotate Left only makes sense for unsigned types");
    ret = (val << 1) | (val >> 7);

    return ret;
}

// checksum
template <typename Container>
constexpr auto checksum(Container const &message) {
    constexpr int IdPosition = 6;
    int           ChecksumPosition = static_cast<int>(message.size()) - 1;
    uint8_t       sum = 0;
    for (auto i = IdPosition; i < ChecksumPosition; ++i)
        sum += message[i];
    return sum;
}

//check sum with evey bit rotate
// example string send 0x49 0x66, 0x72, 0x01, 0x02
// 0x49, 0x66, 0x72, 0x01, 0x02, (checksum = 0x23) , 0x0D
// bit rotate as
// 0x49 -> 0x92
// 0x92 + 0x66 = 0xF8 -> 0xF1
// 0xF1 + 0x72 = 0x163 -> 0xC6
// 0xC6 + 0x01 = 0xC7 -> 0x87
// 0x87 + 0x02 = 0x91 -> 0x23 (checksum)
auto checksum(const uint8_t *buf, const uint8_t buf_size) {
   
   
    uint8_t       sum= 0;
    int     val_rot = 0;
    for (auto i = 0; i < buf_size; ++i) 
    {
        //printf("\n --> at i: %d , buffer : %x \n", i,
        //       static_cast<uint8_t>(buf[i]));

        val_rot = sum + static_cast<uint8_t>(buf[i]);
       // printf("\n SUM: %x, new_sum: %x \n", sum, val_rot);
        sum = rotate_accumulator(val_rot);
  
        //printf("\n --> val rotate: %x \n", sum);
    }

     //printf("\n --> FINAL Checksum: %x \n", sum);
       
   
    return sum;
}



int main() {
    uint8_t cs = 0;
    //int test_value = 0x190;
    //uint8_t acc = rotate_accumulator(test_value);
    uint8_t msg[] = {0x49, 0x66, 0x72, 0x01, 0x02};
    cs = checksum(msg, 5);

    printf("\n Rotate result : 0x%x \n", cs);

    // Get manual gain control
    uint8_t msg_get_gain[] = {0x49, 0x66, 0x77, 0x02, 0x00, 0x00};
    cs = checksum(msg_get_gain, 5);

    printf("\n Get Gain Control checksum : 0x%x \n", cs);
    
    // Get frame rate
    uint8_t msg_get_frame[] = {0x49, 0x66, 0x6C, 0x02, 0x00, 0x00};
    cs = checksum(msg_get_frame, 5);
    printf("\n Get Frame Rate checksum : 0x%x \n", cs);
   
	return 0;
}