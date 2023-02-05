#include <iostream>

struct Node
{
  int data;
  Node *next;
};

class LinkedList
{
public:
  Node *head;
  LinkedList()
  {
    head = NULL;
  }
  // Insert a node at the end of the linked list and return the Node
  Node insert(int x)
  {
    // B1: Tạo con trỏ Node trỏ đến vùng nhớ mới
    Node *newNode = new Node;
    newNode->data = x;
    newNode->next = NULL;
    // B2: Nếu head = NULL thì head = newNode
    if (head == NULL)
    {
      head = newNode;
    }
    // B3: Nếu head != NULL thì duyệt đến cuối danh sách
    else
    {
      Node *temp = head;
      while (temp->next != NULL)
      {
        temp = temp->next;
      }
      temp->next = newNode;
    }
    return *newNode;
  }
  // Insert a node at 'pos' position in the linked list and return the Node
  Node insert(int x, int pos)
  {
    // B1: Tạo con trỏ Node trỏ đến vùng nhớ mới
    Node *newNode = new Node;
    newNode->data = x;
    newNode->next = NULL;
    // B2: Nếu pos = 0 thì newNode->next = head và head = newNode
    if (pos == 0)
    {
      newNode->next = head;
      head = newNode;
    }
    else
    {
      // B3: Tạo con trỏ temp trỏ đến head
      Node *temp = head;
      // B4: Duyệt đến vị trí pos - 1
      for (int i = 0; i < pos - 1; i++)
      {
        temp = temp->next;
      }
      // B5: newNode->next = temp->next và temp->next = newNode
      newNode->next = temp->next;
      temp->next = newNode;
    }
    return *newNode;
  }
  // Locate the position of the first occurrence of 'x' in the linked list
  int locate(int x)
  {
    // Nếu danh sách rỗng trả về -1
    if (head == NULL)
    {
      return -1;
    }
    // Duyêt danh sách
    else
    {
      Node *temp = head;
      int pos = 0;
      while (temp != NULL)
      {
        if (temp->data == x)
        {
          return pos;
        }
        temp = temp->next;
        pos++;
      }
    }
    // Nếu không tìm thấy trả về -1
    return -1;
  }
  // Retrieve the data stored at 'pos' position in the linked list
  Node retrieve(int pos)
  {
    // nếu pos < size() thì trả về Node tại pos
    if (pos < this->size())
    {
      Node *temp = head;
      for (int i = 0; i < pos; i++)
      {
        temp = temp->next;
      }
      return *temp;
    }
    else
    {
      return *head;
    }
  }
  // Delete the node at 'pos' position in the linked list
  int deleteNode(int pos)
  {
    // Nếu pos < size() thì xóa Node tại pos
    if (pos < this->size())
    {
      int val_temp = this->retrieve(pos).data;
      // Nếu pos = 0 thì head = head->next
      if (pos == 0)
      {
        head = head->next;
      }
      if (pos == 1)
      {
        head->next = head->next->next;
      }
      // Nếu pos > 1 thì temp->next = temp->next->next
      Node *temp = head;
      for (int i = 0; i < pos - 1; i++)
      {
        temp = temp->next;
      };
      temp->next = temp->next->next;
      return val_temp;
    }
    else
    {
      return -111111;
    }
  }
  // Return the next node after 'pos' position in the linked list
  Node next(int pos)
  {
    int pos_next = pos + 1;
    return this->retrieve(pos_next);
  }
  // Return the previous node before 'pos' position in the linked list
  Node previous(int pos)
  {
    int pos_prev = pos - 1;
    return this->retrieve(pos_prev);
  }
  // Return the number of nodes in the linked list
  int size()
  {
    int len = 0;
    Node *temp = head;
    while (temp != NULL)
    {
      len++;
      temp = temp->next;
    }
    return len;
  }
  // Return the head of the linked list
  Node getHead()
  {
    return *head;
  }
  // Return the tail of the linked list
  Node getTail()
  {
    Node *temp = head;
    while (temp->next != NULL)
    {
      temp = temp->next;
    }
    return *temp;
  }
  // Print the linked list
  void printList()
  {
    Node *temp = head;
    while (temp != NULL)
    {
      std::cout << temp->data << " ";
      temp = temp->next;
    }
    std::cout << std::endl;
  }
};

void TestForLinkedList()
{
  LinkedList list;
  for (int i = 0; i < 10; i++)
  {
    list.insert(i);
  }
  list.printList();
  std::cout << "size: " << list.size() << std::endl;
  std::cout << "locate 5: " << list.locate(5) << std::endl;
  std::cout << "retrieve 5: " << list.retrieve(5).data << std::endl;
  std::cout << "delete 5: " << list.deleteNode(5) << std::endl;
  list.printList();
  std::cout << "size: " << list.size() << std::endl;
  std::cout << "next 5: " << list.next(5).data << std::endl;
  std::cout << "previous 5: " << list.previous(5).data << std::endl;
  std::cout << "head: " << list.getHead().data << std::endl;
  std::cout << "tail: " << list.getTail().data << std::endl;
}

int main()
{
  // test all method of linked list
  TestForLinkedList();
  return 0;
}