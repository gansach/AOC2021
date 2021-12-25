packet_version_sum = 0

hex2bin = {
    "0": "0000",
    "1": "0001",
    "2": "0010",
    "3": "0011",
    "4": "0100",
    "5": "0101",
    "6": "0110",
    "7": "0111",
    "8": "1000",
    "9": "1001",
    "A": "1010",
    "B": "1011",
    "C": "1100",
    "D": "1101",
    "E": "1110",
    "F": "1111"
}

def decode_header(packet):
    return int(packet[:3], 2), int(packet[3:6], 2)

def decode_literal(packet):
    literal = ""
    packet_cursor = 6

    for i in range(6, len(packet), 5):
        literal += packet[i + 1: i + 5]

        if packet[i] == "0":
            packet_cursor = i + 5
            break

    return int(literal, 2), packet_cursor

def decode_operator(packet):
    length_type_ID = int(packet[6], 2)

    sub_packets = []
    packet_cursor = 7

    if (length_type_ID == 0):

        sub_packets_bits_length = int(packet[packet_cursor : packet_cursor + 15], 2)
        packet_cursor = 22
        
        while packet_cursor < sub_packets_bits_length + 22:
            sub_packet, decoded_bits = decode_packet(packet[packet_cursor : ])
            packet_cursor += decoded_bits
            sub_packets.append(sub_packet)

    else:
        num_sub_packets = int(packet[packet_cursor: packet_cursor + 11], 2)
        packet_cursor = 18
        
        for _ in range(num_sub_packets):
            sub_packet, decoded_bits = decode_packet(packet[packet_cursor : ])
            packet_cursor += decoded_bits
            sub_packets.append(sub_packet)

    return sub_packets, packet_cursor

def decode_packet(packet):  
    global packet_version_sum

    packet_version, packet_type_id = decode_header(packet)

    packet_version_sum += packet_version

    if packet_type_id == 4:
        return decode_literal(packet)
    
    else:
        sub_packets, packet_cursor = decode_operator(packet)
    
    packet_value = 1

    if packet_type_id == 0:
        packet_value = sum(sub_packets)

    elif packet_type_id == 1:
        for x in sub_packets:
            packet_value *= x

    elif packet_type_id == 2:
        packet_value = min(sub_packets)

    elif packet_type_id == 3:
        packet_value = max(sub_packets)

    elif packet_type_id == 5:
        x, y = sub_packets
        packet_value = 1 if x > y else 0

    elif packet_type_id == 6:
        x, y = sub_packets
        packet_value = 1 if x < y else 0

    elif packet_type_id == 7:
        x, y = sub_packets
        packet_value = 1 if x == y else 0
            
    return packet_value, packet_cursor

with open("input.txt", "r") as f:
    packet = "".join(map(lambda x: hex2bin[x], list(f.readline().strip())))
    packet_value, packet_cursor = decode_packet(packet)
    print(packet_value, packet_version_sum)
