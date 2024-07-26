#ifndef HUFFMAN_H
#define HUFFMAN_H

#include <string>
#include <queue>
#include <vector>
#include <fstream>

using namespace std;

struct huffman_node {
    char id;                    // Character 
    int freq;                   // Frequency of the character
    string code;                // Huffman code for the character
    huffman_node* left;
    huffman_node* right;

    huffman_node() {
        left = right = nullptr;
    }
};

typedef huffman_node* node_ptr;

class huffman {
private:
    node_ptr node_array[128];   // Array for 128 characters in the Ascii Table
    fstream in_file, out_file;
    node_ptr child, parent, root;
    char id;
    string in_file_name, out_file_name;

    class compare {
    public:
        bool operator()(const node_ptr& c1, const node_ptr& c2) const {
            return c1->freq > c2->freq;
        }
    };

    priority_queue<node_ptr, vector<node_ptr>, compare> pq;

    void create_node_array();
    void traverse(node_ptr, string);
    int binary_to_decimal(string&);
    string decimal_to_binary(int);
    void build_tree(string&, char);

public:
    huffman(string in, string out);
    void create_pq();
    void create_huffman_tree();
    void calculate_huffman_codes();
    void coding_save();
    void decoding_save();
    void recreate_huffman_tree();
};

#endif
