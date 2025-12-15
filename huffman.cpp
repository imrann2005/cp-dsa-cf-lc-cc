#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_map>

class HuffmanCoder {
private:
    class Node {
    public:
        char data;
        int cost;
        Node* left;
        Node* right;

        Node(char data, int cost) {
            this->data = data;
            this->cost = cost;
            this->left = nullptr;
            this->right = nullptr;
        }
    };

    struct compareNodes {
        bool operator()(Node* a, Node* b) {
            return a->cost > b->cost;
        }
    };

    std::unordered_map<char, std::string> encoder;
    std::unordered_map<std::string, char> decoder;

    void initEncoderDecoder(Node* node, std::string osf) {
        if (node == nullptr) {
            return;
        }

        if (node->left == nullptr && node->right == nullptr) {
            this->encoder[node->data] = osf;
            this->decoder[osf] = node->data;
            return;
        }

        initEncoderDecoder(node->left, osf + "0");
        initEncoderDecoder(node->right, osf + "1");
    }

public:
    HuffmanCoder(const std::string& feeder) {
        std::unordered_map<char, int> fmap;
        for (char cc : feeder) {
            fmap[cc]++;
        }

        std::priority_queue<Node*, std::vector<Node*>, compareNodes> minHeap;
        for (const auto& entry : fmap) {
            Node* node = new Node(entry.first, entry.second);
            minHeap.push(node);
        }

        while (minHeap.size() > 1) {
            Node* first = minHeap.top();
            minHeap.pop();
            Node* second = minHeap.top();
            minHeap.pop();

            Node* newNode = new Node('\0', first->cost + second->cost);
            newNode->left = first;
            newNode->right = second;
            minHeap.push(newNode);
        }

        Node* ft = minHeap.top();
        this->initEncoderDecoder(ft, "");
        
        // Memory cleanup for the Huffman tree
        std::vector<Node*> nodes_to_delete;
        std::queue<Node*> q;
        q.push(ft);
        while(!q.empty()){
            Node* current = q.front();
            q.pop();
            nodes_to_delete.push_back(current);
            if(current->left) q.push(current->left);
            if(current->right) q.push(current->right);
        }
        for(Node* n : nodes_to_delete){
            delete n;
        }
    }

    std::string encode(const std::string& source) {
        std::string sb;
        for (char c : source) {
            sb += encoder.at(c);
        }
        return sb;
    }

    std::string decode(const std::string& code) {
        std::string key = "";
        std::string ans = "";
        for (char c : code) {
            key += c;
            if (decoder.count(key)) {
                ans += decoder.at(key);
                key = "";
            }
        }
        return ans;
    }
};

int main() {
    std::string str = "abbccda";
    HuffmanCoder hc(str);
    std::string cs = hc.encode(str);
    std::cout << cs << std::endl;
    std::string ds = hc.decode(cs);
    std::cout << ds << std::endl;
    return 0;
}