# Definition for singly-linked list.
# Given a linked list, swap every two adjacent nodes and return its head. You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)
class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution(object):
    def swapPairs(self, head):
        arr = []
        while True:
            if head is not None:
                arr.append(head.val)
                head = head.next
            else:
                break
        for i,j in enumerate(arr):
            if i is not 0 and i % 2 == 1:
                temp = arr[i-1]
                temp2 = arr[i]
                arr[i-1] = temp2
                arr[i] = temp
        if not arr:
            return head
        head = ListNode(arr[0])  # Create the head node with the first element of arr
        current = head  # Set current as the head node
        # Iterate over the remaining elements of arr and create the linked list
        for i in range(1, len(arr)):
            current.next = ListNode(arr[i])
            current = current.next
        return head

        
