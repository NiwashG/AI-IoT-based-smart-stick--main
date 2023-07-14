def count_dropped_packets(requests, max_packets, rate):
    total_dropped_packets = 0
    queue = []  # To store the packets in the pipeline
    
    for time, num_packets in requests:
        # Remove packets from the queue that have been delivered
        if len(queue) > 0:
            delivered_packets = min(len(queue), rate)
            queue = queue[delivered_packets:]
        
        # Calculate the remaining capacity in the pipeline
        remaining_capacity = max_packets - len(queue)
        
        # Drop packets if the pipeline is full
        if remaining_capacity < num_packets:
            dropped_packets = num_packets - remaining_capacity
            total_dropped_packets += dropped_packets
            num_packets = remaining_capacity
        
        # Add the packets to the queue
        queue.extend([time] * num_packets)
    
    # Remove any remaining packets from the queue after the last request
    if len(queue) > 0:
        delivered_packets = min(len(queue), rate)
        queue = queue[delivered_packets:]
    
    return total_dropped_packets

# Example usage
requests = [[1, 8], [4, 9], [6, 7]]
rate = 2
max_packets = 10
dropped_packets = count_dropped_packets(requests, max_packets, rate)
print("Total dropped packets:", dropped_packets)