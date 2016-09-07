class LNode:
    def __init__(self,data,nxt):
        self.data = data
        self.next = nxt
list1 = LNode(1,None)
pnode = list1   # 头节点
for i in range(20):  # 长度限制
    pnode.next = LNode(i,None)
    pnode = pnode.next
while list1 is not None:
    print(list1.data)
    list1 = list1.next
