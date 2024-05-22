// #include "Index.h"

// // Index Member Functions
// Index::Index(size_t cap)
// {
//     capacity = cap;
//     table = new listitem *[cap]();
// }
// Index::~Index()
// {
//     for (int i = 0; i < capacity; i++)
//     {
//         listitem *x = table[i];
//         while (x != nullptr)
//         {
//             listitem *next = x->next;
//             delete x;
//             x = next;
//         }
//     }
//     delete table;
// }
// size_t Index::hash(const std::string &k) const
// {
//     std::hash<std::string> hashfunction;
//     return hashfunction(k) % capacity;
// }

// void Index::add(const std::string &k, Node *n)
// {
//     size_t x = hash(k);
//     listitem* item = new listitem(k, n, table[x]);
//     table[x] = item;
// }
// void Index::rem(const std::string &k)
// {
//     size_t x = hash(k);
//     listitem* curr = table[x];
//     listitem* prev = nullptr;


//     while (curr != nullptr) {
//         if (curr->node->key == k) {
//             if (prev) {
//                 prev->next = curr->next;
//             } else {

//                 table[x] = curr->next;
//             }
//             delete curr;
//             return;
//         }

//         prev = curr;
//         curr = curr->next;
//     }
// }

// Node *Index::find(const std::string &k)
// {
//     size_t x = hash(k);
//     listitem* curr = table[x];

//     while (curr != nullptr) {
//         if (curr->node->key == k) {
//             return curr->node;
//         }
//         curr = curr->next;
//     }
//     return nullptr;
// }