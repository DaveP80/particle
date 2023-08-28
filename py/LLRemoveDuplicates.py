# Write a RemoveDuplicates() function which takes a list sorted in increasing order and deletes any duplicate 
# nodes from the list. Ideally, the list should only be traversed once. The head of the resulting list should 
# be returned.

# var list = 1 -> 2 -> 3 -> 3 -> 4 -> 4 -> 5 -> null
# removeDuplicates(list) === 1 -> 2 -> 3 -> 4 -> 5 -> null
class Node(object):
    def __init__(self, data):
        self.data = data
        self.next = None

def remove_duplicates(head):
    if not head:
        return None
    
    unique_values = set()
    nhead = Node(head.data)
    current = nhead
    unique_values.add(head.data)
    
    curr = head.next
    while curr:
        if curr.data not in unique_values:
            unique_values.add(curr.data)
            current.next = Node(curr.data)
            current = current.next
        curr = curr.next
    
    return nhead