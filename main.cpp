#include <iostream>
#include "huffman.h"

using namespace std;

int main(int argc, char *argv[]) {
    if (argc != 4) {
        cout << "Usage for encoding:\n\t" << argv[0] << " encode inputfile outputfile" << endl;
        cout << "Usage for decoding:\n\t" << argv[0] << " decode inputfile outputfile" << endl;
        return 1;
    }

    string mode = argv[1];
    string input_file = argv[2];
    string output_file = argv[3];

    huffman h(input_file, output_file);

    if (mode == "encode") {
        h.create_pq();
        h.create_huffman_tree();
        h.calculate_huffman_codes();
        h.coding_save();
        cout << "File encoded successfully." << endl;
    } else if (mode == "decode") {
        h.recreate_huffman_tree();
        h.decoding_save();
        cout << "File decoded successfully." << endl;
    } else {
        cout << "Invalid mode. Use 'encode' or 'decode'." << endl;
        return 1;
    }

    return 0;
}
