#pragma once
template <class infoT> 
class clList
{
    struct Node
    {
        infoT info;
        Node* next;
    };
    Node* head;
public:
    clList();
    ~clList();
};