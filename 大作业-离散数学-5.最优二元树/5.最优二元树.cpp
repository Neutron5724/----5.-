#include<iostream>
#include<vector>
#include<limits>
#include<queue>
#include<algorithm>
#define sortit std::sort(nodelist.begin(), nodelist.end(), nodecompare)
struct Node {
	int value;
	Node* lchild = nullptr;
	Node* rchild = nullptr;
};
bool nodecompare(Node* node1, Node* node2) {
	return node1->value < node2->value;//�������нڵ�
}
class HaffmanTree {
private:
	Node* root = nullptr;
	std::vector<int> result;

public:
	
	void BuildTree(std::vector<int> list) {
		std::vector<Node*> nodelist;//����û�и��ڵ�Ľڵ�
		Node* tmpnode;
		for (auto i : list) {
			tmpnode = new Node;
			tmpnode->value = i;
			nodelist.push_back(tmpnode);
		}
		sortit;
		while (nodelist.size() != 1) {
			tmpnode = new Node;
			tmpnode->value = nodelist[nodelist.size() - 1]->value + nodelist[nodelist.size() - 2]->value;
			tmpnode->lchild = nodelist[nodelist.size() - 1];
			tmpnode->rchild = nodelist[nodelist.size() - 2];
			nodelist.pop_back();
			nodelist.pop_back();//������������Ԫ��
			nodelist.push_back(tmpnode);
			sortit;	
		}
		root = nodelist[0];
	}
	void PrintResult(std::vector<int> list,Node*start=nullptr) {
		if (start == nullptr) {
			start = root;
		}
		if (start->lchild == nullptr) {
			std::cout << -start->value << ':'<<0;
			for (int i : result)
				std::cout << i;
			//result.pop_back();
			std::cout << std::endl;
			return;
		}
		else {
			result.push_back(0);
			PrintResult(list, start->lchild);
			result.pop_back();
			result.push_back(1);
			PrintResult(list, start->rchild);
			result.pop_back();
		}
		return;
	}
};
int main() {
	int sum;//�ź�������
	std::vector<int> valuelist;//���ڴ洢ÿ���źŵ�ʹ��Ƶ��
	int num;
	std::cout << "����ڵ������";
	while (1) {
		std::cin >> sum;
		if (std::cin.fail() || sum < 1) {
			std::cout << "��������" << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		else
			break;
	}
	std::cout << "����ڵ㣺";
	for (int i = 0; i < sum; i++) {
		std::cin >> num;
		while (1) {
			if (std::cin.fail()) {
				std::cout << "��������" << std::endl;
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			}
			else {
				valuelist.push_back(-num);
				break;
			}
		}
	}
	std::sort(valuelist.begin(), valuelist.end());
	HaffmanTree mytree;
	mytree.BuildTree(valuelist);
	mytree.PrintResult(valuelist);
	return 0;
}
